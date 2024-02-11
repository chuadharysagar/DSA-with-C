#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
    
};
struct node*newnode;
struct node*temp;
struct node *top=NULL;

void push(int x){
    newnode=(struct node*)(malloc(sizeof(struct node)));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
    printf("data pushed to stack");
}

void pop(){
    int item;
    temp=top;
    if(top==NULL){
        printf("the stack is empty\n");
        
    }
    else{
        item=temp->data;
        top=temp->next;
        free(temp);
      printf("the deleted element from the stack is %d\n",item);   
    }
}

void Display(){
    temp=top;
    if(top==NULL){
        printf("the list is empty\n");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        }
}


void peek(){
    
    temp=top;
    if(top==NULL){
        printf("the satck is empty\n");
    }
    else{
        printf("the topmost element is %d",top->data);
    }
    
}

int main(){
    int num;
    int op;
    while(op!=5){
    printf("\nenter your:\n1.push()\n2.Display()\n3.pop()\n4.peek()\n5.exit()\nEnter your choice:");
    scanf("%d",&op);
    
       switch(op){
        case 1:
           printf("enter your data:");
           scanf("%d",&num);
           push(num);
           break;
        case 2:
            Display();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        
        case 5:
           printf("exit from the program\n");
           break;
        default:
           printf("please enter valid operation\n");
        }}
    return 0;
}



