#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	
};

struct node*front=NULL;
struct node*rear=NULL;
struct node*newnode;
struct node*temp;

void enqueqe(){
	newnode=(struct node*)(malloc(sizeof(struct node)));
	printf("enter your data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	
	if(front==NULL && rear==NULL){
		temp=front=rear=newnode;
	}
	else{
		rear=rear->next;
		rear=newnode;	
	}
	printf("element eqquiped in Q\n");	
}



void Dequeqe(){
	int itm;
	if(front==NULL && rear==NULL){
	   printf("the Q is empty\n");
	}
	else{
		itm=temp=front;
		front=temp->next;
		free(temp);
		printf("the dequped data is %d",itm->data);
		
		
	}	
}


void Display(){
	if(front==NULL && rear==NULL){
	   printf("the Q is empty\n");
	}
	else{
		printf("the elements are:\n");
		temp=front;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}	
		
	}	
}

int main(){
	int op;
	while(op!=4){
	printf("\nyour choice are:\n1.enqueqe()\n2.Dequeqe()\n3.Display()\n4.Exit()\nEnter your choice:");
	scanf("%d",op);
	switch(op){
		case 1:
			enqueqe();
			break;
		case 2:
		     Dequeqe();
			 break;
	    case 3:
		     Display();
			 break;
	    case 4:
		    printf("Exit() from the program\n");
			break;
		default:
		   printf("Please enter valied option\n");			 		 	
		
	}
	
}
	return 0;
}


