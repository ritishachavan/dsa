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
NODEPTR insert_front(NODEPTR list,int item){
    NODEPTR p;
    p=getnode();
    p->info=item;
    p->next=list;
    printf("Inserted %d",item);
    return p;
}
NODEPTR insert_rear(NODEPTR list,int item){
    NODEPTR p,q;
    p=getnode();
    p->info=item;
    p->next=NULL;
    if(list==NULL){
        return p;
    }
    else{
        q=list;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
    printf("Inserted %d at rear",item);
    return list;
}
NODEPTR delete_front(NODEPTR list){
    NODEPTR p;
    if(list==NULL){
        printf("list is empty, cannot delete");
        return NULL;
    }
    p=list;
    list=p->next;
    printf("Deleted %d",p->info);
    freenode(p);
    return list;
}
void display(NODEPTR list){
    NODEPTR p;
    p=list;
    int count=0;
    printf("contents of the linked list are:");
    while(p!=NULL){
        printf("%d ",p->info);
        count++;
        p=p->next;
    }
    printf("the number of nodes in list:%d",count);
}
int main(){
    NODEPTR list=NULL;
    int choice, item;
    while(1){
    printf("\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Display\n5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the elemtn to be inserted:");
        scanf("%d",&item);
        list=insert_front(list,item);
        break;
        case 2:
        printf("Enter the elemtn to be inserted:");
        scanf("%d",&item);
        list=insert_rear(list,item);
        break;
        case 3:
        list=delete_front(list);
        break;
        case 4:
        display(list);
        break;
        case 5:
        exit(0);
        default:
        printf("Enter valid choice");
    }
}
}