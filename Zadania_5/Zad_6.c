#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do wstawiania elementu na konkretny indeks
void insert_at_index(struct Node** head_ref, int index, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        free(new_node); // Jeśli indeks jest poza zakresem
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Funkcja pomocnicza do dodawania elementów na koniec listy (do testów)
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

// Funkcja pomocnicza do drukowania listy (do testów)
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Lista przed wstawieniem elementu o wartości 5 na indeks 2:\n");
    printList(head);

    insert_at_index(&head, 2, 5);

    printf("Lista po wstawieniu elementu o wartości 5 na indeks 2:\n");
    printList(head);

    return 0;
}
