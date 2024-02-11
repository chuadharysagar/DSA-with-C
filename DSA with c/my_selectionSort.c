#include <stdio.h>
void Selection_sort(int arr[], int size){
      int min;
      for(int i=0;i<size;i++){
          min=i;
          for(int j=i;j<size-1;j++){
              if(arr[j+1]<arr[min]){
                  min=j+1;
              }}
          if(arr[i]>arr[min]){
              int t= arr[i];
              arr[i]=arr[min];
              arr[min]=t;}}
              
    printf("\nArray afer selection sort\n");
    for(int k=0;k<size;k++){
        printf("%d\t",arr[k]);
    }}

int main()
{
   int my_arr[]={-41,52,62,42,22,37,-10,12};
   int n= sizeof(my_arr)/sizeof(my_arr[0]);
   printf("before sorting the array\n");
   for(int k=0;k<n;k++){
        printf("%d\t",my_arr[k]);
    }
   Selection_sort(my_arr,n);

    return 0;}

