#include <stdio.h>
#include <stdlib.h>
// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};
// Size of the hash table
#define SIZE 10
// Hash table using separate chaining
struct Node* hashTable[SIZE];
// Function to initialize the hash table
void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}
// Function to insert a key into the hash table using separate chaining
void insertSeparateChaining(int key) {
    int index = key % SIZE;
   // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = key;
    newNode->next = NULL;
    // If the slot is empty, insert the new node
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // If the slot is not empty, add the new node to the front of the linked list
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }}

// Function to display the contents of the hash table
void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");}}

int main() {
    // Initialize the hash table
    initializeHashTable();

    // Insert elements into the hash table
    insertSeparateChaining(12);
    insertSeparateChaining(22);
    insertSeparateChaining(7);
    insertSeparateChaining(42);
    insertSeparateChaining(17);
    // Display the hash table
    displayHashTable();
    return 0;}

