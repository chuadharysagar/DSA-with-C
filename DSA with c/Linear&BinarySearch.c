#include<stdio.h>
#define maxsize 100
int size;
int arr[maxsize];

void CreateArray(){
	printf("Enter your array size:");
	scanf("%d",&size);
	if(size<0||size>maxsize){
	    printf("invalid array size enter between 1 to %d\n",maxsize);
	    return;
	}
	for(int i=0;i<size;i++){
		printf("data%d:",i);
		scanf("%d",&arr[i]);
	}
	printf("Araay sucessfully created\n");
}


int Display(int arr[],int size){
	printf("The array elements are:\n");
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
}


//linear search
int LinearSearch(int arr[],int target,int size){
    int found=0;
	for(int i=0;i<=size;i++){
		if(arr[i]==target){
			printf("the element %d is at %d index\n",target,i);
		}
		found=1;
		}
		
		if(!found){
		printf("target not found in array\n");}
    }
  //Binary search  
 void BinarySearch(int arr[],int size,int target){
        int low=0;
        int found=0;
        int high=size-1;
        int mid=low+high/2;
        while(low<=high){
            
            if(target==arr[mid]){
                printf("traget elemnt found at %d index\n",mid);
                found=1;
                break;
            }
            
            else if(target>arr[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(!found){
        printf("target element not found in array\n");
        }
    }
    
int Sortarray(int arr[],int size){
    int temp;
    for (int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
        if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }  
        }
    }
    printf("array is sorted succesfully\n");
}    
    




int main(){
	int choice;
    int target;
	printf("Linear search in Array\n");
	while(choice!=6){
	
	printf("\nYour choice are\n1.CreateArray()\n2.Display()\n3.LinearSearch()\n4.BinarySearch\n5.Sort array \n6.Exit()\nEnter your choice:");
	scanf("%d",&choice);
	
	
	switch(choice){
		case 1:
			CreateArray();
			break;
	    case 2:
		    Display(arr,size);
			break;
	    case 3:
	        printf("Enter your target Element:");
	        scanf("%d",&target);
		    LinearSearch(arr,target,size);
			break;
	    case 4:
	        printf("Enter your target Element:");
	        scanf("%d",&target);
	        Sortarray(arr,size);
	        BinarySearch(arr,size,target);
		    break;
		case 5:
		    Sortarray(arr,size);
		    break;
		    
		case 6:
		    printf("EXIT()\n");
		    break;
		    
		default:
		    printf("Please enter valid option\n");							
		}
}
	
	return 0;
}
