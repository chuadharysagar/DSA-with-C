#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *prev;
    struct node *next;
    
};

struct node*head=NULL;
struct node *temp;
struct node *prevnode;
struct node*nextnode=NULL;
struct node* newnode;
int size;
int pos;

void CreateNode(){
    printf("Enter your list size:");
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data %d:",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            temp=head=newnode;
            
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }printf("node Creation sucessfull\n");
}



void ForwardDis(){
	if(head==NULL){
	printf("\nthe list is empty\n");}
	else{
	
    temp=head;
    printf("Forward display \n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
        }}
}

void BackWardDis(){
	if(head==NULL){
	printf("\nthe list is empty\n");}
	else{
	temp=head;
    printf("Backward display \n");
    while(temp->next!=NULL){
        temp=temp->next;
        }
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->prev;}
    }
}

void InsertBeg(){
    newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data:");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
       if(head==NULL){
           printf("the list is empty\n");
       }
    else{
        temp=head;
        newnode->next=temp;
        temp->prev=newnode;
        head=newnode;
        
    }size++;
    printf("Insertion at beginning sucessfull\n");
    }
    

void InsertLast(){
    newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
       if(head==NULL){
           printf("the list is empty\n");
       }
    else{
        temp=head;
      while(temp->next!=NULL){
          temp=temp->next;
         }
         temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        size++;
    }printf("Insertion at Last sucessfull\n");
    }

void Anyinsert(){
    printf("enter the position to insert:");
    scanf("%d",&pos);
     
    if(pos>=size || pos<0){
        printf("insertion can- not be performed\n");
    }
    else if(pos==1){
        InsertBeg();
    }
    else if(pos==size){
        InsertLast();
    }
    else{
        newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data:");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
       if(head==NULL){
           printf("the list is empty\n");
       }
    else{
        temp=prevnode=head;
        
        for (int i=1;i<pos;i++){
            temp=temp->next;
            prevnode=temp->prev;
        }
        newnode->next=temp;
        newnode->prev=prevnode;
        prevnode->next=newnode;
        temp->prev=newnode;
        }}
        size++;
    printf("insertion completed\n");
}

void Delbeg(){
	if(head==NULL){
		printf("Empty list\n");
	}
	
	else{
		temp=head;
		head=temp->next;
		head->prev=NULL;
		free(temp);
		}
	printf("element deleted at begginig");
	size--;	
}



void delLast(){
	if(head==NULL){
		printf("Empty list\n");
	}
	
	else{
		temp=head;
		while(temp!=NULL){
			prevnode=temp->prev;
			temp=temp->next;
		}
		prevnode->next=NULL;
		temp->prev=NULL;
		free(temp);
			}
	printf("element deleted at Last\n");
	size--;	}

void AnyDelete() {
    int pos;
    printf("Enter the index to be deleted: ");
    scanf("%d", &pos);

    if (pos > size || pos <= 0) {
        printf("Deletion cannot be performed. Invalid index.\n");
    } else if (pos == 1) {
        Delbeg();
    } else if (pos == size) {
        delLast();
    } else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
        size--;

        printf("Deletion completed\n");
    }
}

//void Reverse(){
//	if(head==NULL){
//		printf("Can't reverse list is empty\n'");
//	}
//	else{
//	temp=head;
//	while(temp!=head){
//	    nextnode=temp->next;
//		temp->next=temp->prev;
//		temp->prev=nextnode;
//		temp=nextnode;		
//	}
//	head=temp;}
//	printf("the list is Revesred sucessfully\n");	
//}

int main(){
    int op;
		do{
		printf("\nyour choices are \n1.CreateNode\n2.ForwardDisplay\n3.BackwardDisplay\n4.Insert at beggining\n5.InsertLast()\n6.Insert at any position\n7.Delete at beggining\n8.Delete at last\n9.Delete at any position\n10.Reverse() the list\n11.exit()\nEnter your option:");
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				CreateNode();
				break;
				
		    case 2:
			    ForwardDis();
				break;
				
		    case 3:
			    BackWardDis();
				break;
				
			case 4:
			    InsertBeg();
				break;
			case 5:
			    InsertLast();
			    break;
		    case 6:
		        Anyinsert();
		    	break;
		    case 7:
		    	Delbeg();
		        break;
		    case 8:
		        delLast();
		        break;
		    case 9:
		        AnyDelete();
			    break;
			 case 10:
			 	 Reverse();
			     break;
			case 11:
			    break;
				printf("Exit() from the program\n");     
			     
		    default:
				printf("enter valied option!");}
    }while(op!=11);
    
return 0;}










