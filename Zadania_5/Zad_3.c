#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania ostatniego elementu z listy
void remove_last(struct Node** head_ref) {
    if (*head_ref == NULL) return; // Jeśli lista jest pusta, nic nie robimy
    if ((*head_ref)->next == NULL) {
        free(*head_ref); // Jeśli lista ma tylko jeden element
        *head_ref = NULL;
        return;
    }

    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    free(second_last->next);
    second_last->next = NULL;
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

    printf("Lista przed usunięciem ostatniego elementu:\n");
    printList(head);

    remove_last(&head);

    printf("Lista po usunięciu ostatniego elementu:\n");
    printList(head);

    return 0;
}
