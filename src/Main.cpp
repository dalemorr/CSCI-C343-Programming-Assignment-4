#include <string>
#include <iostream>
#include <fstream>
#include "AirportRecord.h"
#include "HashMap.h"

int main() {
    std::string infilename1 = "../data/air16.dat";
    std::string infilename2 = "../data/air128.dat";
    std::string outfilename1 = "../data/air16.txt";
    std::string outfilename2 = "../data/air128.txt";
    HashMap* hm;

    hm = new HashMap(5);
    HashMap::readFromFile(infilename1, *hm);
    HashMap::writeToFile(outfilename1, *hm);
    std::cout << "MAP 1:" << std::endl;
    std::cout << "i. " << std::endl << hm->toString() << std::endl;
    std::cout << "ii. " << hm->getSize() << std::endl;
    std::cout << "iii. " << hm->get("YWG").toString() << std::endl;
    std::cout << "iv. " << hm->get("CMB").toString() << std::endl;
    hm->remove("HND");
    std::cout << "v. " << "Removed record with key \"HND\"" << std::endl;
    std::cout << "vi. " << hm->getSize() << std::endl;
    std::cout << "vii. " << std::endl << hm->toString() << std::endl;

    std::cout << std::endl;

    hm = new HashMap(19);
    HashMap::readFromFile(infilename2, *hm);
    HashMap::writeToFile(outfilename2, *hm);
    std::cout << "MAP 2:" << std::endl;
    std::cout << "i. " << std::endl << hm->toString() << std::endl;
    std::cout << "ii. " << hm->getSize() << std::endl;
    std::cout << "iii. " << hm->get("YWG").toString() << std::endl;
    std::cout << "iv. " << hm->get("CMB").toString() << std::endl;
    hm->remove("HND");
    std::cout << "v. " << "Removed record with key \"HND\"" << std::endl;
    std::cout << "vi. " << hm->getSize() << std::endl;
    std::cout << "vii. " << std::endl << hm->toString() << std::endl;
}
