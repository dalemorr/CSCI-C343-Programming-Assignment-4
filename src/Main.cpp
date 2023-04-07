#include <string>
#include <iostream>
#include <fstream>
#include "AirportRecord.h"
#include "HashMap.h"

int main() {
    std::string filename1 = "air16.dat";
    std::string filename2 = "air128.dat";

    std::ifstream file1(filename1);
    std::ifstream file2(filename2);
    std::string line;

    std::getline(file1, line);
    if (line == "16") {
        std::cout << "fizz" << std::endl;
    } else if (line == "128") {
        std::cout << "buzz" << std::endl;
    }
}
