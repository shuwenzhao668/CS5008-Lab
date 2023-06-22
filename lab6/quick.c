#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != size -1){
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array: \n");
    int arr[size];
    int i;
    for (i = 0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr,size);

    quickSort(arr, 0, size-1);
    printf("Sorted array:");
    printArray(arr, size);

    return 0;
}