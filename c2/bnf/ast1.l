%{
typedef struct AST{
char *nodetype;
int val;
struct AST *left, *right;
} AST;
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}

%option noyywrap

%%

[0-9]+ {yylval.num=atoi(yytext); return NUM;}
[-+*/()] return yytext[0];
[\n] return 0;
[ \t]+ ;
. return yytext[0];

%%