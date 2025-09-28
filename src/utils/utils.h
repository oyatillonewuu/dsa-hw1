#pragma once
#include <string>

#define EXIT 1
#define SUCCESS 0
#define FAIL 2

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define ORANGE "\033[0;33m"
#define RESET "\033[0m"

int readPosInteger(const std::string&, unsigned int&);
int str2Int(const std::string str);
void printDivLine();
void printLine();
void printLine(int);
void clearScreen();
bool isNumeric(const std::string&);
