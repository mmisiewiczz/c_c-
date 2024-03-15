#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char first_name[50];
    char last_name[50];
    char phone_number[20];
} Contact;

Contact address_book[MAX_CONTACTS];
int num_contacts = 0;

void addContact(const char *first_name, const char *last_name, const char *phone_number) {
    if (num_contacts < MAX_CONTACTS) {
        strcpy(address_book[num_contacts].first_name, first_name);
        strcpy(address_book[num_contacts].last_name, last_name);
        strcpy(address_book[num_contacts].phone_number, phone_number);
        printf("Contact added successfully.\n");
        num_contacts++;
    } else {
        printf("Address book is full. Cannot add more contacts.\n");
    }
}

void searchContact(const char *last_name) {
    int found = 0;
    printf("Search results for '%s':\n", last_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(address_book[i].last_name, last_name) == 0) {
            printf("%s %s - %s\n", address_book[i].first_name, address_book[i].last_name, address_book[i].phone_number);
            found = 1;
        }
    }
    if (!found) {
        printf("No contacts found with last name '%s'.\n", last_name);
    }
}

void deleteContact(const char *last_name) {
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(address_book[i].last_name, last_name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                address_book[j] = address_book[j + 1];
            }
            num_contacts--;
            printf("Contact with last name '%s' deleted successfully.\n", last_name);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No contacts found with last name '%s'. Deletion failed.\n", last_name);
    }
}

void displayAllContacts() {
    printf("All contacts in the address book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s %s - %s\n", address_book[i].first_name, address_book[i].last_name, address_book[i].phone_number);
    }
}

int main() {
    char first_name[50], last_name[50], phone_number[20];
    char choice;

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter first name: ");
                scanf("%s", first_name);
                printf("Enter last name: ");
                scanf("%s", last_name);
                printf("Enter phone number: ");
                scanf("%s", phone_number);
                addContact(first_name, last_name, phone_number);
                break;
            case '2':
                printf("Enter last name to search: ");
                scanf("%s", last_name);
                searchContact(last_name);
                break;
            case '3':
                printf("Enter last name to delete: ");
                scanf("%s", last_name);
                deleteContact(last_name);
                break;
            case '4':
                displayAllContacts();
                break;
            case '5':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
