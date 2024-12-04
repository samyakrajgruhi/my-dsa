#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data){
    if(root == NULL){
        return createnode(data);
    }
    if(data < root -> data){
        root -> left = insert(root -> left, data);
    }
    else if(data > root -> data){
        root -> right = insert(root -> right, data);
    }

    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void main(){
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 10);
    insert(root, 80);
    insert(root, 60);
    printf("Inorder traversal ");
    inorder(root);
}