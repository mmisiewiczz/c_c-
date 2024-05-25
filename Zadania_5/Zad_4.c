#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do usuwania elementu z listy na podstawie indeksu
void remove_by_index(struct Node** head_ref, int index) {
    if (*head_ref == NULL) return; // Jeśli lista jest pusta, nic nie robimy

    struct Node* temp = *head_ref;

    if (index == 0) {
        *head_ref = temp->next; // Zmieniamy nagłówek
        free(temp); // Usuwamy stary nagłówek
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return; // Jeśli indeks jest poza zakresem

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
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

    printf("Lista przed usunięciem elementu o indeksie 2:\n");
    printList(head);

    remove_by_index(&head, 2);

    printf("Lista po usunięciu elementu o indeksie 2:\n");
    printList(head);

    return 0;
}
