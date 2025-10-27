%{
#include<stdio.h>
#include<stdlib.h>
int flag=0;
%}

%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
S: T {printf("\nResult is: %d\n",$$);return 0;}
;
T: T '+' T {$$=$1+$3;}
|T '-' T {$$=$1-$3;}
|T '*' T {$$=$1*$3;}
|T '/' T {$$=$1/$3;}
|T '%' T {$$=$1%$3;}
| '(' T ')' {$$=$2;}
| NUM {$$=$1;}
;
%%
void main(){
printf("Enter arith\n");
yyparse();
if(flag==0) printf("\nValid\n");
}

yyerror(char *s){
printf("Invalid\n ",s);
flag=1;
}