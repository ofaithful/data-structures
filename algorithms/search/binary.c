#include <stdio.h>
#include <math.h>

int bs_list(int* array, size_t length, int needle);

int main() {
    int array[20];

    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    size_t length = sizeof(array) / sizeof(array[0]);

    printf("does array have value %d? - %d\n", 5, bs_list(array, length, 5));
    printf("does array have value %d? - %d\n", 15, bs_list(array, length, 15));
    printf("does array have value %d? - %d\n", 21, bs_list(array, length, 21));
    printf("does array have value %d? - %d\n", 9, bs_list(array, length, 9));
}

int bs_list(int* array, size_t length, int needle) {
    int low = 0;
    int high = length;
    do {
        int middle = floor(low + (high - low) / 2);
        int value = array[middle];

        if (value == needle)
            return 1;
        else if (value > needle)
            high = middle;
        else
            low = middle + 1;
    } while (low < high);

    return 0;
}