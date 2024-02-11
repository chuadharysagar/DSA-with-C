#include <stdio.h>
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }}}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);    }
    printf("\n");}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
	int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);}
    printf("\nOriginal ");
    displayArray(arr, size);

    shellSort(arr, size);

    printf("Sorted ");
    displayArray(arr, size);
    return 0;}

