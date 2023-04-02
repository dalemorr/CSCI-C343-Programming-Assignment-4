//
// Created by littl on 4/2/2023.
//

#include <iostream>
#include "HashMap.h"

int main() {
    HashMap hm;
    hm.put(3, 23);
    hm.put(5, 2377);
    hm.put(9, 263);
    std::cout <<"Value of key = 3, is "<<hm.get(3) << std::endl;
    hm.put(12, 230);
    std::cout << "override an existing entry of (3, 23) with (3,123)" << std::endl;
    hm.put(3, 123);
    std::cout << "New value of key = 3, is "<<hm.get(3) << std::endl;
}