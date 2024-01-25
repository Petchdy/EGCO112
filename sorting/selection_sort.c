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

    int min, min_index, flag = 0;

    printf("arr => ");
    print_array(arr, lenght);
    printf("\n");
    printf("lenght = %d\n", lenght);

    for (int i = 0; i < lenght-1; i++) {
        min = arr[i];
        for (int j = i+1; j < lenght; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
                flag = 1;
            }
        }
        if (flag == 1) {
            swap(&arr[i], &arr[min_index]);
            flag = 0;
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