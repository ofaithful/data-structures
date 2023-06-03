#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} Item;

typedef struct {
    Item* items;    // array to store items
    int capacity;   // max capacity of the queue
    int size;       // current size of the queue
    int head;       // index of the front item
    int tail;       // index of the tail item
} Queue;

Queue* create_queue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->items = (Item*) malloc(capacity * sizeof(Item));
    queue->capacity = capacity;
    queue->size = 0;
    queue->head = -1;
    queue->tail = -1;

    return queue;
}

int is_empty(Queue* queue) {
    return queue->size == 0;
}

int is_full(Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue* queue, Item item) {
    if (is_full(queue)) {
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }

    if (queue->head == -1)
        queue->head = 0;

    queue->tail++;
    queue->items[queue->tail] = item;
    queue->size++;
}

Item dequeue(Queue* queue) {
    if (is_empty(queue)) {
        Item null_item = {0};
        return null_item;    
    }
    Item item = queue->items[queue->head];
    queue->head++;
    queue->size--;

    if (queue->head > queue->tail)
        queue->head = queue->tail = -1;

    return item;
}

void display(Queue* queue) {
    printf("Queue elements are:\n");
    for (int i = 0; i < queue->size; i++) {
        printf("{%d} ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = create_queue(10);
    Item items[10];

    for (int i = 0; i < 10; i++) {
        items[i].value = i * 10;
        enqueue(queue, items[i]);
    }

    display(queue);

    while (!is_empty(queue)) {
        Item item = dequeue(queue);
    }

    free(queue->items);
    free(queue);

    return 0;
}