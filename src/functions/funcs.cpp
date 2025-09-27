#include <iostream>
#include "../utils/utils.h"
#include "funcs.h"
#include "../data_structures/employeeds.h"

int frontEmployeeInfo(EmpLinkedList& employeeList) {
    if (employeeList.isEmpty()) {
        std::cout << BOLD << RED << "List is empty." << RESET;
        printLine();
        return -1;
    }

    employeeList.front()->printInfo();
    return 0;
}

int backEmployeeInfo(EmpLinkedList& employeeList) {
    if (employeeList.isEmpty()) {
        std::cout << BOLD << RED << "List is empty." << RESET;
        printLine();
        return -1;
    }

    employeeList.back()->printInfo();
    return 0;
}
