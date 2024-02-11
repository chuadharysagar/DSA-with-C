#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; 
    }}
int quadraticProbe(int index, int i) {
    return (index + i*i) % SIZE;}
// Function to insert a key into the hash table using quadratic probing
void insertQuadraticProbing(int key) {
    int index = key % SIZE;
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        // If the slot is occupied, probe for the next available slot using quadratic probing
        int i = 1;
        while (hashTable[quadraticProbe(index, i)] != -1) {
            i++;
        }
        hashTable[quadraticProbe(index, i)] = key;
    }}
int searchQuadraticProbing(int key) {
    int index = key % SIZE;
    if (hashTable[index] == key) {
        return index;   
    if (hashTable[index] == -1) {
        return -1;
    }
    // If the initial slot is occupied, probe for the next slots using quadratic probing
    int i = 1;
    while (hashTable[quadraticProbe(index, i)] != -1 && hashTable[quadraticProbe(index, i)] != key) {
        i++;
    }
    if (hashTable[quadraticProbe(index, i)] == key) {
        return quadraticProbe(index, i);
    } else {
        return -1;
    }}
void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }}

int main() {
    initializeHashTable();
    insertQuadraticProbing(12);
    insertQuadraticProbing(22);
    insertQuadraticProbing(7);
    insertQuadraticProbing(42);
    insertQuadraticProbing(17);
    displayHashTable();

    int keyToSearch = 42;
    int searchResult = searchQuadraticProbing(keyToSearch);
    if (searchResult != -1) {
        printf("Key %d found at index %d\n", keyToSearch, searchResult);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }
    return 0;}
 
