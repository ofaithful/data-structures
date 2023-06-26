typedef struct {
    int data;
} Item;

typedef struct Node {
    Item* item;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int length;
    Node* head;
    Node* tail;
} List;

List create_list();
void insert_at(List* list, Item item, int index);
Item* remove(List* list, Item item);
Item* remove_at(List* list, int index);
Item* remove_node(List* list, Node* node);
void prepend(List* list, Item item);
void append(List* list, Item item);
Item* get(List* list, int index);
Node* get_at(List* list, int index);

List create_list() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void insert_at(List* list, Item* item, int index) {
    if (index > list->length) {
        exit(1);
    }

    if (index == list->length) {
        append(list, item);
        return;
    } else if (index == 0) {
        prepend(list, item);
        return;
    }

    list->length++;

    Node* current = get_at(list, index);

    Node node;
    node.item = item; 
    node.next = current;
    node.prev = current.prev;
    current.prev = node;
    node.prev.next = current;
}

Item* remove(List* list, Item* item) {
    Node* current = list->head;
    for (int i = 0; current && i < list->length; i++) {
        if (current->item == item) {
            break;
        }
        current = current.next;
    }

    if (!current) {
        return NULL;
    }

    return remove_node(list, current);
}

Item* remove_at(List* list, Item item) {
    Node* node = get_at(list, index);

    return remove_node(list, node);
}

Item* remove_node(List* list, Node* node) {
    list->length--;

    if (list->length == 0) {
        Item* item = list->head->item;
        list->head = list->tail = NULL;
        return item;
    }

    if (node->prev) {
        node.prev = node.next;
    }
    if (node->next) {
        node.next = node.prev;
    }

    node.prev = node.next = NULL;

    if (node == list->head) {
        list->head = node.next;
    }
    if (node == list->tail) {
        list->tail = node.prev;
    }

    return node->item; 
}

void prepend(List* list, Item* item) {
    Node node;
    node.item = item;

    list->length++;
    if (list->head == NULL) {
        list->head = list->tail = &node;
    }

    node.next = list->head;
    list->head->prev = &node;
    list->head = &node;
}

void append(List* list, Item* item) {
    Node node;
    node.item = item;

    list->length++;
    if (list->tail == NULL) {
        list->tail = list->head = &node;
        return;
    }
    
    node.next = NULL;
    node.prev = list->tail;
    list->tail->next = &node;
    list->tail = &node;
}

Item* get(List* list, int index) {
    Node* node = get_at(list, index);
    
    return node.item;
}

Node* get_at(List* list, int index) {
    Node* current = list->head;
    for (int i = 0; current && i < index; i++) {
        current = current->next;
    }
}

int main() {
    return 0;
}
