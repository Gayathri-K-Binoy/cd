#include<stdio.h>
#include<string.h>
#define MAX 50

char input[MAX],stack[MAX];
int top=-1,pos=0;
void print_stack(){
for(int i=0;i<=top;i++){
if(stack[i]=='I')
printf("id");
else printf("%c",stack[i]);
}

}

void check(){
while (1){
if(top>=0 && stack[top]=='I'){
stack[top]='E';
printf("$");
print_stack();
printf("\t %s$ \tREDUCE-> id\n",input+pos);
}
else if(top>=2 && stack[top-2]=='E' & stack[top-1]=='+' && stack[top]=='E'){
top-=2;
stack[top]='E';
printf("$");
print_stack();
printf("\t %s$ \tREDUCE-> E+E\n",input+pos);

}
else if(top>=2 && stack[top-2]=='E' & stack[top-1]=='*' && stack[top]=='E'){
top-=2;
stack[top]='E';
printf("$");
print_stack();
printf("\t %s$ \tREDUCE-> E*E\n",input+pos);

}
else if(top>=2 && stack[top-2]=='(' & stack[top-1]=='E' && stack[top]==')'){
top-=2;
stack[top]='E';
printf("$");
print_stack();
printf("\t %s$ \tREDUCE-> (E)\n",input+pos);
}
else return;

}
}





int main(){
printf("Grammar : E->E+E | E*E| (E)|id\n");
printf("Enter input\n");
scanf("%s",input);
printf("\nStack\tInput\tAction\n");
while(input[pos]!='\0'){
if(input[pos]=='i' && input[pos+1]=='d'){
stack[++top]='I';
pos+=2;
printf("$");
print_stack();
printf("\t %s$ \tSHIFT-> id\n",input+pos);
check();
}
else{
stack[++top]=input[pos];
pos++;
printf("$");
print_stack();
printf("\t %s$ \tSHIFT-> %c\n",input+pos,stack[top]);
check();
}
}
if(top==0 && stack[top]=='E')printf("\nSUCESS");
else printf("\nFailure\n");


}