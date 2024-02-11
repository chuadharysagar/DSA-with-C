#include<stdio.h>
#define maxsize 10
int arr[maxsize];

void Display(int arr[],int n){
  printf("\nthe array elements  are:\n");
 for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);}}

void Create_array(int arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);}
    printf("array sucessfully created\n");}

void selection_sort(int arr[], int n){
    int min;
    int index;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(arr[j]<arr[j+1]){
            min=arr[j];
                index=j;}
            else{
                min=arr[j+1];
                index=j+1;}}
        
        arr[index]=arr[i];
        arr[i]=min;}}

int main(){
int size;
 printf("enter the size of the array:");
scanf("%d",&size);
    Create_array(arr,size);
    printf("\nBubble sorting the array\n");
    selection_sort(arr,size);
  
    Display(arr,size);
    return 0;}



