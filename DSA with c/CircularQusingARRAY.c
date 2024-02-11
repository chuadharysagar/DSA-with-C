#include<stdio.h>
# define size 5
int q[size];
int front =-1;
int rear=-1;
void enqueq(int data){
   if (front==-1 && rear==-1){
       front=rear=0;
       q[rear]=data;
   } 
   else if((rear+1)%size==front){
       printf("the list is full\n");
   }
   else{
       rear=(rear+1)%size;
       q[rear]=data;
   }
    printf("the element is quqed in the list\n");
    
}


void dequeqe(){
    if(front==-1 &&rear==-1){
        printf("the queqe is empty\n");
    }
    else if(front == rear){
        printf("the dequeqed element is %d",q[front]);
        front=rear=-1;
    }
    else{
        printf("the dequeqed element is %d",q[front]);
        front=(front+1)%size;
    }
    
}

void Display(){
    
    if(front==-1 &&rear==-1){
        printf("the queqe is empty\n");
    }
    else{
        int i=front;
        printf("the queue elements are:\n");
        while(i!=rear){
         
        printf("%d\t",q[i]);
       i=(i+1)%size;
            
        }printf("%d\t",q[rear]);
    }
    
}



int main(){
    int op;
    do{
    printf("\nyour choices are:\n1.enqueq()\n2.dequeqe()\n3.Display()\n4.exit()\nenter your choice:");
    scanf("%d",&op);
    
    switch(op){
        case 1:
           int data;
           printf("enter your data:");
           scanf("%d",&data);
           enqueq(data);
           break;
        case 2:
           dequeqe();
           break;
        case 3:
           Display();
           break;
        case 4:
          printf("exit from the program\n");
        default:
           printf("please enter the valid option\n");
        
    }
    }while(op!=4);
    
    return 0;
}
