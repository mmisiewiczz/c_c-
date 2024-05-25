#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania pierwszego elementu z listy
void pop(struct Node** head_ref) {
    if (*head_ref == NULL) return; // Jeśli lista jest pusta, nic nie robimy

    struct Node* temp = *head_ref; // Zapisujemy wskaźnik do pierwszego elementu
    *head_ref = (*head_ref)->next; // Ustawiamy drugi element jako pierwszy
    free(temp); // Usuwamy stary pierwszy element
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

    printf("Lista przed usunięciem pierwszego elementu:\n");
    printList(head);

    pop(&head);

    printf("Lista po usunięciu pierwszego elementu:\n");
    printList(head);

    return 0;
}
