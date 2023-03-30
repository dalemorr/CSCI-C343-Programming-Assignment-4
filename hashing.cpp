//
// Created by thatd on 3/29/2023.
//

// Demonstrates a HashTable and operations.

#include <iostream>
using namespace std;
class HashEntry {
private:
    int key;
    int value;
public:
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }
    int getKey() {
        return key;
    }
    int getValue() {
        return value;
    }
};
const int TABLE_SIZE = 128;
class HashMap {
private:
    HashEntry **table;
public:
    HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    int get(int key) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->getValue();
    }

    void put(int key, int value) {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }
};

int main() {
    HashMap hm;
    hm.put(3, 23);
    hm.put(5, 2377);
    hm.put(9, 263);
    cout<<"Value of key = 3, is "<<hm.get(3)<<endl;
    hm.put(12, 230);
    cout<<"override an existing entry of (3, 23) with (3,123)" <<endl;
    hm.put(3, 123);
    cout<<"New value of key = 3, is "<<hm.get(3)<<endl;
}
