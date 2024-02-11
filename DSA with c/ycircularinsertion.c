void Insertbeg(){
    newnode=(struct node*)(malloc(sizeof(struct node)));
        printf("Enter your data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(head==NULL){
        temp=head=newnode;
        temp->next=newnode;
    }
    else{
        newnode->next=temp->next;
        temp->next=newnode;
        printf("insertion completed\n");
    }
   size++; 
}
