#include <iostream>
#include <stdexcept>
#include <string>
#include "utils.h"


int readPosInteger(const std::string& input, unsigned int& destination) {
    if (!isNumeric(input)) return FAIL;
    if (input.at(0) == '0') return FAIL;
    destination = str2Int(input);
    return SUCCESS;
}

int str2Int(const std::string str) {
    if (str.length() == 0 || !isNumeric(str)) {
        throw std::runtime_error("Non-numeric string passed to str2Int.");
    }
    int result = 0;

    for (char ch: str) {
        result *= 10;
        int digit = ch - 48;
        result += digit;
    }
    return result;
}

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
    if (str.length() == 0) return false;
    for (char ch: str) {
        if (ch < '0' || ch > '9') return false;
    }
    return true;
}
