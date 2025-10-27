%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct AST{
char *nodetype;
int val;
struct AST* left,*right;
} AST;

AST* makeNode(char *type,AST *l,AST *r){
AST *n=malloc(sizeof(AST));
n->nodetype=strdup(type);
n->val=0;
n->left=l;
n->right=r;
return n;
}
AST* makeNum(int val){
AST*  n=malloc(sizeof(AST));
n->val=val;
n->right=n->left=NULL;
n->nodetype=strdup("NUM");
return n;
}

void printAST(AST *root, int lvl)
{
if(root==NULL)return;
for(int i=0;i<lvl;i++)printf(" ");
if(strcmp(root->nodetype,"NUM")==0){printf("NUM(%d)\n",root->val);}
else printf("%s\n",root->nodetype);

printAST(root->left,lvl+1);
printAST(root->right,lvl+1);
}
int evalAST(AST *root){
if(root==NULL)return 0;
if(strcmp(root->nodetype,"NUM")==0)return root->val;
if(strcmp(root->nodetype,"+")==0)return evalAST(root->left) +evalAST(root->right);
if(strcmp(root->nodetype,"-")==0)return evalAST(root->left) -evalAST(root->right);
if(strcmp(root->nodetype,"*")==0)return evalAST(root->left) *evalAST(root->right);
if(strcmp(root->nodetype,"/")==0)return evalAST(root->left) /evalAST(root->right);
if(strcmp(root->nodetype,"NEG")==0)return -evalAST(root->left);
return 0;
}
%}

%union{ int num; AST* node;}
%token <num> NUM
%type <node> expr
%left '-' '+'
%left '/' '*'
%%
start: expr {printf("\nAST\n"); printAST($1,0);
printf("Result is: %d\n",evalAST($1));
}
;
expr: expr '+' expr{$$=makeNode("+",$1,$3);}
| expr '-' expr {$$=makeNode("-",$1,$3);}
| expr '*' expr {$$=makeNode("*",$1,$3);}
| expr '/' expr {$$=makeNode("/",$1,$3);}
| '(' expr ')' {$$=$2;}
| NUM {$$=makeNum($1);}
;

%%

main(){
printf("ENter\n");
yyparse();
}
yyerror(char *s){
printf("Error %s\n",s);
}













