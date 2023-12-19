#include "array_based_vector.hpp"
#include <iostream>

int main() {
    std::cout << "main is executing..." << "\n";

    IntVector test_list;

    //Add ints 0 - 15 and check they've been added
    for (int num = 0; num < 16; num++) {
        test_list.push(num);
        if (test_list.at(num) == num) {
            std::cout << num << " is added in. \n";
        }
        else {
            std::cout << "got '" << test_list.at(num) << "' instead of " << num << ".\n";
        }
    }

    std::cout << "main is finished" << "\n";
    return 0;
}