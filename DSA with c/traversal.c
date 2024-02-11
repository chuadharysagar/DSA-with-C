#include<stdio.h>


int main(){
	int a[50],size;
	
	printf("enter your array size:");
	scanf("%d",&size);
	printf("enter your elements of the array:");
	for (int i=0;i<size;i++){
		scanf("%d",&a[i]);
		
	}
	
	printf("the elements of the array are following:\n");
		
	for(int i=0;i<size;i++){
		printf("%d\t",a[i]);
		
	}
	
	
	return 0;
}
