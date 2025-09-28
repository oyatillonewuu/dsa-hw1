#include <iostream>
#include <string>
#include "../utils/utils.h"
#include "funcs.h"
#include "../data_structures/employeeds.h"
#define FRONT 1
#define BACK -1
#define BY_ID 0


int _insertEmployeeMultiAction(EmpLinkedList& employeeList, int action) {

    std::string name = "";
    std::string birthDate = "";
    std::string phNumber = "";
    std::string address = "";

    int statusCode = readNewEmployeeInfo(name, birthDate, phNumber, address, true);

    if (statusCode == FAIL) {
        std::cout << RED << BOLD << "Bad input. Request ignored." << RESET;
        printLine();
        return FAIL;
    }

    int id;

    if (action == FRONT) {
        employeeList.addFront(name, birthDate, phNumber, address);
        id = employeeList.front()->getId();
    }
    else if (action == BY_ID) {
        employeeList.add(name, birthDate, phNumber, address);
        id = employeeList.getLastId();
    }
    else if (action == BACK) {
        employeeList.addBack(name, birthDate, phNumber, address);
        id = employeeList.back()->getId();
    }
    else {
        std::cout << RED << BOLD << "Internal error: invalid action." << RESET;
        printLine();
        return FAIL;
    }

    std::cout << GREEN << BOLD << "New employee was added. " << RESET;
    std::cout << ORANGE << BOLD << "ID: " << RESET;
    std::cout << id << ".";

    printLine();
    return SUCCESS;
}


int _deleteFrontOrBack(EmpLinkedList& employeeList, bool front) {
    if (_preventEmptyAction(employeeList)) return FAIL;
    int id;
    if (front) {
        id = employeeList.front()->getId();
        employeeList.deleteFront();
    } else {
        id = employeeList.back() -> getId();
        employeeList.deleteBack();
    }
    _printDeleteMessage(id);
    return SUCCESS;
}

Employee* _findEmployeeById(EmpLinkedList& employeeList) {
    std::string input = "";
    std::cout << ORANGE << "Enter id: " << RESET;
    getline(std::cin, input);

    unsigned int employeeId;

    if (readPosInteger(input, employeeId) == FAIL) {
        employeeId = 0; // EmpLinkedList.find will discard with useful info.
    }

    Employee* empNode = employeeList.find((int) employeeId, false);
    
    return empNode;
}

void _printDeleteMessage(int employeeID) {
    std::cout << GREEN << BOLD << "Employee with " << RESET;
    std::cout << ORANGE << BOLD << "ID = " << RESET;
    std::cout << employeeID;
    std::cout << GREEN << BOLD << " deleted." << RESET;
    printLine();
}

int _preventEmptyAction(EmpLinkedList& employeeList) {
    if (employeeList.isEmpty()) {
        std::cout << BOLD << RED << "List is empty." << RESET;
        printLine();
        return FAIL;
    }
    return SUCCESS;
}


int readNewEmployeeInfo(
    std::string& nameDest,
    std::string& birthDateDest,
    std::string& phNumberDest,
    std::string& addressDest,
    bool failEmpty
) {
    std::cout << ORANGE << "Enter name: " << RESET;
    getline(std::cin, nameDest);

    std::cout << ORANGE << "Enter birth date: " << RESET;
    getline(std::cin, birthDateDest);

    std::cout << ORANGE << "Enter phone number: " << RESET;
    getline(std::cin, phNumberDest);

    std::cout << ORANGE << "Enter address: " << RESET;
    getline(std::cin, addressDest);

    if (
        failEmpty && (
            nameDest.length() == 0 ||
            birthDateDest.length() == 0 ||
            phNumberDest.length() == 0 ||
            addressDest.length() == 0
        )
    ) {
        return FAIL;
    }

    return SUCCESS;
}


int frontEmployeeInfo(EmpLinkedList& employeeList) {
    if (_preventEmptyAction(employeeList) == FAIL) {
        return FAIL;
    }

    employeeList.front()->printInfo();
    printLine();
    return SUCCESS;
}

int backEmployeeInfo(EmpLinkedList& employeeList) {
    if (_preventEmptyAction(employeeList) == FAIL) {
        return FAIL;
    }

    employeeList.back()->printInfo();
    printLine();
    return SUCCESS;
}

int printEmployeesInfo(EmpLinkedList& employeeList) {
    employeeList.printList();
    return SUCCESS;
}

int insertEmployeeFront(EmpLinkedList& employeeList) {
    return _insertEmployeeMultiAction(employeeList, FRONT);
}

int insertEmployeeBack(EmpLinkedList& employeeList) {
    return _insertEmployeeMultiAction(employeeList, BACK);
}

int deleteEmployeeFront(EmpLinkedList& employeeList) {
    return _deleteFrontOrBack(employeeList, true);
}

int deleteEmployeeBack(EmpLinkedList& employeeList) {
    return _deleteFrontOrBack(employeeList, false);
}

int searchEmployeeById(EmpLinkedList& employeeList) {
    Employee* empNode = _findEmployeeById(employeeList);

    if (empNode == nullptr) return FAIL;

    empNode->printInfo();
    printLine();

    return SUCCESS;
}

int modifyEmployeeData(EmpLinkedList& employeeList) {
    Employee* empNode = _findEmployeeById(employeeList);

    if (empNode == nullptr) return FAIL;

    printLine();
    std::cout << RED << BOLD << "Current info:" << RESET;
    printLine();
    empNode->printInfo();
    printLine();

    std::cout << GREEN << BOLD << "Tip: " << RESET;
    std::cout << " to keep the value unchanged, press ENTER";
    printLine(2);

    std::string name = "";
    std::string birthDate = "";
    std::string phNumber = "";
    std::string address = "";

    readNewEmployeeInfo(name, birthDate, phNumber, address, false);

    if (name.length() == 0) {
        name = empNode->getName();
    }
    if (birthDate.length() == 0) {
        birthDate = empNode->getBirthDate();
    }
    if (phNumber.length() == 0) {
        phNumber = empNode->getPhoneNumber();
    }
    if (address.length() == 0) {
        address = empNode->getAddress();
    }
    
    employeeList.modify(
        empNode,
        name, birthDate,
        phNumber, address
    );

    std::cout << GREEN << BOLD << "Employee data updated. " << RESET;
    std::cout << ORANGE << BOLD << "ID: " << RESET;
    std::cout << empNode->getId() << ".";
    printLine();
    printLine();

    return SUCCESS;
}

int addEmployeeById(EmpLinkedList& employeeList) {
    return _insertEmployeeMultiAction(employeeList, BY_ID);
}


int deleteEmployeeById(EmpLinkedList& employeeList) {
    printLine();
    Employee* empNode = _findEmployeeById(employeeList);

    if (empNode == nullptr) return FAIL;

    empNode->printInfo();
    printLine();
    int id = empNode->getId();
    employeeList.deleteNode(empNode);
    _printDeleteMessage(id);
    printLine();

    return SUCCESS;
}

int printEmployeeCount(EmpLinkedList& employeeList) {
    std::cout << ORANGE << BOLD << "Total employee count: " << RESET;
    std::cout << employeeList.count() << ".";
    printLine();
    return SUCCESS;
}
