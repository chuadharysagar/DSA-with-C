#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int data;
    struct node*next;
}*tail;

struct node*head=NULL;
struct node*temp;
struct node*newnode;
struct node*tail;
int size;

void CreateCLL(){
    printf("Enter your listsize:");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data %d:",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        
        if(head==NULL){
            temp=head=newnode;
            temp->next=newnode;
            
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
    }printf("node Creation sucessfull\n");
}


void Insertbeg(){
    
    if(head==NULL){
        temp=head=newnode;
        temp->next=newnode;
    }
    else{temp=head;
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data :");
        scanf("%d",&newnode->data);
        newnode->next=temp;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        head=newnode;
        printf("insertion completed\n");
    }
   size++; 
}



void Display(){
	if(head==NULL){
	printf("\nthe list is empty\n");}
	else{
	
    temp=head;
    while(temp->next!=head){
        printf("%d\t",temp->data);
        temp=temp->next;
        }
	    printf("%d\t",temp->data);
	}
}






int main(){
    int op;
		do{
		printf("\nyour choices are \n1.CreateNode\n2.Display()\n3. Insertbeg()\n4.exit()\nEnter your option:");
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				CreateCLL();
				break;
				
		    case 2:
			    Display();
				break;
			case 3:
			     Insertbeg();
			     break;
		    case 4:
			     printf("Exit() from the program\n");     
			     break;
		    default:
				printf("enter valied option!");}
    }while(op!=4);
    
return 0;}

