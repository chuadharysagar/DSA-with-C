// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>


int main(){
    struct node{
        int data;
        struct node*next;
     };
     struct node*head;
     struct node *newnode;
     struct node*temp;
     int nodeno;
     int pos,itm;
     int count=0;
     newnode=(struct node*)(malloc(sizeof(struct node)));
     
     printf("Enter how many nodes do tou want to create:");
     scanf("%d",&nodeno);
     
     for(int i=0;i<node;i++){
         printf("Enter your data %d:",i);
         scanf("%d",&newnode->data);
         newnode->next=NULL;
         
         if(head==NULL){
             head=temp=newnode;
              }
          else{
              temp->next=newnode;
              temp=newnode;
              }    
              
              }
        printf("enter your element to be inserted:");
        scanf("%d",&itm);
        printf("enter the position for inserting:");
        scanf("%d",&pos);
        
        if(pos>nodeno){
            printf("invalid insertion");
        }
        
        else{
            temp=head;
            while(temp!=NULL){
                temp=temp->next;
                count++;
                
            }
        }
        
        
    
    
    return 0;
}
