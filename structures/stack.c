#include <stdlib.h>

typedef struct node {
    enum {
        POINTER,
        INT,
        DOUBLE,
        FLOAT,
        CHAR,
    } type;
    union {
        void* pointer;
        int i;
        float f;
        double d;
        char c;
    } data;
    struct node *previous;
} Node;

typedef struct {
    int length;
    Node* head;
} Stack;

Stack create_stack();
void stack_push(Stack* stack, Node node);
Node* stack_pop(Stack* stack);
Node* stack_peek();

Stack create_stack() {
    Stack stack;
    stack.length = 0;

    return stack;
}

Node* peek(Stack* stack) {
    if (stack->head) {
        return stack->head;
    }

    return NULL;
}

void stack_push(Stack* stack, Node node) {
    if (!stack->length) {
        stack->length++;
        stack->head = node;
        return;
    }

    node.previous = stack->head;
    stack->head = node;
}

Node* stack_pop(Stack* stack) {
    int length = max(0, stack->length - 1);
    if (!stack->length) {
        Node* head = stack->head;
        stack->head = NULL;
        return head;
    }
    
    Node* head = stack->head;
    stack->head = head->previous;
    
    // free

    return head;
}

int main() {
    return 0;
}
