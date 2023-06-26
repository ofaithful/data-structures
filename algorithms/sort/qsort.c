void qsort(int* array, int low, int high);
int partition(int* array, int low, int high);

int partition(int* array, int low, int high) {
    int pivot = array[high];

    int index = low -1;

    for (int i = low; i < high; i++) {
        if (array[i] <= pivot) {
            index++;
            int tmp = array[i];
            array[i] = array[index];
            array[index] = tmp;
        }
    }

    index++;
    array[high] = array[index];
    array[index] = pivot;

    return index;
}

void qsort(int* array, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partition(array, low, high);

    qsort(array, low, pivotIndex - 1);
    qsort(array, pivotIndex + 1, high);
}
