#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int lb, int ub){
    int pivot= arr[lb];
    int start=lb;
    int end= ub;
    
    while(start<end){
        while(arr[start]<=pivot && start<ub){
            start++;
        }
    
        while(arr[end]>pivot){
            end--;
        }
    
        if(start<end){
            swap(&arr[start],&arr[end]);
        }
    }
    return start;
}

void Quicksort(int arr[],int lb, int ub){
    if(lb<ub){
        int loc= partition(arr,lb,ub);
        Quicksort(arr,lb,loc-1);
        Quicksort(arr,loc,ub);
    }
}

void Display(int arr[], int end){
    for(int i=0;i<=end;i++){
        printf("%d",arr[i]);
        if(i!=end){
            printf("\t");
        }
    }
}

int main()
{
    int arr[]={7,2,46,1,8,10,24,21,12};
    int length= 8;
    printf("%d\n",length);
    Quicksort(arr,0,length-1);
    Display(arr,length-1);

    return 0;
}

