#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node*next;
    
};

struct node*head;
struct node*newnode;
struct node *temp;
int size;

void CreateNode(){
    printf("Enter your linked list size:");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
    newnode=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter your data%d:",i);
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        temp=head=newnode;
    }
    else{
        temp->next=newnode;
        newnode->next=head;
        temp=newnode;
    }}
    printf("Circular singly linked list is created sucesfully\n");
    
}
void Display(){
    if(head==NULL){
        printf("The List is Empty\n");
    }
    else{
        printf("The elements in linked list are:\n");
        temp=head;
        while(temp->next!=head){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    
    
}

int main(){
    int op;
    printf("Linked list operation are\n");
    while(op!=3){
        printf("\nyour choices are\n1.CreateNode()\n2.Display()\n3.Exit()\nEnter your choice:");
        scanf("%d",&op);
        switch(op){
            case 1:
              CreateNode();
              break;
            
            case 2:
              Display();
              break;
            case 3:
               printf("Exit() from program\n");
               break;
        }
        
    }
    return 0;
}
