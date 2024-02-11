#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*head;
struct node*tail;
struct node*temp;
struct node *newnode;

void enqueue(){
    newnode=(struct node*)(malloc(sizeof(struct node)));
    printf("enter your data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(head==NULL && tail==NULL){
        temp=head=tail=newnode;
    }
    else{
        
        temp->next=newnode;
        temp=newnode;
        tail=newnode;
    }
    printf("data enqueued \n");
    
}

void Dqueue(){
    int itm;
    if(head==tail){
        head=NULL;
        tail=NULL;
	   
	}
	else if(head==NULL && tail==NULL){
	    
	    printf("the Q is empty\n");
	}
	else{
    temp=head;
    itm=head->data;
    head=head->next;
	free(temp);
    printf("deleted data %d",itm);
	}
    
}

void display(){
		temp=head;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
int main(){
    int op;
    while(op!=4){
    printf("\nyour choices are\n1.enqueue()\n2.Dqueue()\n3.display()\n4.exit()\nenter your choice:");
    scanf("%d",&op);
    
    switch(op){
        case 1:
          enqueue();
          break;
        case 2:
           Dqueue();
           break;
        case 3:
           display();
           break;
        case 4: 
             printf("exit()\n");
             break;
        default:
           printf("enter valid option\n");
        
    }
    }
    
    
    
    
    return 0;
}

