// ���ÿ��� ũ�� 1000���� ����, overflow ���� Ȯ���� ���� test�ÿ��� 7���� ����
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
* index: ST ������ ���
* type: case �����ϱ� ���� ����
* cLine: �ڵ� �� �� ��� ����
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
* nextid: ���� identifier�� ���� index
* nextfree: ST���� ���� character�� ���Ե� ���� index
*/
int nextid;
int nextfree;
int hashcode;
int sameid;
int yyleng;
char* yytext;

/* errorTypes
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
* 18)noerror : ���� ����
* 19)no_expression : if statement�� ���ǹ��� ���Ե��� ����
*/
enum errorTypes { no_expression, wrong_funcdef, wrong_stat, wrong_init, noparen, nocomma, emptycomma, nobrace, nobracket, nosemi, invalid_n, invalid_p, noerror, illid_digit, illid_long, illid_illch, illid_illegal, overst }; typedef enum errorTypes ERRORtypes;
ERRORtypes err;

/*
* num_err: ���� ����
* cLine: �ڵ� �� ��
* found: symtable.c ���� ����ϴ� �˻��� flag
*/
int num_err;
int cLine;
int found;