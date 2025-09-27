#include <iostream>
#include "utils.h"


void printDivLine() {
    for (int i = 0; i < 50; i++) {
        std::cout << "-";
    }
    printLine();
}

void printLine() {
    std::cout << std::endl;
}
