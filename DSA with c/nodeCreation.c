#include<stdio.h>
#include<stdlib.h>

int main(){
    struct node{
        
        int data;
        struct node*next;
    };
    
    struct node*head;
    head=NULL  ;// ar initially
    int choice;
    
    struct node *newnode;
    struct node *temp;
    int count=0;
    
    do{
    newnode=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter your data%d:",count);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
        
    }
    
    printf("Do you want to continue\n 1.yes\n 0.exit :");
    scanf("%d",&choice);
     count++;  
    }
    
    while(choice==1);
    
    
    printf("now disply function:\n");
    temp=head;
    while(temp!=NULL){
        
        printf("%d\t",temp->data);
        temp=temp->next;
    }


    
    return 0;
}

