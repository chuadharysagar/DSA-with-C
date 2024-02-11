#include<stdio.h>
#include<stdlib.h>

#define maxsize 10
int arr[maxsize];
void Create_array(int arr[],int n){
	printf("Enter %d element:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("array sucessfully created\n");
}

void BubbleSort(int arr[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
           if(arr[j]>arr[j+1]){
               int t=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=t;
               flag=1;
           }
           }
           if(flag==0){
               printf("\nthe array is alreay sorted\n");
               break;
        }}}

void Display(int arr[],int n){
  printf("\nthe array elements  are:\n");
 for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

int main(){
int size;
 printf("enter the size of the array:");
scanf("%d",&size);
    Create_array(arr,size);
    printf("\nBubble sorting the array\n");
    BubbleSort(arr,size);
  
    Display(arr,size);
    return 0;}
