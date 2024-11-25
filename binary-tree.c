#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void inorder(struct node *next){
    if(next!=NULL){
        inorder(next->left);
        printf("%d ",next->data);
        inorder(next->right);
    }
}

int main(){
    struct node *root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(5);

    printf("inorder traversal :\n");

    inorder(root);
}