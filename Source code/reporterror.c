#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

extern char* yytext;

extern yylex();


/*
* yyerror() - ����� error �޼��� ���� ��� �Լ�
*/
void yyerror(char* s) {
    if (s != "parse error") { //parser_tab.c���� �߻��� parse������ �ƴѰ��
        printf("\t%-5d %-10s %-50s\n", cLine, yytext, s);//���� �޼��� ���
        num_err++;//������ 1 ���� 
    }
}


/* reporterror
* token type���� ������ ������, ���� ���� 1�� ������Ų ��, �ش� ������ ���
* 0)wrong_funcdef : �ùٸ��� ���� �Լ� ����
* 1)wrong_stat : �ùٸ��� ���� ����
* 2)wrong_init : �ùٸ��� ���� ���� ����
* 3)nosemi : semicolon�� ������� ���� ���
* 4)nobrace : �ùٸ��� ���� ������ �߰��� ���(missing brace)
* 5)nobraket : �ùٸ��� ���� ������ ���ȣ ���
* 6)noparen : �ùٸ��� ���� ������ ��ȣ ���
* 7)nocomma: �ùٸ��� ���� ������ �޸� ��� ( �� : (int a int v) )
* 8)emptycomma: �ùٸ��� ���� ������ �޸� ��� ( �� : int a, ; )
* 9)long : 12�ڸ� �ʰ��ϴ� identifier
* 10)overst : table�� size�� �ʰ��� ���
* 11)illid_digit : ���ڷ� �����ϴ� identifier
* 12)illid_long : 12�� �̻��� identifier
* 13)illid_illch : �ùٸ��� ���� symbol ���
* 14)illid_illegal : �ҹ��ڰ� ���Ե� Ű���� ����
* 15)overst : table�� size�� �ʰ��� ���
* 16)invalid_n : ���� ����� ���ڸ� ���
* 17)invalid_p : �ڷ��� �������� �ʰ� ���� ����
* 18)no_expression : if statement�� ���ǹ��� ���Ե��� ����
* 19)noerror : ���� ����
*/
void reporterror(ERRORtypes err) {
    switch (err) {
    case wrong_funcdef: //wrong_funcdef   
        printf("\t%-5d %-50s\n", cLine, " Wrong function definition");
        num_err++;
        break;

    case wrong_stat: //wrong_stat
        printf("\t%-5d %-50s\n", cLine, " Wrong state definition");
        num_err++;
        break;

    case wrong_init: //wrong_init
        printf("\t%-5d %-50s\n", cLine, " Wrong variable init");
        num_err++;
        break;

    case nosemi: //nosemi
        printf("\t%-5d %-50s\n", cLine, " Missing semicolon");
        num_err++;
        break;

    case nobrace: //nobrace (�߰�ȣ)
        printf("\t%-5d %-50s\n", cLine, " Missing brace");
        num_err++;
        break;

    case nobracket: //nobraket (���ȣ)
        printf("\t%-5d %-50s\n", cLine, " Missing bracket");
        num_err++;
        break;

    case noparen: //noparen (�Ұ�ȣ)
        printf("\t%-5d %-50s\n", cLine, " Missing paren");
        num_err++;
        break;

    case nocomma: //ex. (int a int v)
        printf("\t%-5d %-50s\n", cLine, " Missing comma");
        num_err++;
        break;

    case emptycomma: //ex. int a, ;
        printf("\t%-5d %-50s\n", cLine, " empty comma");
        num_err++;
        break;

    case illid_digit:
        num_err++;
        printf("\t%6d start with digit\n", cLine);
        break;

    case illid_long:
        num_err++;
        printf("\t%6d too long identifier\n", cLine);
        break;

    case illid_illch:
        num_err++;
        printf("\t%6d illegal symbol\n", cLine);
        break;

    case illid_illegal:
        num_err++;
        printf("\t%6d illegal identifier\n", cLine);
        break;

    case overst:
        num_err++;
        printf("\tError : OVERFLOW in ST\n");
        printf("==================================================\n");
        printf("Parsing ends.***\n\n");


        if (num_err == 0) {
            printf("no errors detected\n\n");
        }
        else printf("%d error(s) detected\n\n", num_err);

        break;

    case invalid_n: // ���� ����� ���ڸ� ��� (ex. int 3;)
        num_err++;
        printf("\t%-5d %-50s\n", cLine, "init error : invalid number");
        break;
    case invalid_p: // �ڷ��� �������� �ʰ� ���� ���� (ex. float param; -> ����3������ float�� �ϳ��� �ڷ������� �ٷ��� �ʱ� ����)
        num_err++;
        printf("\t%-5d %-50s\n", cLine, "no spec defined");
        break;

    case no_expression: // if statement�� ���ǹ��� ���Ե��� ���� (ex. if() a = b;)
        num_err++;
        printf("\t%-5d %-50s\n", cLine, "no condition expression");
        break;

    case noerror:
        break;

    }
}
