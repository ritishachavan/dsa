#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack{
    int top;
    int item[MAX];
};
void insert(int value, struct stack *s){
    if(s->top==MAX -1)
    printf("Stack overflow\n");
    (s->top)++;
    s->item[s->top]=value;
    printf("Inserted");
}
void delete(struct stack *s){
    if(s->top==-1)
    printf("stack underflow");
    int value=s->item[s->top];
    printf("%d deleted",value);
    s->top--;
}
void display(struct stack *s){
    int i;
    if(s->top==-1)
    printf("Stack is empty");
    printf("Elements in the stack");
        for(i=s->top;i>=0;i--){
            printf("%d \n",s->item[i]);
        }
    }

void main(){
    struct stack s;
    int ch,value;
    s.top=-1;
    while(1){
        printf("Enter your choice:\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                 printf("Enter the value:");
                 scanf("%d",&value);
                 insert(value,&s);
                 break;
            case 2:
                delete(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
                    }
    }
}