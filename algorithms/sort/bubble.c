#include <stdio.h>

void bubble_sort(int* array, size_t length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
} 

int main() {
    int array[] = { 1, 6, 7, 3, 16, 4, 67, 12, 8, 2 };
    size_t length = sizeof(array) / sizeof(array[0]);

    printf("Init array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    
    bubble_sort(array, length);

    printf("\nSorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}