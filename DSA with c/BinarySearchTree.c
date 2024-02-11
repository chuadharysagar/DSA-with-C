#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node * right;
    
};

struct node * createNode(int value){
struct node* newnode = (struct node *)(malloc(sizeof(struct node)));
  newnode->data=value;
  newnode->left=newnode->right=NULL;
  
  return newnode;
}

struct node * Insertion(struct node* root, int item){
    if(root==NULL){
       return createNode(item);
    }
    if(item>root->data){
        root->right= Insertion(root->right,item);
    }
    else{
        root->left=Insertion(root->left,item);
    }
    
  return root;  
}

void Inorder(struct node *root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    printf("%d\t",root->data);
    Inorder(root->right);
}

//Search operation 
struct node* Search(struct node * root, int key){
    if(root->data==key || root==NULL){
        return root;
    }
    if(key>root->data){
        return Search( root->right,key);
    }
    return Search(root->left,key);
    
}

int main(){
    struct node* root=NULL;
    root=Insertion(root,12);
    Insertion(root,10);
    Insertion(root,7);
    Insertion(root,100);
    Insertion(root,78);
    Insertion(root,1);
    printf("The order Traversal of the Bst\n");
    Inorder(root);
    
    struct node * result= Search(root,7);
    if(result!=NULL){
        printf("\nThe element is found");
    }
    else{
        printf("Element is not found");
    }
    return 0;
}



