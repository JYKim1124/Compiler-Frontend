#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "glob.h"
#include "tn.h"



/* PrintHStable -
* hash table�� ���Ŀ� ���߾� ���
*/
void PrintHStable()
{
	HTpointer here;
	int i, j;

	printf("[[  HASH TABLE  ]]\n");

	for (i = 0; i < HTsize; i++) {
		if (HT[i] != NULL) {
			here = HT[i];
			do {
				printf(" Hash Code%4d : (", i);
				for (j = here->index; ST[j] != '\0'; j++) printf("%c", ST[j]);
				printf(" : ");

				switch (here->type) {
					//int variable
				case 1: printf("integer scalar variable, line%d)\n", here->cLine); break;
					//void variable
				case 2: printf("void scalar variable, line%d)\n", here->cLine); break;
					//array(int) variable
				case 3: printf("array integer variable, line%d)\n", here->cLine); break;
					//void function
				case 4: printf("function, return type=void, line%d)\n", here->cLine); break;
					//not define
				case 5: printf("not defined identifier/function, line%d)\n", here->cLine); break;
					//int function
				case 6: printf("function, return type=int, line%d)\n", here->cLine); break;
					//int scalar parameter
				case 7: printf("integer scalar parameter, line%d)\n", here->cLine); break;

				default: printf("identifier about parse error, line%d)\n", here->cLine); break;
				}
				here = here->next;
			} while (here != NULL);
		}



	}

}


/*ComputeHS
* identifier�� hashcode ��� : ��� characters�� �ƽ�Ű ���� ���� ��, HT������� ���� ������
*/
void ComputeHS(int nid, int nfree)
{
	int code, i;
	code = 0;
	for (i = nid; i < nfree - 1; i++) {
		int current = (int)ST[i];
		//If current is lowercase, convert it to uppercase
		current = (current >= 'A' && current <= 'Z' ? current - 'A' + 'a' : current);
		code += current;
	}
	hashcode = (code % HTsize) + 1;
	hashcode = (hashcode == HTsize ? 0 : hashcode);
}


/*
* LookupHS
* �� identifer�� ����, hastable�� �̹� �ִ��� Ȯ��
* �̹� �ִٸ� found�� true�� �ʱ�ȭ / ���ٸ� false�� �ʱ�ȭ
*/
void LookupHS(int nid, int hscode)
{
	HTpointer here;
	int i, j;
	found = FALSE;

	//������� ������
	if (HT[hscode] != NULL) {
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;
			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j]) found = FALSE;
				else {
					i++;
					j++;
				}
			}
			here = here->next;

		}
	}
}


/*
* ADDHT
* ���ο� identifier�� hash table�� �ִ´�.
* index�� next�� �������ְ�, type�� 0���� �ʱ�ȭ�ϸ�, ���° �ٿ� �����ϴ����� cLine�� �����Ѵ�.
* ht[hashcode]����Ʈ�� ����ִٸ�, next�� NULL�� ä���,
* ����Ʈ�� ������������� next�� HT���̺��� �̿��Ͽ� ä���.
*/
void ADDHT(int hscode)
{
	HTpointer ptr;
	ptr = (HTpointer)malloc(sizeof(struct HTentry));

	if (HT[hscode] == NULL) {
		ptr->type = 0;
		ptr->next = NULL;
		ptr->cLine = cLine;
		HT[hscode] = ptr;
		ptr->index = nextid;
	}
	else {
		ptr->type = 0;
		ptr->index = nextid;
		ptr->next = HT[hscode];
		ptr->cLine = cLine;
		HT[hscode] = ptr;
	}
	look_id = ptr;

}


/*
SymbolTable
*   identifier�� �νĵ� token�� �� ���ھ� ST�� ����. (yytext, yyleng�̿�)
*   �ش� identifier�� hashcode���� ���.
*   HT[hashcode]�� identifier�� �̹� �ִ��� Ȯ��
*   �̹� ������, ���� ���� identifier�� ST���� ����
*   ���� ������, HT[hashcode]�� index�� identifier�� ST������ ù �ε��� ���� ����
*   identifier�� ���� line number, Token-type(Identifier), token ������ ���
*/
int SymbolTable()
{
	nextid = nextfree;

	// ST overflow �߻� ��
	if ((nextfree == STsize) || ((nextfree + yyleng) > STsize)) {
		reporterror(overst);
		PrintHStable();
		exit(0);
	}

	// yytext �ѱ��ھ� ST�� ����
	for (int i = 0; i < yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	// identifier�� �� ���� ��
	ST[nextfree++] = '\0';

	// HS���, �� identifer�� ����, hastable�� �̹� �ִ��� Ȯ��
	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);


	if (!found) { // ���� ���� identifier�� ST�� ���� �� ���� ��
		ADDHT(hashcode); // HT ����
	}
	else { // �̹� ���� identifier�� ���� ��
		nextfree = nextid; //�̹��� ST�� ���� identifier�� ������ ���
	}

	return 1;

}