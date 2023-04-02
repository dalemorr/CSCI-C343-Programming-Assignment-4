// Created by dalemorr on 3/29/2023.
//
// Demonstrates a HashTable and operations.

#include <iostream>
#include "HashMap.h"

HashEntry::HashEntry(int key, int value) {
    this->key = key;
    this->value = value;
}

int HashEntry::getKey() {
    return key;
}

int HashEntry::getValue() {
    return value;
}

HashMap::HashMap() {
    table = new HashEntry*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int HashMap::get(int key) {
    int hash = (key % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getKey() != key) {
        hash = (hash + 1) % TABLE_SIZE;
    }
    if (table[hash] == NULL) {
        return -1;
    } else {
        return table[hash]->getValue();
    }
}

void HashMap::put(int key, int value) {
    int hash = (key % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getKey() != key) {
        hash = (hash + 1) % TABLE_SIZE;
    }
    if (table[hash] != NULL) {
        delete table[hash];
    }
    table[hash] = new HashEntry(key, value);
}

HashMap::~HashMap() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            delete table[i];
        }
    }
    delete[] table;
}
