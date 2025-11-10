#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 30
char s[max];
int top=-1;
void push(char c){
if (top==max){
    printf("stack overflow");}
else{
    s[++top]=c;}}
char pop(){
    if(top==-1){
        printf("stack underflow");

    }
    else{
        char p=s[top--];
        return p;

    }
}
int prec(char op){
switch(op){
case '^': return 3;
case '*':
case '/':return 2;
case '+':
case'-': return 1;
default:return -1;
}}
int main(){
char infix[max],postfix[max];
printf("infix exp:");
scanf("%s",infix);
int k=0;
int l=strlen(infix);
for(int i=0;i<l;i++){
    if(isalnum(infix[i]))
        postfix[k++]=infix[i];

else if(infix[i]=='(')
         push(infix[i]);
else if(infix[i]==')'){
    while((top!=-1&&s[top]!='(')){
           postfix[k++]=pop();
}pop();}
else{
    while(top!=-1&&prec(s[top])>prec(infix[i]))
        postfix[k++]=pop();
}
push(infix[i]);
}
while(top!=-1){
    postfix[k++]=pop();

postfix[k]='\0';}
printf("postfix:%s",postfix);
return 0;
}
