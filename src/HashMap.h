#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <utility>
#include <list>
#include <iostream>
#include "AirportRecord.h"

typedef std::pair<std::string, AirportRecord> Entry;

class HashMap {
private:
    std::list<Entry> *table;
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

    static void readFromFile(const std::string& filename, HashMap& hm);

    static void writeToFile(const std::string& filename, HashMap& hm);

    std::string toString();
};

#endif // HASHMAP_H
