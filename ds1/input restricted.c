#include<stdio.h>
#define size 5
int n[max];
int r=-1,f=-1;
void id();
void od();
void insrear()
void delrear();
void delfr();
void infr();
void display();
int main(){
int ch;
printf("enter your choice: \n 1.output restricted queue \n 2.input restricted queue);
scanf("%d",ch);
switch(ch){
case 1:
    void od();
    break;
case 2:
    void id();
    break;
default:
    printf("wrong choice!");
}
return 0;}
void od(){
printf("enter your chice to perform on output restricted queue:\n1.insert rear 2.insert front 3.delete front 5.exit");
int o;
scanf("%d",&o);
do{
switch(o)
{
case 1:
    insrear();
    break;
case 2:
    infr();
    break;
case 3:
    delfr();
    break;
case 4:
    display();
default:
    printf("wrong case!")
}while(o!=5);}}
void id(){
printf("enter your chice to perform on input restricted queue:\n1.insert rear 2.delete front 3.delete rear 5.exit");
int o;
scanf("%d",&o);
do{
switch(o)
{
case 1:
    insrear();
    break;
case 2:
    delfr();
    break;
case 3:
    delrear();
    break;
case 4:
    display();
default:
    printf("wrong case!")
}while(o!=5);}}
void insrear(){
int v;
printf("enter value to be inserted");
scanf("%d",&v);
if(f==0&&r==n-1||f==r+){
    printf("overflow");
}
if(f==-1){
    l=0;
    r=0;
}
else{
    if(l==max-1){
        l=0;
    }
    else{
        r=r+1;
    }
    n[r]=v
}}
void infr(){
int v;
printf("enter value to be inserted");
scanf("%d",&v);
if(f==0&&r==n-1||f==r+){
    printf("overflow");
}
if(f==-1){
    l=0;
    r=0;
}
else{
    if(l==0){
        l=max-1;
    }
    else{
        f--;
    }
    n[f]=v
}}
void delfr(){

}
