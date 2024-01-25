#include<stdio.h>

void swap(int * a, int * b);
void insertion_sort(int arr[], int lenght);
void print_array(int arr[], int lenght);

int main() {

    int arr[] = {6, 5, 0, 1, 3, 2, 4, 8, 7};
    int size = sizeof(arr)/sizeof(int);

    insertion_sort(arr, size);

    return 0;
}

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int arr[], int lenght) {

    printf("arr => ");
    print_array(arr, lenght);
    printf("\n");
    printf("size = %d\n", lenght);

    int temp;

    for (int i = 0; i < lenght-1; i++) {

        for (int j = i+1; j > 0 && arr[j] < arr[j-1]; j--) {
            swap(&arr[j], &arr[j-1]);
        }

        print_array(arr, lenght);
        printf("\n");
    
    }
}

void print_array(int arr[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        printf("%d ", arr[i]);
    }
    
}