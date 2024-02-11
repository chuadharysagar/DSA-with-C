#include <stdio.h>

// Size of the hash table
#define SIZE 10

// Hash table using quadratic probing
int hashTable[SIZE];

// Function to initialize the hash table
void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 indicates an empty slot
    }
}

// Function to probe for the next available slot using quadratic probing
int quadraticProbe(int index, int i) {
    return (index + i*i) % SIZE;
}

// Function to insert a key into the hash table using quadratic probing
void insertQuadraticProbing(int key) {
    int index = key % SIZE;

    // If the slot is empty, insert the key
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        // If the slot is occupied, probe for the next available slot using quadratic probing
        int i = 1;
        while (hashTable[quadraticProbe(index, i)] != -1) {
            i++;
        }
        hashTable[quadraticProbe(index, i)] = key;
    }
}

// Function to search for a key in the hash table using quadratic probing
int searchQuadraticProbing(int key) {
    int index = key % SIZE;

    // If the initial slot contains the key, return the index
    if (hashTable[index] == key) {
        return index;
    }

    // If the initial slot is empty, the key is not present
    if (hashTable[index] == -1) {
        return -1;
    }

    // If the initial slot is occupied, probe for the next slots using quadratic probing
    int i = 1;
    while (hashTable[quadraticProbe(index, i)] != -1 && hashTable[quadraticProbe(index, i)] != key) {
        i++;
    }

    // If the key is found, return the index; otherwise, return -1
    if (hashTable[quadraticProbe(index, i)] == key) {
        return quadraticProbe(index, i);
    } else {
        return -1;
    }
}

// Function to display the contents of the hash table
void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    // Initialize the hash table
    initializeHashTable();

    // Insert elements into the hash table
    insertQuadraticProbing(12);
    insertQuadraticProbing(22);
    insertQuadraticProbing(7);
    insertQuadraticProbing(42);
    insertQuadraticProbing(17);

    // Display the hash table
    displayHashTable();

    // Search for a key
    int keyToSearch = 42;
    int searchResult = searchQuadraticProbing(keyToSearch);
    if (searchResult != -1) {
        printf("Key %d found at index %d\n", keyToSearch, searchResult);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }

    return 0;
}

