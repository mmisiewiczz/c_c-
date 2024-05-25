#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;           // Wartość przechowywana przez węzeł
    struct Node* next;  // Wskaźnik na następny węzeł
};

// Funkcja dodająca nowy element na początek listy
void addFirst(struct Node** head_ref, int new_data) {
    // Tworzymy nowy węzeł
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Przypisujemy nowej wartości do nowego węzła
    new_node->data = new_data;
    
    // Ustawiamy wskaźnik next nowego węzła na obecny początek listy
    new_node->next = *head_ref;
    
    // Ustawiamy nowy węzeł jako początek listy
    *head_ref = new_node;
}

// Funkcja wyświetlająca zawartość listy
void printList(struct Node* node) {
    // Przechodzimy przez listę i wyświetlamy wartości kolejnych węzłów
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Inicjalizacja głównego wskaźnika na początek listy
    struct Node* head = NULL;
    
    // Dodawanie elementów na początek listy
    addFirst(&head, 3);
    addFirst(&head, 5);
    addFirst(&head, 7);
    
    // Wyświetlanie listy
    printList(head);
    
    return 0;
}