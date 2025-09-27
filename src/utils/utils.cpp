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

void printLine(int nTimes) {
    for (int i = 0; i < nTimes; i++) {
        std::cout << std::endl;
    }
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

bool isNumeric(const std::string& str) {
    for (char ch: str) {
        if (ch < '0' || ch > '9') return false;
    }
    return true;
}
