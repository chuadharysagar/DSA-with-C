#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *newnode;
struct node *head;
struct node *temp;
struct node *prevnode;
int size;
int pos;

void createnode(){
	printf("enter how many node do you want create:");
	scanf("%d",&size);
	
	for(int i=1;i<=size;i++){
	newnode=(struct node*)(malloc(sizeof(struct node)));
	
	printf("enter your data%d:",i);
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
	}
	
	
	
	void display(){
		temp=head;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	
	
	void insert(){
		
		printf("enter your index:");
		scanf("%d",&pos);
		
		if(pos>size){
			printf("invalid position !!");
		}
	    else{
	    	temp=head;
	    	newnode=(struct node*)(malloc(sizeof(struct node)));
	    	printf("enter your data:");
	    	scanf("%d",&newnode->data);
	    	for(int i=1;i<pos;i++){
	    		temp=temp->next;
			}
			newnode->next=temp->next;
	    		temp->next=newnode;
		}	
	   printf("sucessfully inserted the element:\n");
	}
	
	void deletenode(){
		printf("enter the position for deletion:");
		scanf("%d",&pos);
		
		if(head==0){
			printf("empty List !!");
		}
		else{
			if(pos==1){
				temp=head;
				head=head->next;
				free(temp);
			}
			else if(pos==size){
				temp=head;
				while(temp->next!=NULL){
					prevnode=temp;
					temp=temp->next;
					}
					prevnode->next=NULL;
					free(temp);
				}
			else{
				temp=head;
				for(int i=1;i<=pos;i++){
					prevnode=temp;
					temp=temp->next;	
				}
				prevnode->next=temp->next;
				free(temp);
				
			}	
		}
		
	printf("sucessfully deleted node\n");	
	}
	
	
	
	int main(){
		
		int choice;
		int op;
		do{
		printf("\nyour choices are \n1.CreateNode\n2.Display\n3.Insertion\n4.DeleteNode\n5.Exit()\nEnter your option:");
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				createnode();
				break;
				
		    case 2:
			    display();
				break;
				
		    case 3:
			    insert();
				break;
				
			case 4:
			    deletenode();
				break;	
		    case 5:
		    	break;
		    	
			default:
				printf("enter valied option!");
		}
	} while(op!=5);
		
		return 0;
	}
