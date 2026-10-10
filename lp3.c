#include<stdio.h>
#include<stdlib.h>
char stack[50];
int top=-1;
void push(char ch){
    stack[++top]=ch;
}
char pop(){
    return(stack[top--]);
}
int prcd(char ch){
    int p=0;
    switch(ch){
        case '^':
        p=3;
        break;
        case '*':
        case '/':
        case '%':
        p=2;
        break;
        case '-':
        case '+':
        p=1;
        break;
        case '(':
        p=0;
        break;
        default:
        p=0;
    }
    return p;
}
void conversion(char infix[],char postfix[]){
    int i=0,p=0;
    char ch;
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];
    
        switch(ch){
            default:
            postfix[p++]=ch;
            break;
            case '(':
            push(ch);
            break;
            case ')':
            while(top!=-1 && stack[top]!='(')
            postfix[p++]=pop();
            if(top!=-1)
            pop();
            break;
            case '^':
            while(top!=-1 && prcd(stack[top])>prcd(ch))
            postfix[p++]=pop();
            push(ch);
            break;
            case '*':
            case '/':
            case '+':
            case '%':
            case '-':
            while(top!=-1 && prcd(stack[top])>=prcd(ch))
            postfix[p++]=pop();
            push(ch);
            break;
        }
    }
    while(top!=-1)
    postfix[p++]=pop();
    postfix[p]='\0';
}
void main(){
    char infix[50],postfix[50];
    printf("enter infix expression:\n");
    scanf("%s\n",infix);
    conversion(infix,postfix);
    printf("postfix expression:%s\n",postfix);
}