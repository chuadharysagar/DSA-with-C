// Online C compiler to run C program online
#include <stdio.h>
void Quadratic(int arr[],int n, int tsize, int table[]){
    for(int i=0;i<n;i++){
    int key= arr[i]%tsize;
    
    if(table[key]==-1){
        table[key]=arr[i];
    }
    else{
       for(int j=0;j<tsize;j++){
          int fn =1+(j*j);
          if(table[fn]==-1){
             table[fn] =arr[i];
             break;
          }
       }    }
}
printf("after hashing the element\n");
for(int k=0;k<tsize;k++){
    printf("%d\t",table[k]);
}


}



int main() {
    int arr[]={2341,4234,2839,430,22,397,3920};
    int n=7;
    int tsize=7;
    int table[7];
    
    for(int i=0;i<tsize;i++){
        table[i]=-1;
    }
    Quadratic(arr,7,7,table);

    return 0;
}