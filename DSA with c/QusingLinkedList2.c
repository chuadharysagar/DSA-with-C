#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node *newnode;
struct node*front=NULL;
struct node*rear=NULL;
struct node*temp;
void enqueqe(){
    newnode=(struct node*)(malloc(sizeof(struct node*)));
    newnode->next=NULL;
    printf("enter your data:");
    scanf("%d",&newnode->data);
    if(front==NULL && rear==NULL){
        front=rear=newnode;}
    else{
        rear->next=newnode;
        rear=newnode;}
    printf("data enqueqed\n");}

void Display(){
    if(front==NULL && rear==NULL){
         printf("the queque is empty\n");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }}}

void Dequeqe(){
     if(front==NULL){
         printf("the q is empty\n");
     }
    else if(front==NULL && rear==NULL){
         printf("the queque is empty\n");
    }
    else{
        temp=front;
		front=front->next;
		printf("the dequped data is %d",temp->data);
		free(temp);}}

void FRONT(){
    if(front==NULL && rear==NULL){
         printf("the queque is empty\n");
    }
    else{
        printf("the first element of the Queqe is %d\n",front->data);}}

void IsEmpty(){
    if(front==NULL && rear==NULL){
         printf("Yes,the queque is empty!!\n");
    }
    else{
        printf("the queue is not empty\n");}}

int main(){
    int op;
    int mynum;
    while(op!=6){
    printf("\nyour choicesare:\n1.enqueqe()\n2.Display()\n3.Dequeqe()\n4.FRONT()\n5.IsEmpty()\n6.Exit()\nEnter your choice:");
    scanf("%d",&op);
    switch(op){
        case 1:
           enqueqe();
           break;
        case 2:
           Display();
           break;
        case 3:
           Dequeqe();
           break;
        case 4:
           FRONT();
           break;
        case 5:
           IsEmpty();
           break;
        case 6:
            printf("exit from the program\n");
            break;
        default:
          printf("Please enter valied option\n");}}
    return 0;}



