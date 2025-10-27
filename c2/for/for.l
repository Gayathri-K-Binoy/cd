%{
#include<stdio.h>
#include "y.tab.h"
%}

%option noyywrap

%%
[0-9]+ return NUM;
"for" return FOR;
[ \t \n]+ ;
[a-zA-Z_][a-zA-Z_0-9]* return ID;
"==" return EQ;
"<=" return LE;
">=" return GE;
"!=" return NE;
"++" return INC;
"--" return DEC;
"||" return OR;
"&&" return AND;
. return yytext[0];

%%