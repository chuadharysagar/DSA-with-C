#include<stdio.h>
#define maxsize 10
int arr[maxsize];

void Display(int arr[],int n){
  printf("The Sorted array elements  are:\n");
 for(int i=0;i<n;i++){
        printf("%d\t",arr[i]); }}

void Create_array(int arr[],int n){
	printf("enter %d number\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);}
    printf("Array sucessfully created\n");}

void Insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
       int temp=arr[i];
      int  j=i-1;
       while(j>=0 && arr[j]>temp){
           arr[j+1]=arr[j];
           j--;}
       arr[j+1]=temp;} }

int main(){
int size;
 printf("Enter the size of the array:");
scanf("%d",&size);
    Create_array(arr,size);
    printf("\Insertion sorting the array\n");
    Insertion_sort(arr,size);
    Display(arr,size);
    return 0;}



