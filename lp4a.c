#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
char stack[50];
int top=-1;
void push(int n){
stack[++top]=n;
}
int pop(){
    return(stack[top--]);
}
void main(){
    char ch;
    char s[50];
    printf("Enter postfix expression:\n");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        ch=s[i];
        if(isdigit(ch))
        push(ch-'0');
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'|| ch=='%' || ch=='%' || ch=='^' || ch=='$'){
            if(top<1){
            printf("invalid expression");
            return;
            }
            int b=pop();
            int a=pop();
            switch(ch){
                case '+':
                push(a+b);
                break;
                case '-':
                push(a-b);
                break;
                case '*':
                push(a*b);
                break;
                case '/':
                if(b==0){
                    printf("division by zero\n");
                    return;
                }
                push(a/b);
                break;
                case '%':
                if(b==0){
                    printf("division by zero\n");
                    return;
                }
                push(a%b);
                break;
                case '^':
                case '$':
                push(pow(a,b));
                break;
            }

        }
        else{
            printf("invalid operation\n");
            return;
        }
    }
    if(top!=0){
        printf("invalid expression\n");
        return;
    }
    int ans=pop();
    printf("result:%d",ans);
}