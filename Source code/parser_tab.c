
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TEOF	258
#define	TLBRACE	259
#define	TRBRACE	260
#define	TLBRACKET	261
#define	TRBRACKET	262
#define	TCONST	263
#define	TELSE	264
#define	TIF	265
#define	TINT	266
#define	TRETURN	267
#define	TVOID	268
#define	TMODASSIGN	269
#define	TEIF	270
#define	TWHILE	271
#define	TPLUS	272
#define	TMINUS	273
#define	TSTAR	274
#define	TSLASH	275
#define	TMOD	276
#define	TEQUAL	277
#define	TNOTEQU	278
#define	TLESS	279
#define	TGREAT	280
#define	TLESSE	281
#define	TGREATE	282
#define	TIDENT	283
#define	TNOT	284
#define	TAND	285
#define	TOR	286
#define	TINC	287
#define	TDEC	288
#define	TADDASSIGN	289
#define	TSUBASSIGN	290
#define	TMULASSIGN	291
#define	TDIVASSIGN	292
#define	TNUMBER	293
#define	TCOMMENT	294
#define	TSTRING	295
#define	TERROR	296
#define	TCOMMA	297
#define	TCARR	298
#define	TSEMI	299
#define	TRPAREN	300
#define	TASSIGN	301
#define	TLPAREN	302
#define	TILLIDENT	303
#define	TLONG	304
#define	LOWER_THAN_ELSE	305

#line 1 "parser.y"

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


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		194
#define	YYFLAG		-32768
#define	YYNTBASE	51

#define YYTRANSLATE(x) ((unsigned)(x) <= 305 ? yytranslate[x] : 96)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    19,    22,
    25,    28,    31,    34,    37,    41,    43,    45,    48,    50,
    52,    54,    56,    58,    60,    62,    64,    67,    71,    75,
    77,    78,    80,    84,    88,    92,    95,    98,   103,   108,
   110,   111,   113,   116,   120,   124,   126,   130,   134,   136,
   140,   144,   146,   151,   156,   158,   160,   163,   165,   166,
   168,   169,   171,   174,   177,   179,   181,   183,   185,   187,
   190,   193,   195,   199,   200,   206,   214,   219,   223,   229,
   233,   237,   239,   241,   245,   249,   253,   257,   261,   265,
   267,   271,   273,   277,   279,   283,   287,   289,   293,   297,
   301,   305,   307,   311,   315,   317,   321,   325,   329,   331,
   334,   337,   340,   343,   345,   350,   355,   358,   361,   363,
   364,   366,   368,   372,   374,   376,   378,   382
};

static const short yyrhs[] = {    52,
     0,    53,     0,    52,    53,     0,    54,     0,    69,     0,
    28,    44,     0,    28,     1,     0,     5,     0,    38,     1,
     0,    45,     1,     0,     4,     1,     0,    55,    66,     0,
    55,    44,     0,    55,     1,     0,    56,    61,    62,     0,
    57,     0,    58,     0,    57,    58,     0,    59,     0,    60,
     0,     8,     0,    11,     0,    13,     0,    28,     0,    49,
     0,    48,     0,    38,     1,     0,    47,    63,    45,     0,
    47,    63,     1,     0,    64,     0,     0,    65,     0,    64,
    42,    65,     0,    64,    56,    72,     0,    64,    42,     1,
     0,    56,    72,     0,    72,     1,     0,     4,    67,    74,
     5,     0,     4,    67,    74,     1,     0,    68,     0,     0,
    69,     0,    68,    69,     0,    56,    70,    44,     0,    56,
    70,     1,     0,    71,     0,    70,    42,    71,     0,    70,
    42,     1,     0,    72,     0,    72,    46,    38,     0,    72,
    46,     1,     0,    28,     0,    28,     6,    73,     7,     0,
    28,     6,    73,     1,     0,    48,     0,    49,     0,    38,
     1,     0,    38,     0,     0,    75,     0,     0,    76,     0,
    75,    69,     0,    75,    76,     0,    66,     0,    77,     0,
    79,     0,    80,     0,    81,     0,    78,    44,     0,    82,
     1,     0,    82,     0,    78,    42,    82,     0,     0,    10,
    47,    82,    45,    76,     0,    10,    47,    82,    45,    76,
     9,    76,     0,    10,    47,    82,     1,     0,    10,    47,
    45,     0,    16,    47,    82,    45,    76,     0,    12,    78,
    44,     0,    12,    78,     1,     0,    83,     0,    84,     0,
    90,    46,    83,     0,    90,    34,    83,     0,    90,    35,
    83,     0,    90,    36,    83,     0,    90,    37,    83,     0,
    90,    14,    83,     0,    85,     0,    84,    31,    85,     0,
    86,     0,    85,    30,    86,     0,    87,     0,    86,    22,
    87,     0,    86,    23,    87,     0,    88,     0,    87,    25,
    88,     0,    87,    24,    88,     0,    87,    27,    88,     0,
    87,    26,    88,     0,    89,     0,    88,    17,    89,     0,
    88,    18,    89,     0,    90,     0,    89,    19,    90,     0,
    89,    20,    90,     0,    89,    21,    90,     0,    91,     0,
    18,    90,     0,    29,    90,     0,    32,    90,     0,    33,
    90,     0,    95,     0,    91,     6,    82,     7,     0,    91,
    47,    92,    45,     0,    91,    32,     0,    91,    33,     0,
    93,     0,     0,    94,     0,    83,     0,    94,    42,    83,
     0,    28,     0,    48,     0,    38,     0,    47,    82,    45,
     0,    47,    82,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    29,    30,    31,    32,    33,    34,    35,    38,    43,    46,
    47,    48,    49,    50,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    82,    83,    84,    88,    89,    93,
    94,    95,    96,    97,   100,   105,   113,   114,   115,   121,
   122,   123,   124,   125,   129,   136,   137,   138,   142,   143,
   144,   148,   159,   168,   172,   173,   174,   179,   180,   181,
   182,   183,   184,   185,   186,   187,   188,   189,   190,   192,
   193,   199,   200,   201,   203,   204,   205,   210,   216,   217,
   218,   222,   223,   224,   225,   226,   227,   228,   229,   231,
   232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
   242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
   252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
   262,   263,   264,   265,   270,   271,   272,   273
};

static const char * const yytname[] = {   "$","error","$undefined.","TEOF","TLBRACE",
"TRBRACE","TLBRACKET","TRBRACKET","TCONST","TELSE","TIF","TINT","TRETURN","TVOID",
"TMODASSIGN","TEIF","TWHILE","TPLUS","TMINUS","TSTAR","TSLASH","TMOD","TEQUAL",
"TNOTEQU","TLESS","TGREAT","TLESSE","TGREATE","TIDENT","TNOT","TAND","TOR","TINC",
"TDEC","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TNUMBER","TCOMMENT",
"TSTRING","TERROR","TCOMMA","TCARR","TSEMI","TRPAREN","TASSIGN","TLPAREN","TILLIDENT",
"TLONG","LOWER_THAN_ELSE","mini_c","translation_unit","external_dcl","function_def",
"function_header","dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier",
"type_specifier","function_name","formal_param","opt_formal_param","formal_param_list",
"param_dcl","compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
    53,    54,    54,    54,    55,    56,    57,    57,    58,    58,
    59,    60,    60,    61,    61,    61,    61,    62,    62,    63,
    63,    64,    64,    64,    64,    65,    65,    66,    66,    67,
    67,    68,    68,    69,    69,    70,    70,    70,    71,    71,
    71,    72,    72,    72,    72,    72,    72,    73,    73,    74,
    74,    75,    75,    75,    76,    76,    76,    76,    76,    77,
    77,    78,    78,    78,    79,    79,    79,    79,    80,    81,
    81,    82,    83,    83,    83,    83,    83,    83,    83,    84,
    84,    85,    85,    86,    86,    86,    87,    87,    87,    87,
    87,    88,    88,    88,    89,    89,    89,    89,    90,    90,
    90,    90,    90,    91,    91,    91,    91,    91,    92,    92,
    93,    94,    94,    95,    95,    95,    95,    95
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     1,     2,     2,
     2,     2,     2,     2,     3,     1,     1,     2,     1,     1,
     1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
     0,     1,     3,     3,     3,     2,     2,     4,     4,     1,
     0,     1,     2,     3,     3,     1,     3,     3,     1,     3,
     3,     1,     4,     4,     1,     1,     2,     1,     0,     1,
     0,     1,     2,     2,     1,     1,     1,     1,     1,     2,
     2,     1,     3,     0,     5,     7,     4,     3,     5,     3,
     3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
     3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
     3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
     2,     2,     2,     1,     4,     4,     2,     2,     1,     0,
     1,     1,     3,     1,     1,     1,     3,     3
};

static const short yydefact[] = {     0,
     0,     8,    21,    22,    23,     0,     0,     0,     1,     2,
     4,     0,     0,    16,    17,    19,    20,     5,    11,     7,
     6,     9,    10,     3,    14,    41,    13,    12,    52,     0,
    55,    56,     0,     0,    46,    49,    18,     0,    61,    40,
    42,    59,    57,    31,    15,    45,     0,    44,     0,    52,
     0,    55,    56,     0,    74,     0,     0,   124,     0,     0,
     0,   126,     0,   125,    65,     0,    60,    62,    66,     0,
    67,    68,    69,     0,    82,    83,    90,    92,    94,    97,
   102,   105,   109,   114,    43,    58,     0,     0,     0,    30,
    32,     0,    48,    47,    51,    50,    57,     0,     0,    72,
     0,   110,   111,   112,   113,     0,    39,    38,    63,    64,
     0,    70,    71,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   117,   118,   120,    54,    53,    36,    29,
    28,     0,     0,    37,    78,     0,    81,    80,     0,   128,
   127,    73,    91,   105,    93,    95,    96,    99,    98,   101,
   100,   103,   104,   106,   107,   108,    89,    85,    86,    87,
    88,    84,     0,   122,     0,   119,   121,    35,    33,    34,
    77,    74,    74,   115,   116,     0,    75,    79,   123,    74,
    76,     0,     0,     0
};

static const short yydefgoto[] = {   192,
     9,    10,    11,    12,    38,    14,    15,    16,    17,    33,
    45,    89,    90,    91,    65,    39,    40,    18,    34,    35,
    36,    87,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
   175,   176,   177,    84
};

static const short yypact[] = {   102,
    19,-32768,-32768,-32768,-32768,     5,    29,    57,   102,-32768,
-32768,    15,   -20,    26,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    26,-32768,-32768,    42,    62,
    -4,    38,    45,    20,-32768,    49,-32768,   194,   152,    26,
-32768,    76,    71,   138,-32768,-32768,     4,-32768,     2,   116,
   122,-32768,-32768,   101,   212,   103,   212,-32768,   212,   212,
   212,-32768,   212,-32768,-32768,    82,   125,-32768,-32768,    13,
-32768,-32768,-32768,    44,-32768,   121,   135,    43,    78,    91,
   140,   168,    87,-32768,-32768,-32768,    34,   194,     6,    25,
-32768,   154,-32768,-32768,-32768,-32768,-32768,   191,    55,-32768,
   212,-32768,-32768,-32768,-32768,     9,-32768,-32768,-32768,-32768,
   212,-32768,-32768,   212,   212,   212,   212,   212,   212,   212,
   212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
   212,   212,   212,-32768,-32768,   212,-32768,-32768,-32768,-32768,
-32768,    83,   194,-32768,-32768,    16,-32768,-32768,   126,-32768,
-32768,-32768,   135,-32768,    43,    78,    78,    91,    91,    91,
    91,   140,   140,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   170,-32768,   133,-32768,   137,-32768,-32768,-32768,
-32768,   179,   179,-32768,-32768,   212,   183,-32768,-32768,   179,
-32768,   188,   193,-32768
};

static const short yypgoto[] = {-32768,
-32768,   189,-32768,-32768,     0,-32768,   187,-32768,-32768,-32768,
-32768,-32768,-32768,    64,   198,-32768,-32768,    72,-32768,   166,
   -42,-32768,-32768,-32768,   -66,-32768,   160,-32768,-32768,-32768,
   -51,  -105,-32768,   104,   106,    28,     7,    52,   -46,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		260


static const short yytable[] = {    13,
   110,    92,    95,   100,    93,    20,   140,    29,    13,   150,
   102,   106,   103,   104,   105,    25,   181,    30,    26,    19,
    46,   167,   168,   169,   170,   171,   172,    31,    32,    22,
   174,    50,     3,     3,   137,     4,     4,     5,     5,    96,
   138,    51,   -26,    88,   113,   139,   146,    42,    21,   149,
   141,    52,    53,   151,   111,   147,   112,    23,    27,   152,
   182,    47,    43,    48,   116,   117,   142,   154,   154,   154,
   154,   154,   154,   154,   154,   154,   154,   164,   165,   166,
   189,   173,   107,   178,   -25,   -72,   108,   -72,   -24,   143,
     3,    44,   133,     4,    49,     5,   111,    41,   148,    92,
   180,   118,   119,   120,   121,     1,     2,   122,   123,     3,
    50,    85,     4,    86,     5,   187,   188,   -27,   134,   135,
    51,    42,    97,   191,   158,   159,   160,   161,    26,     6,
    52,    53,     3,   136,    54,     4,    55,     5,   109,     7,
    56,    88,    57,   156,   157,     3,     8,    98,     4,   101,
     5,   114,    58,    59,   144,    26,    60,    61,   124,   125,
   126,    54,    62,    55,   115,    50,   -74,    56,   -74,    57,
   183,    63,    64,   162,   163,    51,   184,   185,   186,    58,
    59,   127,    26,    60,    61,    52,    53,   193,    54,    62,
    55,   190,   194,   -74,    56,   -74,    57,    24,    63,    64,
    37,   128,   129,   130,   131,   179,    58,    59,    57,    28,
    60,    61,    94,   132,    99,     0,    62,   153,    58,    59,
   155,    50,    60,    61,     0,    63,    64,     0,    62,    57,
     0,    51,     0,     0,     0,   145,     0,    63,    64,    58,
    59,    52,    53,    60,    61,     0,     0,     0,     0,    62,
     0,     0,     0,     0,     0,     0,     0,     0,    63,    64
};

static const short yycheck[] = {     0,
    67,    44,     1,    55,     1,     1,     1,    28,     9,     1,
    57,    63,    59,    60,    61,     1,     1,    38,     4,     1,
     1,   127,   128,   129,   130,   131,   132,    48,    49,     1,
   136,    28,     8,     8,     1,    11,    11,    13,    13,    38,
     7,    38,    47,    44,     1,    88,    98,     6,    44,   101,
    45,    48,    49,    45,    42,     1,    44,     1,    44,   111,
    45,    42,     1,    44,    22,    23,    42,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   186,   133,     1,     1,    47,    42,     5,    44,    47,    90,
     8,    47,     6,    11,    46,    13,    42,    26,    44,   142,
   143,    24,    25,    26,    27,     4,     5,    17,    18,     8,
    28,    40,    11,    38,    13,   182,   183,    47,    32,    33,
    38,     6,     1,   190,   118,   119,   120,   121,     4,    28,
    48,    49,     8,    47,    10,    11,    12,    13,    67,    38,
    16,   142,    18,   116,   117,     8,    45,    47,    11,    47,
    13,    31,    28,    29,     1,     4,    32,    33,    19,    20,
    21,    10,    38,    12,    30,    28,    42,    16,    44,    18,
    45,    47,    48,   122,   123,    38,     7,    45,    42,    28,
    29,    14,     4,    32,    33,    48,    49,     0,    10,    38,
    12,     9,     0,    42,    16,    44,    18,     9,    47,    48,
    14,    34,    35,    36,    37,   142,    28,    29,    18,    12,
    32,    33,    47,    46,    55,    -1,    38,   114,    28,    29,
   115,    28,    32,    33,    -1,    47,    48,    -1,    38,    18,
    -1,    38,    -1,    -1,    -1,    45,    -1,    47,    48,    28,
    29,    48,    49,    32,    33,    -1,    -1,    -1,    -1,    38,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 35 "parser.y"
{
               yyerrok;
               reporterror(wrong_stat);
            ;
    break;}
case 8:
#line 39 "parser.y"
{
                    yyerrok;
                    reporterror(nobrace);
              ;
    break;}
case 9:
#line 43 "parser.y"
{
         yyerrok; reporterror(invalid_n);
         ;
    break;}
case 10:
#line 46 "parser.y"
{yyerrok; reporterror(noparen);
    break;}
case 11:
#line 47 "parser.y"
{yyerrok; reporterror(nobrace);
    break;}
case 14:
#line 50 "parser.y"
{
                      
                       yyerrok;
                       reporterror(wrong_funcdef);    
                     ;
    break;}
case 21:
#line 61 "parser.y"
{type_const=1;;
    break;}
case 22:
#line 62 "parser.y"
{type_int=1;;
    break;}
case 23:
#line 63 "parser.y"
{type_void=1;;
    break;}
case 24:
#line 64 "parser.y"
{
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
                  ;
    break;}
case 27:
#line 84 "parser.y"
{
         yyerrok; reporterror(invalid_n);
         ;
    break;}
case 29:
#line 89 "parser.y"
{
            yyerrok;
            reporterror(noparen);
            ;
    break;}
case 34:
#line 97 "parser.y"
{
         reporterror(nocomma);
         ;
    break;}
case 35:
#line 100 "parser.y"
{
         yyerrok;
         reporterror(emptycomma);
         ;
    break;}
case 36:
#line 105 "parser.y"
{
                  if(type_int==1){ /* int로 설정된 경우 */
                        param_int=1; 
                        look_id->type=7;  /* integer scalar parameter */
                  }
                  type_int=0;
                  type_void=0;
                  param_int=0;
;
    break;}
case 37:
#line 113 "parser.y"
{yyerrok; reporterror(invalid_p);/*param에서 자료형 선언하지 않고 identifier 들어온 경우*/;
    break;}
case 39:
#line 116 "parser.y"
{
               yyerrok;
               reporterror(nobrace); /* no brace error */
            ;
    break;}
case 44:
#line 125 "parser.y"
{
               type_int=0;
                           type_void=0;
            ;
    break;}
case 45:
#line 129 "parser.y"
{
               look_tmp->type=0; /* identifier about parse error */
               yyerrok;
               type_int=0;
                           type_void=0;
                           reporterror(nosemi); /* no semicolon error */
            ;
    break;}
case 48:
#line 138 "parser.y"
{
            yyerrok;
            reporterror(emptycomma);
         ;
    break;}
case 51:
#line 144 "parser.y"
{
                        yyerrok;
                        reporterror(wrong_init);
                      ;
    break;}
case 52:
#line 148 "parser.y"
{
                     if(look_id->type==0){
                           /* scalar : int인지 void인지에 따라*/
                           if(type_int==1){
                                 look_id->type=1; /* integer scalar variable */
                           }
                           else if(type_void==1)
                                 look_id->type=2; /* void scalar variable */
                        }
                     look_tmp=look_id;
            ;
    break;}
case 53:
#line 160 "parser.y"
{
                     /* array */
                     if(look_id->type==0){
                           if(type_int==1) 
                        {look_id->type=3;} /* array integer variable */           
                     }
                      look_tmp=look_id;
               ;
    break;}
case 54:
#line 168 "parser.y"
{
            yyerrok;
            reporterror(nobracket); /* no bracket error */
         ;
    break;}
case 57:
#line 174 "parser.y"
{
         yyerrok; reporterror(invalid_n);
         ;
    break;}
case 71:
#line 194 "parser.y"
{
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                  ;
    break;}
case 77:
#line 206 "parser.y"
{
      yyerrok;
      reporterror(noparen); /* error - no parenthesis */
   ;
    break;}
case 78:
#line 211 "parser.y"
{
      yyerrok;
      reporterror(no_expression); /* error - no expression */
   ;
    break;}
case 81:
#line 218 "parser.y"
{
                        yyerrok;
                        reporterror(nosemi); /* no semicolon error */
                ;
    break;}
case 124:
#line 265 "parser.y"
{
                  if(look_id->type==0)
                        look_id->type=5; /* not defined identifier/function */

            ;
    break;}
case 128:
#line 273 "parser.y"
{yyerrok; reporterror(noparen);
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 274 "parser.y"
