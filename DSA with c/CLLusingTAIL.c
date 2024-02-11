#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int data;
    struct node*next;
};

struct node*temp;
struct node*newnode;
struct node*tail=NULL;
struct node*prevnode;
int size;
int pos;

void CreateCLL(){
    printf("Enter your listsize:");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data %d:",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
            
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
    }printf("node Creation sucessfull\n");
}
 
 void DelLast(){
     if (tail==NULL){
         printf("the list is empty\n");
     }
     else{
         temp=tail->next;
         while(temp!=tail){
            prevnode=temp;
            temp=temp->next;
         }
         prevnode->next=tail->next;
         tail=prevnode;
         free(temp);
        printf("element is deleted \n");
        size--;
     }
     
     
 }
 
 
void Delbeg(){
    if(tail==NULL){
        printf("the lsit is empty\n");
    }
    else{
        temp=tail->next;
        tail->next=temp->next;
        free(temp);
    }
    size--;
    printf("deletion from the begning is completed\n");

}


void Delany(){
    if(tail==NULL){
        printf("the list is empty\n");
    }
    else{
    printf("enter the position for deletion:");
    scanf("%d",&pos);
    if(pos==1){
        Delbeg();
    }
    else if(pos==size){
        DelLast();
    }
    
    else{
    temp=tail->next;
    for(int i=1;i<pos;i++){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=temp->next;
    free(temp);
    printf("deleted from the list\n");
   
    }
        size--;
    }
}

void Insertbeg(){
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
            
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
        }
        size++;
    printf("inserted at begining\n");
    
    
}


void InsertLast(){
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
            
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    printf("inserted at last\n");
}


void Insertany(){
    printf("enter the position for insertion:");
    scanf("%d",&pos);
    if(pos==1){
       Insertbeg(); 
    }
    else if(pos==size){
       InsertLast();   
        
    }
    else{
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=tail->next;
        for(int i=1;i<pos-1;i++){
          
            temp=temp->next;
     }
        newnode->next=temp->next;
        temp->next=newnode;
        }
    printf("insertion completed\n");
}


void Display(){
	if(tail==NULL){
	printf("\nthe list is empty\n");}
	else{
	temp=tail->next;
    while(temp->next!=tail->next){
        printf("%d\t",temp->data);
        temp=temp->next;
        }
	    printf("%d\t",temp->data);
	}
}


int main(){
    int op;
		do{
		printf("\nyour choices are \n1.CreateNode\n2.Display()\n3.Delbeg()\n4.DelLast()\n5. Delany()\n6.Insertbeg()\n7.InsertLast()\n8.Insertany()\n9.exit()\nEnter your option:");
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				CreateCLL();
				break;
				
		    case 2:
			    Display();
				break;
			
			case 3:
			 Delbeg();
			 break;
			 case 4:
			    DelLast();
			    break;
			 case 5:
			    Delany();
			    break;
			case 6:
			    Insertbeg();
			    break;
			case 7:
			     InsertLast();
			     break;
			case 8:
			    Insertany();
			    break;
			     
		    case 9:
			     printf("Exit() from the program\n");     
			     break;
		    default:
				printf("enter valied option!\n");}
    }while(op!=9);
    
return 0;}

