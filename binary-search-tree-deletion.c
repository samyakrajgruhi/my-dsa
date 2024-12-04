#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

struct node *insertBST(struct node *root,int data){
    if(root==NULL){
        return createnode(data);
    }
    struct node *temp = root;
    if(data>temp->data){
        root->right = insertBST(temp->right,data);
    }
    else if(data<temp->data){
        root->left = insertBST(temp->left,data);
    }
    return root;
}

struct node *findMin(struct node *root){
    struct node *current=root;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct node *delete(struct node *root,int data){
    if(root == NULL){
        return root;
    }

    if(data<root->data){
        root->left = delete(root->left,data);
    }

    else if(data>root->data){
        root->right = delete(root->right,data);
    }

    else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right,temp->data);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    
}

void main(){
    struct node *root=NULL;
    root = insertBST(root,10);
    insertBST(root,40);
    insertBST(root,50);
    insertBST(root,5);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,6);
    insertBST(root,9);

    inorder(root);
    printf("\n");
    root = delete(root,10);

    inorder(root);
}