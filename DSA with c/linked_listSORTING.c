#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
	
};

struct node *newnode;
struct node *head;
struct node *temp;
struct node*nextnode;
struct node *prevnode;
int size;



void Createnode(){
        newnode=(struct node *)(malloc(sizeof(struct node)));
	    printf("enter your data:");
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
	
	
	
	
void Getlenght(){
    int count=0;
    temp=head;
    while(temp!=0){
        temp=temp->next;
        count++;
        
    }
    printf("The lenght of the list is %d",count);
}


void Sort_list(){
    struct node *current;
    struct node *p2;
    int t;
    p2=current=temp=head;
    while(temp->next!=NULL){
            current=p2=head;
        while(current->next!=NULL){
        	current=p2->next;
        	if(p2->data>current->data){
            t=p2->data;
            p2->data=current->data;
            current->data=t;
       }
        	p2=p2->next;
		}
        temp=temp->next;
        
    }
    printf("the list is sorted\n");
}

void ReverseNode(){
    temp=nextnode=head;
    prevnode=NULL;
    
    while(temp!=NULL){
        nextnode=nextnode->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
        
    }
    head=prevnode;
    printf("Reversed sucesfull!!\n");
    Display();
}


	void Display(){
		temp=head;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}


int main(){
    
    int choice;
    do{
    printf("\nyour choices are:\n1.Createnode\n2.Getlenght\n3.ReverseNode\n4.Display\n5.Sort the list\n6.Exit()\nEnter your choice:");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
          Createnode();
          break;
          
        case 2:
          Getlenght();
          break;
        case 3:
          ReverseNode();
          break;
         case 4:
           Display();
           break;
           
           case 5:
               Sort_list();
               break;
           
         case 6:
            printf("exit from the program");
            break;
         default:
           printf("Please enter valied choice !!!\n");
    }
    
    }while(choice!=6);
    
 return 0;
}
