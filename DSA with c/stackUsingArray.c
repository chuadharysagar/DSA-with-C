#include<stdio.h>
#include<stdlib.h>

#define size 5

int stack[size];
int top=-1;

void push(){
    int num;
    printf("Enter your data:");
    scanf("%d",&num);
    if(top==size-1){
        printf("Overflow conditon\n");
    }
    else{
        top++;
        stack[top]=num;
         }
         printf("pushed the elemet\n");
}


void pop(){
    int item;
    if(top==-1){
        printf("underflow condition\n");
    }
    else{
        item=stack[top];
        top--;
    }
    printf("the deleted item is %d\n",item);
}

void peek(){
    if(top==-1){
        
        printf("Underflow condition\n");
    }
    else{
        printf("the topmost element in stack is %d\n",stack[top]);
    }
}


void Display(){
    printf("the elements are:\n");
    for(int i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
}

int main(){
    int op;
    do{
    printf("\nyour choices:\n1.push()\n2.pop()\n3.peek()\n4.Display()\n5.exit()\nEnter your choice:");
    scanf("%d",&op);
    
    switch(op){
        case 1:
         push();
         break;
        case 2:
          pop();
          break;
        case 3:
          peek();
          break;
        case 4:
          Display();
          break;
        case 5:
          printf("exit() from the program\n");
          break;
        
        default:
          printf("please enter valid option\n");
        }}while(op!=5);
    
    
    
    return 0;
}


