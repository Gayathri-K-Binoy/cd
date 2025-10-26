#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
char prods[MAX][MAX],first[MAX][MAX],follow[MAX][MAX];
int n;//no of prodicution
int add(char *set,char c){
for(int i=0;set[i]!='\0';i++)
{
	if(set[i]==c){
	return 0;
	}
}
int len=strlen(set);
set[len]=c;
set[len+1]='\0';
return 1;

}
void findFirst(char *result, char c){
	if(!isupper(c)){//terminal
	add(result,c);
	return;
	}
		//NT
	for(int i=0;i<n;i++){
		if(prods[i][0]==c){
			if(prods[i][2]=='#')//epsilon
			{
				add(result,'#');
			}
	else{
			int j=2;
			while(prods[i][j]!='\0'){
				char next=prods[i][j];
				if(!isupper(next)){//terminal
					add(result,next);
					break;
				}
				else{//nt following then first a has first b so recursive first b
				char temp[MAX]="";
				findFirst(temp,next);
				int hasepsilon=0;
				for(int k=0;temp[k]!='\0';k++){
					if(temp[k]!='#'){
						add(result,temp[k]);
					}
					else{
					hasepsilon=1;
					}				
				}
				if(!hasepsilon) break;
				j++;
				if(prods[i][j]=='\0'){
					add(result,'#');
				}
				}
					
			}			
			}
		}
	}

}
void findFollow(char *result,char c){
//start symbol
if(prods[0][0]==c){add(result,'$');}

	for(int i=0;i<n;i++){
		for(int j=2;prods[i][j]!='\0';j++){
			if(prods[i][j]==c){
				if(prods[i][j+1]!='\0'){
				char next=prods[i][j+1];
				if(!isupper(next))//terminal
					{add(result,next);
					}
				else{
				char temp[MAX]="";
				findFirst(temp,next);
				int hasepsilon=0;
				for(int k=0;temp[k]!='\0';k++){
				if(temp[k]!='#'){
				add(result,temp[k]);
				}
				else{hasepsilon=1;}
				}
				if(hasepsilon){
				char temp2[MAX]="";
				findFollow(temp2,prods[i][0]);
				for(int k=0;temp2[k]!='\0';k++){
					add(result,temp2[k]);
				}				
				}
				}
				}
				else if(prods[i][0]!=c){
				char temp[MAX]="";
				findFollow(temp,prods[i][0]);
				for(int k=0;temp[k]!='\0';k++){
					add(result,temp[k]);
				}		
				}
			}
		}	
	}
}

int main(){
char first[MAX],follow[MAX];
char c;
printf("Enter number of productions");
scanf("%d",&n);
getchar();
printf("Enter productions");
for(int i=0;i<n;i++) {fgets(prods[i],MAX,stdin);
	for(int j=0;prods[i][j]; j++){
	if(prods[i][j]=='\n'){prods[i][j]='\0';
	break;
	}
	}
}
for(int i=0;i<n;i++){
c=prods[i][0];//lhs
memset(first,0,sizeof(first));
memset(follow,0,sizeof(follow));
findFirst(first,c);
findFollow(follow,c);
printf("\n%c: \n",c);
printf("First of %c is : ",c);
for(int j=0;first[j];j++){
printf("%c  ",first[j]);
}
printf("\nFollow of %c is : ",c);
for(int j=0;follow[j];j++){
printf("%c  ",follow[j]);
}
printf("\n");
}
return 0;
}