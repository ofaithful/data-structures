#include <stdio.h>
#include <stdlib.h>

// typedef struct {
//     int value;
// } node;

typedef enum {
    type_pointer,
    type_int,
    type_float,
    type_dobule,
    type_long
} DataType;

typedef struct node {
    DataType t;
    union {
        void* pointer;
        int i;
        float f;
        double d;
        long l;
    } data;
    struct node *next;
} Node;

typedef struct {
    Node* nodes;    // array to store nodes
    int capacity;   // max capacity of the queue
    int size;       // current size of the queue
    Node *head;
    Node *tail;
} Queue;

Queue* create_queue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->nodes = (Node*) malloc(capacity * sizeof(Node));
    queue->capacity = capacity;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}


void enqueue(Queue* queue, Node node) {
    queue->size++;

    if (queue->tail == NULL) {
        queue->tail = queue->head = &node;
        return;
    }

    queue->tail->next = &node;
    queue->tail = &node;
    printf("queue head: %d\n", queue->head->data.i);
}

Node dequeue(Queue* queue) {
    if (queue->head == NULL) {
        Node null_node = {0};
        return null_node;    
    }

    queue->size--;

    Node* head = queue->head;
    queue->head = queue->head->next;

    // free

    head->next = NULL;
    
    return *head;
}

Node peek(Queue* queue) {
    return *(queue->head);
}

int main() {
    Queue* queue = create_queue(10);
    Node nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i].t = type_int;
        nodes[i].data.i = (i + 1) * 100;
        enqueue(queue, nodes[i]);
        // printf("Queued node(%d):\n\ttype: %d\n\tvalue: %d\n", i, nodes[i].t, nodes[i].data.i);
    }

    while (queue->head != NULL) {
        Node node = dequeue(queue);
        printf("Dequeued node:\n\ttype: %d\n\tvalue: %d\n", node.t, node.data.i);
    }

    free(queue->nodes);
    free(queue);

    return 0;
}
