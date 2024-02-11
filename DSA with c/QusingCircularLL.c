#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    
};
struct node*front=NULL;
struct node*rear=NULL;
struct node*temp;
struct node*newnode;

void Enqueqe(){
    newnode=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter your data:");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    
    if(front==NULL && rear==NULL){
       front=rear=newnode;
       rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
        
    }
    printf("the %d elemet is inserted sucessfully\n",newnode->data);
    
}


void Dequeqe(){
    if(front==NULL){
       printf("the queqe is empty(Underflow condtion)\n");
    }
    else if(front==rear){
          printf("the deleted elemet is %d\n",front->data);
          front=NULL;
    }
    else{
        temp=front;
        front=front->next;
        printf("the deleted elemet is %d\n",temp->data);
        free(temp);
    }
}


void Display(){
    
    printf("your elemts are:\n");
    if(front==NULL && rear==NULL){
       printf("the queqe is empty(Underflow condtion)\n");
    }
    else{
        temp=front;
        while(temp!=rear){
            printf("%d\t",temp->data);
            temp=temp->next;
             }
             printf("%d\t",temp->data);
    }
}
    
int main(){
    int op;
    do{
    printf("\nyour choices are:\n1.Enqueqe()\n2.Dequeqe()\n3.Display()\n4.Exit()\nEnter your choice:");
    scanf("%d",&op);
    
    switch(op){
            case  1:
               Enqueqe();
               break;
            case 2:
               Dequeqe();
               break;
               
            case 3:
                Display();
                break;
            case 4:
              printf("exit from the program\n");
              break;
            default:
              printf("please enter valid option\n");
        
    }
    }while(op!=4);
    
    
    return 0;
}    
    
    
    
