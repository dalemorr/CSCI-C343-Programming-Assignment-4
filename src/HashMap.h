#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <iostream>
#include <tuple>
#include "Sequence.h"
#include "AirportRecord.h"

typedef std::tuple<std::string, AirportRecord> Entry;

class HashMap {
private:
    Sequence<Entry> *table;
    const int PRIME = 41;
    int buckets;
    int size = 0;
    int hash(std::string key);
public:
    HashMap(int buckets);

    ~HashMap();

    AirportRecord get(std::string key);

    void put(std::string key, AirportRecord value);

    void remove(std::string key);

    int getSize();

    std::string toString();
};

#endif //HASHMAP_H
