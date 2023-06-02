#include <stdio.h>

int index_of(int* array, size_t length, int value);

int main() {
    int array[50];

    for (int i = 0; i < 50; i++) {
        array[i] = i * 2;
    }

    size_t length = sizeof(array) / sizeof(array[0]);

    printf("index_of(%d): %d\n", 5, index_of(array, length, 5));
    printf("index_of(%d): %d\n", 15, index_of(array, length, 15));
    printf("index_of(%d): %d\n", 4, index_of(array, length, 4));
    printf("index_of(%d): %d\n", 22, index_of(array, length, 22));
    printf("index_of(%d): %d\n", 34, index_of(array, length, 34));
    printf("index_of(%d): %d\n", 46, index_of(array, length, 46));
    printf("index_of(%d): %d\n", 27, index_of(array, length, 27));
    printf("index_of(%d): %d\n", 168, index_of(array, length, 168));
}

int index_of(int* array, size_t length, int value) {
    if (value > length)
        return -2;
    
    int position = -1;
    
    for (int i = 0; i < length; i++) {
        if (array[i] == value)
            position = i;
    }

    return position;
}
