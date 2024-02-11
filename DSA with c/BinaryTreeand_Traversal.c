#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};


struct node*Create(){
    int x;
 struct node*newnode;
 newnode=(struct node*)(malloc(sizeof(struct node)));
 printf("\nEnter data (for no node -1):");
 scanf("%d",&x);
 if(x==-1){
     return 0;
 }
 else{
     newnode->data=x;
     printf("\nEnter the left child for %d",x);
     newnode->left=Create();
     printf("\nEnter the right child of %d",x);
     newnode->right=Create();
    return newnode;   
 }
}

void Preorder(struct node*root){
    if(root==0){
        return;
    }
    else{
    printf("%d\t",root->data);
    Preorder(root->left);
    Preorder(root->right);}
}


void Inorder(struct node*root){
    if(root==0){
        return ;
    }
    else{
        Inorder(root->left);
        printf("%d\t",root->data);
        Inorder(root->right);
    }
}


void Postorder(struct node*root){
    if(root==0){
        return;
    }
    else{
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\t",root->data);
    }
}

int main(){
    struct node*root;
    root=Create();
    printf("\nPreorder traversal:\n");
    Preorder(root);
    
    printf("\nInorder Traversal of the Tree:\n");
    Inorder(root);
   
    
    printf("\nPostorder traversal of the tree:\n");
    Postorder(root);
    
     return 0;
}
