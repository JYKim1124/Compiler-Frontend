#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "glob.h"
#include "tn.h"



/* PrintHStable -
* hash table을 형식에 맞추어 출력
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
* identifier의 hashcode 계산 : 모든 characters의 아스키 값을 더한 후, HT사이즈로 나눈 나머지
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
* 각 identifer에 대해, hastable에 이미 있는지 확인
* 이미 있다면 found를 true로 초기화 / 없다면 false로 초기화
*/
void LookupHS(int nid, int hscode)
{
	HTpointer here;
	int i, j;
	found = FALSE;

	//비어있지 않으면
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
* 새로운 identifier를 hash table에 넣는다.
* index와 next를 지정해주고, type은 0으로 초기화하며, 몇번째 줄에 존재하는지를 cLine에 저장한다.
* ht[hashcode]리스트가 비어있다면, next는 NULL로 채우고,
* 리스트가 비어있지않으면 next는 HT테이블을 이용하여 채운다.
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
*   identifier로 인식된 token을 한 글자씩 ST에 넣음. (yytext, yyleng이용)
*   해당 identifier의 hashcode값을 계산.
*   HT[hashcode]에 identifier가 이미 있는지 확인
*   이미 있으면, 현재 읽은 identifier를 ST에서 삭제
*   아직 없으면, HT[hashcode]의 index에 identifier의 ST에서의 첫 인덱스 값을 넣음
*   identifier에 대해 line number, Token-type(Identifier), token 순으로 출력
*/
int SymbolTable()
{
	nextid = nextfree;

	// ST overflow 발생 시
	if ((nextfree == STsize) || ((nextfree + yyleng) > STsize)) {
		reporterror(overst);
		PrintHStable();
		exit(0);
	}

	// yytext 한글자씩 ST에 넣음
	for (int i = 0; i < yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	// identifier를 다 넣은 후
	ST[nextfree++] = '\0';

	// HS계산, 각 identifer에 대해, hastable에 이미 있는지 확인
	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);


	if (!found) { // 아직 같은 identifier를 ST에 넣은 적 없을 때
		ADDHT(hashcode); // HT 삽입
	}
	else { // 이미 같은 identifier가 있을 때
		nextfree = nextid; //이번에 ST에 읽은 identifier를 다음에 덮어씀
	}

	return 1;

}