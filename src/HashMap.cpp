#include "HashMap.h"
#include <string>
#include <sstream>
#include <iostream>
#include <tuple>
#include "Sequence.h"
#include "AirportRecord.h"

typedef std::tuple<std::string, AirportRecord> Entry;

HashMap::HashMap(int buckets) {
    table = new Sequence<Entry>;
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
    Entry *thisEntry;

    for (int i = 0, l = table[hashCode].length(); i < l; i++) {
        table[hashCode].entry(*thisEntry, i);

        if (std::get<0>(*thisEntry) == key) {
            return std::get<1>(*thisEntry);
        }
    }
}

void HashMap::put(std::string key, AirportRecord value) {
    Entry *entry = new Entry(key, value);
    table[hash(key)].add(*entry, table[hash(key)].length());
    size++;
}

void HashMap::remove(std::string key) {
    int hashCode = hash(key);
    Entry *thisEntry;

    for (int i = 0, l = table[hashCode].length(); i < l; i++) {
        table[hashCode].entry(*thisEntry, i);

        if (std::get<0>(*thisEntry) == key) {
            table[hashCode].remove(*thisEntry, i);
            size--;
        }
    }
}

int HashMap::getSize() {
    return size;
}

std::string HashMap::toString() {
    std::stringstream outputStream;
    Entry *thisEntry;

    for (int i = 0; i < buckets; i++) {
        if (i > 0) {
            outputStream << std::endl;
        }

        for (int j = 0; j < table[i].length(); j++) {
            if (j > 0) {
                outputStream << ", ";
            }

            table[i].entry(*thisEntry, j);
            outputStream << "<" << std::get<0>(*thisEntry) << ", " << std::get<1>(*thisEntry).toString() << ">";
        }
    }

    return outputStream.str();
}
