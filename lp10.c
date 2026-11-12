#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right, *left;
};
typedef struct node *NODEPTR;
NODEPTR insert(NODEPTR root,int x){
    if(root==NULL){
        root=(NODEPTR)malloc(sizeof(struct node));
        root->data=x;
        root->right=NULL;
        root->left=NULL;
    }
    if(x>root->data){
        root->right=insert(root->right,x);
    }
    else if(x<root->data){
        root->left=insert(root->left,x);
    }
    return root;
}
void inorder(NODEPTR root){
    if(root!=NULL){
       
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right);
    }
}
void preorder(NODEPTR root){
    if(root!=NULL){
       
        printf("%d, ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODEPTR root){
    if(root!=NULL){
       
        postorder(root->left);
        postorder(root->right);
        printf("%d, ",root->data);
    }
}
NODEPTR search(NODEPTR root, int key){
    if(root==NULL||key==root->data){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else if(key>root->data){
        return search(root->right,key);
    }
}
void main(){
    int key, choice,x;
    NODEPTR root=NULL;
    while(1){
    printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Seach\n6.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the element to be inserted:");
        scanf("%d",&x);
        root=insert(root,x);
        break;
        case 2:
        printf("inorder:\n");
        inorder(root);
        break;
        case 3:
        printf("preorder:\n");
        preorder(root);
        break;
        case 4:
        printf("postorder:\n");
        postorder(root);
        break;
        case 5:
        printf("enter the element to search:");
        scanf("%d",&key);
        if(search(root,key)!=NULL)
        printf("element found");
        else
        printf("element not found");
        break;
        case 6:
        exit(0);
        default:
        printf("enter valid choice:");
    }
}
}