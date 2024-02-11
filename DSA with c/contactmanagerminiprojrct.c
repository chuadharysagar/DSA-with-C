#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phoneNumber[15];
    char email[50];
    struct Contact* next;
} Contact;
Contact* createContact(char name[], char phoneNumber[], char email[]) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (newContact) {
        strcpy(newContact->name, name);
        strcpy(newContact->phoneNumber, phoneNumber);
        strcpy(newContact->email, email);
        newContact->next = NULL;
    }
    return newContact;
}
void addContact(Contact** head, char name[], char phoneNumber[], char email[]) {
    Contact* newContact = createContact(name, phoneNumber, email);
    if (newContact) {
        newContact->next = *head;
        *head = newContact;
        printf("Contact added successfully.\n");
    } else {
        printf("Failed to add contact. Memory allocation error.\n");
    }}
void deleteContact(Contact** head, char name[]) {
    Contact* current = *head;
    Contact* previous = NULL;
    while (current && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current) {
        if (!previous)
            *head = current->next;
        else
            previous->next = current->next;
        free(current);
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }}
void searchContact(Contact* head, char name[]) {
    while (head && strcmp(head->name, name) != 0)
        head = head->next;
    if (head) {
        printf("Contact found:\nName: %s\nPhone Number: %s\nEmail: %s\n",
               head->name, head->phoneNumber, head->email);
    } else {
        printf("Contact not found.\n");
    }}
void displayContacts(Contact* head) {
    while (head) {
        printf("Name: %s\nPhone Number: %s\nEmail: %s\n\n", head->name,
               head->phoneNumber, head->email);
        head = head->next;
    }}
void freeContacts(Contact* head) {
    while (head) {
        Contact* next = head->next;
        free(head);
        head = next;
    }}
int main() {
    Contact* contacts = NULL;
    int choice;
    char name[50];
    char phoneNumber[15];
    char email[50];
    do {
        printf("\nContact Management System\n1. Add Contact\n2. Delete Contact\n3. Search Contact\n4. Display Contacts\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter contact details:\nName: ");
                scanf("%s", name);
                printf("Phone Number: ");
                scanf("%s", phoneNumber);
                printf("Email: ");
                scanf("%s", email);

                addContact(&contacts, name, phoneNumber, email);
                break;
            case 2:
                printf("Enter the name of the contact to delete: ");
                scanf("%s", name);
                deleteContact(&contacts, name);
                break;
            case 3:
                printf("Enter the name of the contact to search: ");
                scanf("%s", name);
                searchContact(contacts, name);
                break;
            case 4:
                displayContacts(contacts);
                break;
            case 5:
                freeContacts(contacts);
                printf("Exiting the Contact Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;}

