#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; 
    }}
int secondHash(int key) {
    return 7 - (key % 7);
}
int doubleHash(int index, int i, int key) {
    return (index + i * secondHash(key)) % SIZE;}
void insertDoubleHashing(int key) {
    int index = key % SIZE;
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = 1;
        while (hashTable[doubleHash(index, i, key)] != -1) {
            i++;
        }
        hashTable[doubleHash(index, i, key)] = key;
    }}
int searchDoubleHashing(int key) {
    int index = key % SIZE;
    if (hashTable[index] == key) {
        return index;
    }
    if (hashTable[index] == -1) {
        return -1;
    }
    int i = 1;
    while (hashTable[doubleHash(index, i, key)] != -1 && hashTable[doubleHash(index, i, key)] != key) {
        i++;
    }
    if (hashTable[doubleHash(index, i, key)] == key) {
        return doubleHash(index, i, key);
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
    insertDoubleHashing(120);
    insertDoubleHashing(212);
    insertDoubleHashing(73);
    insertDoubleHashing(4);
    insertDoubleHashing(173);
    
    displayHashTable();
    int keyToSearch = 4;
    int searchResult = searchDoubleHashing(keyToSearch);
    if (searchResult != -1) {
        printf("Key %d found at index %d\n", keyToSearch, searchResult);
    } else {
        printf("Key %d not found\n", keyToSearch);}
    return 0;}

