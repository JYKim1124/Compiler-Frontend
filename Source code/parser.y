%{
/* 이주미 김가영 박소영 김주연*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

int type_const=0;
int type_int=0;
int type_void=0;
int param_int=0;


extern reporterror();
extern yylex();
extern yyerror(char *s);

%}

%token TEOF TLBRACE TRBRACE TLBRACKET TRBRACKET TCONST TELSE TIF TINT TRETURN TVOID TMODASSIGN TEIF
%token TWHILE TPLUS TMINUS TSTAR TSLASH TMOD TEQUAL TNOTEQU TLESS TGREAT TLESSE TGREATE TIDENT
%token TNOT TAND TOR TINC TDEC TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN TNUMBER
%token TCOMMENT TSTRING TERROR TCOMMA TCARR TSEMI TRPAREN TASSIGN TLPAREN TILLIDENT TLONG
%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE
%%
mini_c          : translation_unit;
translation_unit    : external_dcl
         | translation_unit external_dcl;
external_dcl       : function_def
           | declaration
            | TIDENT TSEMI
            | TIDENT error{
               yyerrok;
               reporterror(wrong_stat);
            }| TRBRACE /* 왼쪽 중괄호 없음 */
           {
                    yyerrok;
                    reporterror(nobrace);
              }
              | TNUMBER error{
         yyerrok; reporterror(invalid_n);
         }
         |TRPAREN error {yyerrok; reporterror(noparen)}
         |TLBRACE error {yyerrok; reporterror(nobrace)};
function_def       : function_header compound_st
            |function_header TSEMI
                     |function_header error{
                      
                       yyerrok;
                       reporterror(wrong_funcdef);    
                     };
function_header    : dcl_spec function_name formal_param;
dcl_spec       : dcl_specifiers;
dcl_specifiers       : dcl_specifier
          | dcl_specifiers dcl_specifier;
dcl_specifier       : type_qualifier
         | type_specifier;
type_qualifier       : TCONST   {type_const=1;};
type_specifier       : TINT   {type_int=1;}
          | TVOID      {type_void=1;};
function_name    : TIDENT{
                  /* type이 identifier about parse error또는 
                  not defined identifier/function로 설정된 경우 */

                  if(look_id->type==0||look_id->type==5){
                        
                        /* void인지 int인지에 따라 function type 설정*/
                        if(type_void==1){
                              look_id->type=4; /* function, return type=void */
                        }else if(type_int==1){
                              look_id->type=6; /* function, return type=int */
                        }
                    
                        type_int=0;
                        type_void=0;
                        look_tmp=look_id;
                  }
                  }
         | TLONG
         | TILLIDENT
         | TNUMBER error{
         yyerrok; reporterror(invalid_n);
         }
         ;
formal_param       : TLPAREN opt_formal_param TRPAREN
            | TLPAREN opt_formal_param error{
            yyerrok;
            reporterror(noparen);
            };
opt_formal_param    : formal_param_list
            |;
formal_param_list    : param_dcl      
             | formal_param_list TCOMMA param_dcl
         | formal_param_list dcl_spec declarator{
         reporterror(nocomma);
         }
         | formal_param_list TCOMMA error {
         yyerrok;
         reporterror(emptycomma);
         }
         ;
param_dcl       : dcl_spec declarator{
                  if(type_int==1){ /* int로 설정된 경우 */
                        param_int=1; 
                        look_id->type=7;  /* integer scalar parameter */
                  }
                  type_int=0;
                  type_void=0;
                  param_int=0;
}|declarator error{yyerrok; reporterror(invalid_p);/*param에서 자료형 선언하지 않고 identifier 들어온 경우*/};
compound_st       : TLBRACE opt_dcl_list opt_stat_list TRBRACE
            | TLBRACE opt_dcl_list opt_stat_list error
            {
               yyerrok;
               reporterror(nobrace); /* no brace error */
            }
            ;
opt_dcl_list       : declaration_list   
         |;
declaration_list    : declaration
         | declaration_list declaration;
declaration       : dcl_spec init_dcl_list TSEMI{
               type_int=0;
                           type_void=0;
            }
            | dcl_spec init_dcl_list error{
               look_tmp->type=0; /* identifier about parse error */
               yyerrok;
               type_int=0;
                           type_void=0;
                           reporterror(nosemi); /* no semicolon error */
            };
init_dcl_list       : init_declarator   
         | init_dcl_list TCOMMA init_declarator 
         | init_dcl_list TCOMMA error{
            yyerrok;
            reporterror(emptycomma);
         };
init_declarator    : declarator
          | declarator TASSIGN TNUMBER;
          | declarator TASSIGN error {
                        yyerrok;
                        reporterror(wrong_init);
                      };
declarator       : TIDENT{
                     if(look_id->type==0){
                           /* scalar : int인지 void인지에 따라*/
                           if(type_int==1){
                                 look_id->type=1; /* integer scalar variable */
                           }
                           else if(type_void==1)
                                 look_id->type=2; /* void scalar variable */
                        }
                     look_tmp=look_id;
            }        
              | TIDENT TLBRACKET opt_number TRBRACKET
            {
                     /* array */
                     if(look_id->type==0){
                           if(type_int==1) 
                        {look_id->type=3;} /* array integer variable */           
                     }
                      look_tmp=look_id;
               }
         | TIDENT TLBRACKET opt_number error{
            yyerrok;
            reporterror(nobracket); /* no bracket error */
         }
               |TILLIDENT
                 |TLONG
                 | TNUMBER error{
         yyerrok; reporterror(invalid_n);
         }
         ;
         
opt_number       : TNUMBER
              |;
opt_stat_list       : statement_list         
          |;
statement_list       : statement               
                             | statement_list declaration 
          | statement_list statement;
statement       : compound_st         
            | expression_st         
            | if_st   
            | while_st   
            | return_st   
            ;
expression_st    : opt_expression TSEMI
                  | expression error
                  {
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                  } 
      ;   
opt_expression    : expression               
          | opt_expression TCOMMA expression
          |;

if_st          : TIF TLPAREN expression TRPAREN  statement  %prec LOWER_THAN_ELSE
         | TIF TLPAREN expression TRPAREN statement TELSE statement
   | TIF TLPAREN expression error
   {
      yyerrok;
      reporterror(noparen); /* error - no parenthesis */
   }
   | TIF TLPAREN TRPAREN /* if문에 조건문이 없는 경우 */
   {
      yyerrok;
      reporterror(no_expression); /* error - no expression */
   }
         ;
while_st       : TWHILE TLPAREN expression TRPAREN statement ;
return_st       : TRETURN opt_expression TSEMI
                | TRETURN opt_expression error{
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                };
expression       : assignment_exp;
assignment_exp    : logical_or_exp         
         | unary_exp TASSIGN assignment_exp       
         | unary_exp TADDASSIGN assignment_exp    
         | unary_exp TSUBASSIGN assignment_exp    
         | unary_exp TMULASSIGN assignment_exp 
         | unary_exp TDIVASSIGN assignment_exp    
         | unary_exp TMODASSIGN assignment_exp    
         ;
logical_or_exp    : logical_and_exp            
         | logical_or_exp TOR logical_and_exp ;
logical_and_exp    : equality_exp               
          | logical_and_exp TAND equality_exp;
equality_exp       : relational_exp         
         | equality_exp TEQUAL relational_exp 
         | equality_exp TNOTEQU relational_exp;
relational_exp    : additive_exp       
         | relational_exp TGREAT additive_exp 
         | relational_exp TLESS additive_exp    
         | relational_exp TGREATE additive_exp 
         | relational_exp TLESSE additive_exp;
additive_exp       : multiplicative_exp            
         | additive_exp TPLUS multiplicative_exp    
         | additive_exp TMINUS multiplicative_exp;
multiplicative_exp    : unary_exp               
             | multiplicative_exp TSTAR unary_exp       
             | multiplicative_exp TSLASH unary_exp    
             | multiplicative_exp TMOD unary_exp;
unary_exp       : postfix_exp            
            | TMINUS unary_exp            
            | TNOT unary_exp         
            | TINC unary_exp            
            | TDEC unary_exp;
postfix_exp       : primary_exp            
               | postfix_exp TLBRACKET expression TRBRACKET
               | postfix_exp TLPAREN opt_actual_param TRPAREN
               | postfix_exp TINC
               | postfix_exp TDEC;
opt_actual_param    : actual_param
           |;
actual_param       : actual_param_list;
actual_param_list    : assignment_exp
            | actual_param_list TCOMMA assignment_exp;
primary_exp       : TIDENT{
                  if(look_id->type==0)
                        look_id->type=5; /* not defined identifier/function */

            }
            |TILLIDENT
              | TNUMBER
              | TLPAREN expression TRPAREN
              | TLPAREN expression error {yyerrok; reporterror(noparen)};
%%