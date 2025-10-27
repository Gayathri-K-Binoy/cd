#include<stdio.h>
#include<string.h>
#include<ctype.h>

int lineno=0,i;
char c,str[100];

char *keywords[]={
"for","while","if","else","break","continue","return","int","double","float","static","char"
};

char isKeyword(char *c){
for(int k=0;k<sizeof(keywords)/sizeof(keywords[0]);k++){
if(strcmp(keywords[k],c)==0)return 1;
}
return 0;
}


int main(){
FILE *f=fopen("input.txt","r");
if(!f){
printf("Error open file\n");
return 1;
}

while((c=getc(f))!=EOF){
if(isdigit(c)){

int num=c-'0';
while(isdigit(c=getc(f)))num=num*10+(c-'0');
ungetc(c,f);
printf("%d is a integer\n",num);

}
else if(isalpha(c) || c=='_'){
i=0; str[i++]=c;
while(isalnum(c=getc(f)) || c=='_' || c=='$')str[i++]=c;
str[i]='\0';
ungetc(c,f);
if(isKeyword(str)){
printf("%s is a keyword\n",str);
}
else printf("%s is a identifier\n",str);
}

else if(strchr("+-/*<>!&|=",c)){
char op[3]={c,'\0','\0'};
char next= getc(f);
if((c=='+' && next=='+') ||(c=='-' && next=='-') ||(c=='=' && next=='=') ||(c=='!' && next=='=') ||(c=='|' && next=='|') ||(c=='&' && next=='&') ||(c=='<' && next=='=') ||(c=='>' && next=='=') ){
op[1]=next;
}
else ungetc(next,f);
printf("%s is operator\n",op);
}
else if(c==' ' || c=='\t');
else if(c=='\n')lineno++;
else printf("%c is delimiter/special symbol\n",c);
}
fclose(f);
printf("Number of lines: %d",lineno);
return 0;
}