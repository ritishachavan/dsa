#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
int hash(int key){
    return key%SIZE;
}
void insert(int ht[],int key){
    int index,i;
    index=hash(key);
    for(i=0;i<SIZE;i++){
    if(ht[index]==-1){
        ht[index]=key;
        printf("inserted %d",key);
        return;
    }
    index=(index+1)%SIZE;
}
printf("Hash table is full, cannot insert");

}
void display(int ht[]){
    printf("Hash table:\n");
    printf("Index \t Key\n");
    for(int i=0;i<SIZE;i++){
        if(ht[i]==-1)
        printf("%d \t Empty\n",i);
        else
        printf("%d \t %d\n",i,ht[i]);
    }
}
void main(){
    int ht[SIZE],choice, key;
    for(int i=0;i<SIZE;i++){
        ht[i]=-1;
    }
    while(1){
        printf("\n1.Insert\n2.Display\n3.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the elemtn to be inserted :");
            scanf("%d",&key);
            insert(ht,key);
            break;
            case 2:
            display(ht);
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Enter valid choice:");
        }
    }
}