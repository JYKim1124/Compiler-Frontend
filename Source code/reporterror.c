#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

extern char* yytext;

extern yylex();


/*
* yyerror() - 사용자 error 메세지 직접 출력 함수
*/
void yyerror(char* s) {
    if (s != "parse error") { //parser_tab.c에서 발생한 parse에러가 아닌경우
        printf("\t%-5d %-10s %-50s\n", cLine, yytext, s);//에러 메세지 출력
        num_err++;//에러수 1 증가 
    }
}


/* reporterror
* token type별로 에러를 나누고, 에러 수를 1씩 증가시킨 후, 해당 에러문 출력
* 0)wrong_funcdef : 올바르지 않은 함수 선언
* 1)wrong_stat : 올바르지 않은 선언
* 2)wrong_init : 올바르지 않은 변수 선언
* 3)nosemi : semicolon을 사용하지 않은 경우
* 4)nobrace : 올바르지 않은 형식의 중괄요 사용(missing brace)
* 5)nobraket : 올바르지 않은 형식의 대괄호 사용
* 6)noparen : 올바르지 않은 형식의 괄호 사용
* 7)nocomma: 올바르지 않은 형식의 콤마 사용 ( 예 : (int a int v) )
* 8)emptycomma: 올바르지 않은 형식의 콤마 사용 ( 예 : int a, ; )
* 9)long : 12자를 초과하는 identifier
* 10)overst : table의 size를 초과한 경우
* 11)illid_digit : 숫자로 시작하는 identifier
* 12)illid_long : 12자 이상의 identifier
* 13)illid_illch : 올바르지 않은 symbol 사용
* 14)illid_illegal : 소문자가 포함된 키워드 형태
* 15)overst : table의 size를 초과한 경우
* 16)invalid_n : 변수 선언시 숫자만 사용
* 17)invalid_p : 자료형 선언하지 않고 변수 선언
* 18)no_expression : if statement에 조건문이 포함되지 않음
* 19)noerror : 에러 없음
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

    case nobrace: //nobrace (중괄호)
        printf("\t%-5d %-50s\n", cLine, " Missing brace");
        num_err++;
        break;

    case nobracket: //nobraket (대괄호)
        printf("\t%-5d %-50s\n", cLine, " Missing bracket");
        num_err++;
        break;

    case noparen: //noparen (소괄호)
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

    case invalid_n: // 변수 선언시 숫자만 사용 (ex. int 3;)
        num_err++;
        printf("\t%-5d %-50s\n", cLine, "init error : invalid number");
        break;
    case invalid_p: // 자료형 선언하지 않고 변수 선언 (ex. float param; -> 과제3에서는 float를 하나의 자료형으로 다루지 않기 때문)
        num_err++;
        printf("\t%-5d %-50s\n", cLine, "no spec defined");
        break;

    case no_expression: // if statement에 조건문이 포함되지 않음 (ex. if() a = b;)
        num_err++;
        printf("\t%-5d %-50s\n", cLine, "no condition expression");
        break;

    case noerror:
        break;

    }
}
