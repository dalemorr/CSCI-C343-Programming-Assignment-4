#include "HashMap.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include "AirportRecord.h"

typedef std::pair<std::string, AirportRecord> Entry;

HashMap::HashMap(int buckets) {
    table = new std::list<Entry>;
    this->buckets = buckets;
}

HashMap::~HashMap() {
    delete table;
}

int HashMap::hash(std::string key) {
    int hashCode = 0;

    int primeToPower = 1;
    int i = 0;
    while (key[i]) {
        hashCode += primeToPower * key[i];
        primeToPower *= PRIME;
        i++;
    }

    hashCode %= buckets;
    return hashCode;
}

AirportRecord HashMap::get(std::string key) {
    int hashCode = hash(key);

    for (auto & it : table[hashCode]) {
        if (std::get<0>(it) == key) {
            return std::get<1>(it);
        }
    }
}

void HashMap::put(std::string key, AirportRecord value) {
    auto *entry = new Entry(key, value);
    table[hash(key)].push_back(*entry);
    size++;
}

void HashMap::remove(std::string key) {
    int hashCode = hash(key);

    for (auto it = table[hashCode].begin(); it != table[hashCode].end(); it++) {
        if (std::get<0>(*it) == key) {
            it = table[hashCode].erase(it);
            size--;
        }
    }
}

void readFromFile(const std::string& filename, HashMap& hm) {
    std::ifstream file(filename);
    std::string line;

    /*while (std::getline(file, line)) {
        std::stringstream
    }*/
}

int HashMap::getSize() {
    return size;
}

std::string HashMap::toString() {
    std::stringstream outputStream;

    for (int i = 0; i < buckets; i++) {
        if (i > 0) {
            outputStream << std::endl;
        }

        for (auto it = table[i].begin(); it != table[i].end(); it++) {
            if (it != table[i].begin()) {
                outputStream << ", ";
            }

            outputStream << "<" << std::get<0>(*it) << ", " << std::get<1>(*it).toString() << ">";
        }
    }

    return outputStream.str();
}
