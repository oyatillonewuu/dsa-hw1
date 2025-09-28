#include <iostream>
#include <stdexcept>
#include <string>
#include "employeeds.h"
#include "../utils/utils.h"


Employee::Employee(
    int id,
    std::string name,
    std::string birthDate,
    std::string phNumber,
    std::string address
)
    : m_id{ id }
    , m_name{ name }
    , m_birthDate{ birthDate }
    , m_phNumber{ phNumber }
    , m_address{ address }
    , next{ nullptr }
{};

void Employee::printInfo() const {
    printLine();
    std::cout << ORANGE << "ID: " << RESET << this->m_id;
    printLine();
    std::cout << ORANGE << "Name: " << RESET << this->m_name;
    printLine();
    std::cout << ORANGE << "Birth date: " << RESET << this->m_birthDate;
    printLine();
    std::cout << ORANGE << "Phone number: " << RESET << this->m_phNumber;
    printLine();
    std::cout << ORANGE << "Address: " << RESET << this->m_address;
    printLine();
}

int Employee::getId() const {
    return m_id;
}

std::string Employee::getName() const {
    return m_name;
}

std::string Employee::getBirthDate() const {
    return m_birthDate;
}

std::string Employee::getPhoneNumber() const {
    return m_phNumber;
}

std::string Employee::getAddress() const {
    return m_address;
}

EmpLinkedList::EmpLinkedList()
    : head{ nullptr }
    , lastId{ 0 }
{};

EmpLinkedList::~EmpLinkedList() {
    while (head) {
        Employee* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void EmpLinkedList::validateAccess() const {
    if (isEmpty()) {
        throw std::runtime_error("Illegal access: list is empty.");
    }
}

bool EmpLinkedList::isEmpty() const {
    return head == nullptr;
}

Employee* EmpLinkedList::front() const {
    validateAccess();
    return head;
}

Employee* EmpLinkedList::back() const {
    validateAccess();
    Employee* mover = head;

    while (mover->next) {
        mover = mover->next;
    }
    return mover;
}

void EmpLinkedList::printList() const {
    printLine();
    std::cout << ORANGE BOLD << "Employee List" << RESET;
    printLine();
    printDivLine();

    if (isEmpty()) {
        std::cout << BOLD << RED<< "(empty)" << RESET << std::endl;
        printDivLine();
        printLine();
        return;
    }

    Employee* employee = head;

    while (employee) {
        employee->printInfo();
        printDivLine();
        employee = employee->next;
    }

    printLine();

    return;
}

void EmpLinkedList::addFront(
    std::string name,
    std::string birthDate,
    std::string phNumber,
    std::string address
) {
    int nextId = lastId + 1;
    Employee* newEmp = new Employee(
        nextId,
        name, birthDate,
        phNumber, address
    );

    if (isEmpty()) {
        head = newEmp;
    } else {
        newEmp->next = head;
        head = newEmp;
    }
    lastId = nextId;
    return;
}

void EmpLinkedList::addBack(
    std::string name,
    std::string birthDate,
    std::string phNumber,
    std::string address
) {
    int nextId = lastId + 1;

    Employee* newEmp = new Employee(
        nextId,
        name, birthDate,
        phNumber, address
    );

    if (isEmpty()) {
        head = newEmp;
    }
    else {
        Employee* lastNode = head;

        while (lastNode->next) {
            lastNode = lastNode->next;
        }

        lastNode->next = newEmp;
        lastNode = newEmp;
    }

    lastId = nextId;
    return;
}

void EmpLinkedList::deleteFront() {
    validateAccess();
    Employee* target = head;
    head = head->next;
    delete target;
}

void EmpLinkedList::deleteBack() {
    validateAccess();
    Employee* prevTarget = head;

    if (prevTarget->next == nullptr) {
        head = nullptr;
        delete prevTarget;
        return;
    }

    while (prevTarget->next->next) {
        prevTarget = prevTarget->next;
    }

    Employee* target = prevTarget->next;
    prevTarget->next = nullptr;
    delete target;
}

Employee* EmpLinkedList::find(int id, bool printInfo) const {
    if (!isEmpty()) {
        Employee* mover = head;
        while (mover) {
            if (mover->m_id == id) {
                if (printInfo) {
                    mover->printInfo();
                }
                return mover;
            }
            mover = mover->next;
        }
    }
    std::cout << RED << BOLD "Employee witd ID " << RESET;
    std::cout << ORANGE << BOLD << id << RESET;
    std::cout << RED << BOLD << " was not found." << RESET;
    printLine();
    return nullptr;
}

void EmpLinkedList::modify(
    Employee* emp,
    std::string newName,
    std::string newBirthDate,
    std::string newPhoneNumber,
    std::string newAddress
) {
    if (emp == nullptr) {
        throw std::runtime_error("Error: tried to modify non-existent employee record.");
    }

    emp->m_name = newName;
    emp->m_birthDate = newBirthDate;
    emp->m_phNumber = newPhoneNumber;
    emp->m_address = newAddress;

    return;
}

void EmpLinkedList::add(
    std::string name,
    std::string birthDate,
    std::string phNumber,
    std::string address
)
{
    int nextId = lastId + 1;
    Employee* emp = new Employee(
        nextId,
        name,
        birthDate,
        phNumber,
        address
    );

    if (isEmpty()) {
        head = emp;
        lastId = nextId;
        return;
    }

    int lowId = nextId - 1;
    Employee* prevCandidate = nullptr;
    Employee* mover = head;

    while (mover) {
        if (!prevCandidate) {
            if (mover->m_id <= lowId) {
                prevCandidate = mover;
            }
        } else {
            if (mover->m_id <= lowId && mover->m_id >= prevCandidate->m_id) {
                prevCandidate = mover;
            }
        }
        mover = mover->next;
    }

    if (!prevCandidate) {
        emp->next = head;
        head = emp;
    } else {
        emp->next = prevCandidate->next;
        prevCandidate->next = emp;
    }

    lastId = nextId;
    return;
}

void EmpLinkedList::deleteNode(Employee * emp) {
    if (emp == nullptr) {
        throw std::runtime_error("Error: tried to remove non-existent employee record.");
    }

    if (emp == head) {
        head = head->next;
        delete emp;
        return;
    }

    Employee* prev = head;

    while (prev->next != emp) {
        prev = prev->next;
    }

    prev->next = emp->next;
    delete emp;
    return;
}

int EmpLinkedList::count() const {
    int count = 0;

    Employee* mover = head;

    while (mover) {
        count++;
        mover = mover->next;
    }
    return count;
}

int EmpLinkedList::getLastId() const {
    return lastId;
}
