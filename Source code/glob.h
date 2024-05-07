// 평상시에는 크기 1000으로 설정, overflow 오류 확인을 위한 test시에는 7으로 설정
#define STsize 1000
// #define STsize 7
#define HTsize 100
#define FALSE 0
#define TRUE 1
#define MAX_LEN 11

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z' || (x) == '_') )
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

typedef struct HTentry* HTpointer;

/*
* index: ST 읽을때 사용
* type: case 구분하기 위한 변수
* cLine: 코드 줄 수 담는 변수
*/
typedef struct HTentry {
	int index;
	int type;
	int cLine;
	HTpointer next;
}HTentry;


HTpointer HT[HTsize];
HTpointer look_id;
HTpointer look_tmp;


char ST[STsize];

/*
* nextid: 현재 identifier의 시작 index
* nextfree: ST에서 다음 character가 삽입될 곳의 index
*/
int nextid;
int nextfree;
int hashcode;
int sameid;
int yyleng;
char* yytext;

/* errorTypes
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
* 18)noerror : 에러 없음
* 19)no_expression : if statement에 조건문이 포함되지 않음
*/
enum errorTypes { no_expression, wrong_funcdef, wrong_stat, wrong_init, noparen, nocomma, emptycomma, nobrace, nobracket, nosemi, invalid_n, invalid_p, noerror, illid_digit, illid_long, illid_illch, illid_illegal, overst }; typedef enum errorTypes ERRORtypes;
ERRORtypes err;

/*
* num_err: 에러 개수
* cLine: 코드 줄 수
* found: symtable.c 에서 사용하는 검색용 flag
*/
int num_err;
int cLine;
int found;