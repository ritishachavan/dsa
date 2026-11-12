#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR getnode(){
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    return p;
}
void freenode(NODEPTR p){
    free(p);
}
NODEPTR insert_front(NODEPTR last,int item){
    NODEPTR p;
    p=getnode();
    p->info=item;
    if(last==NULL){
        last=p;
        p->next=p;
    }
    else{
        p->next=last->next;
        last->next=p;
    }
    return last;
}
NODEPTR insert_rear(NODEPTR last,int item){
    NODEPTR p;
    p=getnode();
    p->info=item;
    if(last==NULL){
        last=p;
        p->next=p;
    }
    else{
        p->next=last->next;
        last->next=p;
        last=p;
    }
    return last;
}
NODEPTR delete_front(NODEPTR last){
    NODEPTR p;
    if(last==NULL){
        printf("list is empty");
        return NULL;
    }
    p=last->next;
    if(p==last){
        last=NULL;
    }
    else{
        last->next=p->next;
     }
    printf("delted %d",p->info);
    freenode(p);
    return last;
}
void display(NODEPTR last){
    NODEPTR p;
    if(last==NULL)
    printf("list empty");
    else{
    p=last->next;
    printf("contents are:\n");
    do{
        printf("%d ",p->info);
        p=p->next;
    }while(p!=last->next);
}
}
void main(){
    NODEPTR last=NULL;
    int choice,item;
    while(1){
    printf("\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Display\n5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the elemtn to be inserted:");
        scanf("%d",&item);
        last=insert_front(last,item);
        break;
        case 2:
        printf("Enter the elemtn to be inserted:");
        scanf("%d",&item);
        last=insert_rear(last,item);
        break;
        case 3:
        last=delete_front(last);
        break;
        case 4:
        display(last);
        break;
        case 5:
        exit(0);
        default:
        printf("Enter valid choice");
    }
}
}
