#pragma once
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define ORANGE "\033[0;33m"
#define RESET "\033[0m"

void printDivLine();
void printLine();
void printLine(int);
void clearScreen();
bool isNumeric(const std::string&);
