#include <stdio.h>
void getUserInput(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);}}

void binarySort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;}}}}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;}
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;}}
return -1; // Element not found
}
void displayArray(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf(" %d\t", arr[i]);}
    printf("\n");}
    
int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    getUserInput(arr, size);
    int choice;
    while(choice!=3){
    printf("\nChoose operation:\n");
    printf("1. Sort the array\n");
    printf("2. Search for an element\n");
    printf("3.Exit()\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            binarySort(arr, size);
            displayArray(arr, size);
            break;
        case 2:
            printf("Enter the element you want to search: ");
            scanf("%d", &target);
            binarySort(arr, size);
            int result = binarySearch(arr, size, target);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found in the array.\n");
            }
            break;
        case 3:
          printf("Exit()\n");
          break;
        default:
            printf("Invalid choice.\n");}}
return 0;
}


