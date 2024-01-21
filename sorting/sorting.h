void swap(int * a, int * b);
void bubble_sort (int arr[], int lenght);
void insertion_sort(int arr[], int lenght);
void selection_sort(int arr[], int lenght);
void print_array(int arr[], int lenght);

void swap(int * a, int * b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort (int arr[], int lenght) {

    for (int i = 0; i < lenght-1; i++) {
        for (int j = i+1; j < lenght; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }

}

void insertion_sort(int arr[], int lenght) {

    int temp;

    for (int i = 0; i < lenght-1; i++) {

        for (int j = i+1; j > 0 && arr[j] < arr[j-1]; j--) {
            swap(&arr[j], &arr[j-1]);
        }
    
    }

}

void selection_sort(int arr[], int lenght) {

    int min;

    for (int i = 0; i < lenght-1; i++) {
        min = 32767;
        for (int j = i; j < lenght; j++) {
            if (arr[j] < min) {
                min = arr[j];
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

void print_array(int arr[], int lenght) {

    for (int i = 0; i < lenght; i++) {
        printf("%d ", arr[i]);
    }

}