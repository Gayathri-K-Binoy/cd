#include<stdio.h>
#include<string.h>
void generate(char *expr, char op, char *reg){
char temp[100];
int i=0,j=0;
while(expr[i]!='\0'){
if(expr[i]==op){
	printf("%c\t%c\t%c\t%c\n",op,*reg,expr[i-1],expr[i+1]);
	temp[j-1]=*reg;
	i+=2;
	(*reg)--;//Z-Y-X
}
else{
temp[j++]=expr[i++];
}
}
temp[j]='\0';
strcpy(expr,temp);

}
void gencode(char *expr){
char reg='Z';
generate(expr,'/',&reg);
generate(expr,'*',&reg);
generate(expr,'+',&reg);
generate(expr,'-',&reg);
generate(expr,'=',&reg);

}
int main(){
char expr[100];
printf("Enter expression\n");
scanf("%s",expr);
printf("\nOp\tRes\tArg1\tArg2\n");
gencode(expr);
return 0;

}