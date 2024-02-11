#include<stdio.h>
#define size 5
int Q[size];
int front;
int rear;
front =-1;
rear=-1;
int data;

void enqueqe(){
    if(rear>size-1){
        printf("the queue is full\n");}
    else{
        printf("Enter your data:");
        scanf("%d",&data);
        if(front==-1&&rear==-1){
            front++;
            rear++;
            Q[rear]=data;
            }
        else{
            rear++;
            Q[rear]=data;
        }}}
    
    void dequeqe(){
        if(front==-1&&rear==-1){
            printf("the Q is empty\n");
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            printf("the dqeued data is %d",Q[front]);
            front++;
        }}
    
    void Display(){
        if(front==-1&&rear==-1){
            printf("the Q is empty\n");
        }
        else{
          for (int i=front;i<=rear;i++){
              printf("%d\t",Q[i]);
          }} }
         
void Front(){
     if(front==-1&&rear==-1){
            printf("the Q is empty\n");
        }
    else{
        printf("the fornt element of the Queue is %d\n",Q[front]);
    }}
   
void Isfull(){
    if(rear==size-1){
        printf("the queue is full\n");
    }
    else{
        printf("the queue is not full\n");}}   

void Isempty(){
    if(front==-1&&rear==-1){
            printf("the Q is empty\n");
        }
    else{
        printf("the queue is not empty\n");}}    
int main(){
    int op;
    do{
    printf("\nyour choics are:\n1.enqueqe()\n2.dequeqe()\n3.Display()\n4.front()\n5.Isfull()\n6.Isempty()\n7.Exit()\nEnter your operation:");
    scanf("%d",&op);
    switch(op){
        case 1:
         enqueqe();
         break;
        case 2:
         dequeqe();
         break;
        case 3:
         Display();
         break;
        case 4:
          Front();
          break;
        case 5:
          Isfull();
          break;
        case 6:
           Isempty();
           break;
        case 7:
           printf("exit() from the program\n");
           break;
        default:
           printf("please Enter valid option\n");
    }
}while(op!=7);
 return 0;}




    
