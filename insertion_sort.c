#include<stdio.h>

void insertion_sort(int arr[], int lenght);
void print_array(int arr[], int lenght);

int main() {

    int arr[] = {6, 5, 0, 1, 3, 2, 4, 8, 7};
    int size = sizeof(arr)/sizeof(int);

    insertion_sort(arr, size);

    return 0;
}

void insertion_sort(int arr[], int lenght) {

    printf("arr => ");
    print_array(arr, lenght);
    printf("\n");
    printf("size = %d\n", lenght);

    int temp;

    for (int i = 1; i < lenght-1; i++) {
    
        temp = arr[i-1];

        for (int j = i-1; j >= 0 && arr[j] > temp ; j--) {
            arr[j+1] = arr[j];
        }
        arr[i] = temp;
        print_array(arr, lenght);
        printf("\n");
    }
    
}

void print_array(int arr[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        printf("%d ", arr[i]);
    }
    
}