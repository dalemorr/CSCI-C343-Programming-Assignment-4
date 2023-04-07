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
        if (it.first == key) {
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
        if (it->first == key) {
            it = table[hashCode].erase(it);
            size--;
        }
    }
}

void HashMap::readFromFile(const std::string& filename, HashMap& hm) {
    std::ifstream file(filename);
    int dataSize;

    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latDeg;
    int latMin;
    int latSec;
    std::string latDir;
    int lonDeg;
    int lonMin;
    int lonSec;
    std::string lonDir;
    int altitude;

    if (!file) {
        std::cout << "Unable to open file";
        exit(1);
    }

    if (file.is_open()) {
        file >> dataSize;
        for (int i = 0; i < dataSize; i++) {
            file >> code;
            file >> name;
            file >> city;
            file >> country;
            file >> latDeg;
            file >> latMin;
            file >> latSec;
            file >> latDir;
            file >> lonDeg;
            file >> lonMin;
            file >> lonSec;
            file >> lonDir;
            file >> altitude;

            hm.put(code, AirportRecord(code, name, city, country, latDeg, latMin, latSec, latDir, lonDeg, lonMin, lonSec, lonDir, altitude));
        }
        file.close();
    }
}

void HashMap::writeToFile(const std::string& filename, HashMap& hm) {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << hm.toString();
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
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

            std::cout << "This works too" << std::endl;
            outputStream << "<" << it->first << ", ";

            std::cout << "But does this work?" << std::endl;

            outputStream << it->second.toString() << ">";
            std::cout << "This additionally works" << std::endl;
        }
    }

    return outputStream.str();
}
