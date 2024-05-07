#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
#include <malloc.h>

extern int yyparse();
extern void PrintHStable();

void main() {
	look_id = (HTpointer)malloc(sizeof(struct HTentry));
	look_tmp = (HTpointer)malloc(sizeof(struct HTentry));

	printf("\n\n*** MiniC parsing begins\n\n");

	/* cLine, nextid, nextfree �ʱ�ȭ */
	cLine = 1;
	nextid = 0;
	nextfree = 0;

	/* �Ľ� �� ���� Ÿ�� ��� */
	yyparse();

	printf("Parsing ends.***\n\n");


	if (num_err == 0) {
		printf("no errors detected\n\n");


	}

	else printf("%d error(s) detected\n\n", num_err);

	printf("=======================================================================\n\n");

	/* HS���̺� ���*/
	PrintHStable();
}