

#include <stdio.h>

int main()
{
    printf("insertion operation in c");
int a[50],num,pos,size;

printf("enter your array size:");
scanf("%d",&size);

printf("enter your array elements:\n");
for(int i=0;i<size;i++){
    
    scanf("%d",&a[i]);
}

   for(int i=0;i<size;i++){
    
    printf("%d\t",a[i]);
}
 
printf("\nenter your element to be inserted in array:");
scanf("%d",&num);

printf("enter your elemnt index:");
scanf("%d",&pos);

for(int i=size-1;i>=pos-1;i--){
    a[i+1]=a[i];
    
}
a[pos-1]=num;
size++;
    
 for(int i=0;i<size;i++){
    printf("%d\t",a[i]);
}  

    return 0;
}

