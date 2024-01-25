#include<stdio.h>
#include<stdlib.h>
#include"sorting.h"

int main(int argc, char * argv[]) {

    int arr[argc-1];

    for (int i = 0; i < argc-1; i++) {
        
        arr[i] = atoi(argv[i+1]);
    
    }
    
    // printf("bubble_sort => ");
    // bubble_sort(arr, argc-1);
    // print_array(arr, argc-1);
    // printf("\n");
    // printf("selection_sort => ");
    // selection_sort(arr, argc-1);
    // print_array(arr, argc-1);
    // printf("\n");
    printf("insertion_sort => ");
    insertion_sort(arr, argc-1);
    print_array(arr, argc-1);
    printf("\n");

}