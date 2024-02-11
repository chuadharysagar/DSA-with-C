#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

// Function to initialize the hash table
void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 indicates an empty slot
    }
}
// Function to probe for the next available slot using linear probing
int linearProbe(int index, int i) {
    return (index + i) % SIZE;
}

// Function to insert a key into the hash table using linear probing
void insertLinearProbing(int key) {
    int index = key % SIZE;

    // If the slot is empty, insert the key
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        // If the slot is occupied, probe for the next available slot using linear probing
        int i = 1;
        while (hashTable[linearProbe(index, i)] != -1) {
            i++;
        }
        hashTable[linearProbe(index, i)] = key;
    }}

// Function to search for a key in the hash table using linear probing
int searchLinearProbing(int key) {
    int index = key % SIZE;
   // If the initial slot contains the key, return the index
    if (hashTable[index] == key) {
        return index;
    }
    // If the initial slot is empty, the key is not present
    if (hashTable[index] == -1) {
        return -1;
    }
    // If the initial slot is occupied, probe for the next slots
    int i = 1;
    while (hashTable[linearProbe(index, i)] != -1 && hashTable[linearProbe(index, i)] != key) {
        i++;
    }
   // If the key is found, return the index; otherwise, return -1
    if (hashTable[linearProbe(index, i)] == key) {
        return linearProbe(index, i);
    } else {
        return -1;
    }}
    
void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }}
int main() {
    // Initialize the hash table
    initializeHashTable();
    insertLinearProbing(12);
    insertLinearProbing(22);
    insertLinearProbing(7);
    insertLinearProbing(42);
    insertLinearProbing(17);
    displayHashTable();

    // Search for a key
    int keyToSearch = 42;
    int searchResult = searchLinearProbing(keyToSearch);
    if (searchResult != -1) {
        printf("Key %d found at index %d\n", keyToSearch, searchResult);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }
    return 0;}

