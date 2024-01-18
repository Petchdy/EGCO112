#include<stdio.h>
#include<limits.h>

void swap(int * a, int * b);
void selection_sort(int arr[], int lenght);
void print_array(int arr[], int lenght);

int main () {

    int arr[] = {6, 5, 0, 1, 3, 2, 4, 8, 7};
    int size = sizeof(arr)/sizeof(int);

    selection_sort(arr, size);

    return 0;
}

void swap(int * a, int * b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int lenght) {

    int min;

    printf("arr => ");
    print_array(arr, lenght);
    printf("\n");
    printf("lenght = %d\n", lenght);

    for (int i = 0; i < lenght-1; i++) {
        min = INT_MAX;
        for (int j = i; j < lenght; j++) {
            if (arr[j] < min) {
                min = arr[j];
                swap(&arr[j], &arr[i]);
            }
        }
        print_array(arr, lenght);
        printf("\n");
    }
}

void print_array(int arr[], int lenght) {

    for (int i = 0; i < lenght; i++) {
        printf("%d ",arr[i]);
    }   

}