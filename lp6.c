#include<stdio.h>
#include<stdlib.h>
#define MAX 3
struct circular{
    int front, rear;
    char item[MAX];
};
void enqueue(char value,struct circular *q){
    if(q->front==(q->rear+1)%MAX){
        printf("Queue overflow\n");
        return;
    }
    if(q->front==-1)
    q->front=0;
    q->rear=(q->rear+1)%MAX;
    q->item[q->rear]=value;
    printf("inserted\n");
}
void dequeue(struct circular *q){
    if(q->front==-1){
        printf("queue underflow\n");
        return;
    }
    char element=q->item[q->front];
     printf(" %c deleted\n",element);

    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
        return;
    }
    else{
        q->front=(q->front+1)%MAX;
    }
   
}
void display(struct circular *q){
    if(q->front==-1){
        printf("queue empty\n");
        return;
    }
    printf("elements in queue are\n");
    int i=q->front;
    while(1){
        printf("%c\n",q->item[i]);
        if(i==q->rear)
        break;
        i=(i+1)%MAX;
    }
}
void main(){
    struct circular q;
    q.front=-1;
    q.rear=-1;
    int choice;
    while(1){
        printf("1.insert \n2.delete\n3.display\n4.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            char element;
            printf("enter the value:\n");
            scanf(" %c",&element);
            enqueue(element,&q);
            break;
            case 2:
            dequeue(&q);
            break;
            case 3:
            display(&q);
            break;
            case 4:
            exit(0);
            default:
            printf("enter valid choice:\n");
        }
    }
}