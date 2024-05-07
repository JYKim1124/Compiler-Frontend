%{
/*
 * scanner.l - lexical analyzer for the MiniC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
#include "glob.h"

extern reporterror(ERRORtypes err);
int SymbolTable();
extern ComputeHS(int nid, int nfree);
extern LookupHS(int nid, int nfree);
extern SymbolTable();
extern ADDHT(int hscode);
extern PrintHStable();
extern yyerror(char *s);
extern yylex();

%}

%%
"const"				return(TCONST);
[cC][oO][nN][sS][tT]		{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }
"else" 				return(TELSE);
[eE][lL][sS][eE]			{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }
"if" 				return(TIF);
[iI][fF]				{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }
"int"				return(TINT);
[iI][nN][tT]			{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }
"return"				return(TRETURN);
[rR][eE][tT][uU][rR][nN]		{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }
"void" 				return(TVOID);
[vV][oO][iI][dD]			{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }
"while" 				return(TWHILE);
[wW][hH][iI][lL][eE]		{     yyerror("scanner error : illegal identifier"); return (TILLIDENT); }

"+" 				return(TPLUS);
"-" 				return(TMINUS);
"*" 				return(TSTAR);
"/" 				return(TSLASH);
"%" 				return(TMOD);

"=" 				return(TASSIGN);
"+=" 				return(TADDASSIGN);
"-=" 				return(TSUBASSIGN);
"*=" 				return(TMULASSIGN);
"/=" 				return(TDIVASSIGN);
"%=" 				return(TMODASSIGN);

"!" 				return(TNOT);
"&&" 				return(TAND);
"||" 				return(TOR);

"==" 				return(TEQUAL);
"!="	 			return(TNOTEQU);
"<" 				return(TLESS);
">" 				return(TGREAT);
"<=" 				return(TLESSE);
">=" 				return(TGREATE);

"++" 				return(TINC);
"--" 				return(TDEC);

"(" 				return(TLPAREN);
")" 				return(TRPAREN);
"," 				return(TCOMMA);
"{"				return(TLBRACE);
"}"				return(TRBRACE);
"["				return(TLBRACKET);
"]"				return(TRBRACKET);
";" 				return(TSEMI);

[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);

[A-Za-z_][A-Za-z0-9_]* 		{ 
					if(yyleng > MAX_LEN)
						{     yyerror("scanner error : too long identifier"); return (TLONG); }
						{ SymbolTable(); return(TIDENT);}
				}



"//".*				;
"/*"([^*]|\*+[^*/])*\**"*/"		{
					for(int i=0;i<yyleng;i++)
						if(yytext[i]=='\n') cLine++;

				}

[ \t]			 	;
"\n" 				{ cLine++; }

[0-9]+[A-Za-z0-9_]+ 		{     yyerror("scanner error : start with digit"); return (TILLIDENT); }

. 				{     yyerror("scanner error : illegal symbol"); return (TILLIDENT); }
%%

int yywrap()
{
	return 1;
}