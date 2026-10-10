#include<stdio.h>
#include<stdlib.h>
#define MAX 3
struct queue{
    int front, rear;
    int item[MAX];
};
void enqueue(int value,struct queue *q){
    if(q->rear==MAX-1){
        printf("Queue overflow\n");
        return;
    }
    q->rear=q->rear+1;
    q->item[q->rear]=value;
    printf("inserted\n");
}
void dequeue(struct queue *q){
    if(q->front>q->rear){
        printf("queue underflow\n");
        return;
    }
    int element=q->item[q->front];
    printf(" %d deleted\n",element);
    q->front++;
}
void display(struct queue *q){
    printf("elements in queue are\n");
    for(int i=q->front;i<=q->rear;i++){
        printf("%d \n",q->item[i]);
    }
}
void main(){
    struct queue q;
    q.front=0;
    q.rear=-1;
    int choice;
    while(1){
        printf("1.insert \n2.delete\n3.display\n4.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            int element;
            printf("enter the value:\n");
            scanf("%d",&element);
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