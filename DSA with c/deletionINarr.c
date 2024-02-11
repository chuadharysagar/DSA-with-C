#include<stdio.h>

int main(){
	printf("Deletion operation in c\n");
int a[50],num,pos,size,item;

printf("enter your array size:");
scanf("%d",&size);

if(size<=0 || size>sizeof(a)/sizeof(int)){
	
	printf("invalid array size");
}
else{

printf("enter your array elements:\n");
for(int i=0;i<size;i++){
    
    scanf("%d",&a[i]);
}

   for(int i=0;i<size;i++){
    
    printf("%d\t",a[i]);
}
printf("enter your elemnt Position:");
scanf("%d",&pos);
item=a[pos-1];

for(int i=pos-1;i<size-1;i++){
	a[i]=a[i+1];
}
	size--;
printf("the deleted element from the array is %d",item);
printf("\n elements after deletion");
for (int i=0;i<size;i++){
	printf("%d\t",a[i]);
}}
	return 0;
}
