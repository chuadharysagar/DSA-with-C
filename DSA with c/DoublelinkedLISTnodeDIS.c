#include <stdio.h>
#include<stdlib.h>


struct node{
  int data;
  struct node*prev;
  struct node*next;
};

struct node *head;
struct node *temp;
struct node* newnode;

void Createnode(){
    int size;
    printf("enter how many nodes you want to create :");
    scanf("%d",&size);
    
    for (int i=0;i<size;i++){
        newnode=(struct node *)(malloc(sizeof(struct node)));
        printf("enter your data %d: ",i);
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        
        
        if(head== NULL){
            head=temp=newnode;
        }
        else{
           temp->next=newnode;
           newnode->prev=temp;
           temp=newnode;
        }
    }
    printf("node created sucessfull !!\n");
}

void Display(){
    temp=head;
    int chose;
    printf("1.Forward Display\n2.Reverse Display\nEnter choice:");
    scanf("%d",&chose);
    
    switch(chose){
        case 1:
          while(temp!=0){
              printf("%d\t",temp->data);
              temp=temp->next;}
              
              break;

        case 2:
          while(temp->next!=NULL){
              temp=temp->next;}
             while(temp!=NULL){
                 printf("%d\t",temp->data);
                 temp=temp->prev;
             }
             break;
        default:
          printf("\nenter valid option!!\n");
     }
}
 
 
 


int main(){
    printf("Doubly linked list ...operation\n");
    Createnode();
    Display();
    
    return 0;
	}














