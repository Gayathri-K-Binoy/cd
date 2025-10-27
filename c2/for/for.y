%{
#include<stdio.h>
#include<stdlib.h>
%}

%token ID NUM FOR INC DEC GE LE NE EQ AND OR 

%right '=' //assignment
%left OR AND //logical
%left '<' '>' EQ LE GE NE //relational
%left '+' '-' //addsub
%left '*' '/' //divmul

%%
START: FOR_LOOP {printf("\nINput accepted\n"); exit(0);}
;
FOR_LOOP: FOR '(' INIT ';' COND ';' UPD ')' BODY
;
INIT: ID '=' EXP
;
COND: VALUE RELOP VALUE
;
RELOP: '<'
| '>'
|LE|GE|NE|EQ
;

UPD: ID INC
| ID DEC
| ID '=' EXP
;

EXP: ID
| NUM
| EXP '+' EXP
| EXP '-' EXP
| EXP '*' EXP
| EXP '/' EXP
;

VALUE: ID
| NUM
;

BODY: '{' STMTLIST '}'
| '{' '}'
|
;

STMTLIST: STMT
| STMTLIST STMT
;

STMT: ID '=' EXP ';'
| FOR_LOOP
;

%%
yyerror(char *s){
printf("Error %s\n",s);
}
main(){
printf("Enter for loop\n");
yyparse();

}