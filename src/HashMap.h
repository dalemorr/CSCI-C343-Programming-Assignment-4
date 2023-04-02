//
// Created by littl on 4/2/2023.
//

#ifndef CSCI_C343_PROGRAMMING_ASSIGNMENT_4_HASHMAP_H
#define CSCI_C343_PROGRAMMING_ASSIGNMENT_4_HASHMAP_H

#include <iostream>

class HashEntry {
private:
    int key;
    int value;
public:
    HashEntry(int key, int value);

    int getKey();

    int getValue();
};

const int TABLE_SIZE = 128;

class HashMap {
private:
    HashEntry **table;
public:
    HashMap();

    int get(int key);

    void put(int key, int value);

    ~HashMap();
};

#endif //CSCI_C343_PROGRAMMING_ASSIGNMENT_4_HASHMAP_H
