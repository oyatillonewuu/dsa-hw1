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
    std::cout << "ID: " << this->m_id;
    printLine();
    std::cout << "Name: " << this->m_name;
    printLine();
    std::cout << "Birth date: " << this->m_birthDate;
    printLine();
    std::cout << "Phone number: " << this->m_phNumber;
    printLine();
    std::cout << "Address: " << this->m_address;
    printLine();
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

const Employee* EmpLinkedList::front() const {
    validateAccess();
    return head;
}

const Employee* EmpLinkedList::back() const {
    validateAccess();
    Employee* mover = head;

    while (mover->next) {
        mover = mover->next;
    }
    return mover;
}

void EmpLinkedList::printList() const {
    printLine();
    std::cout << "Employee List";
    printLine();
    printDivLine();

    if (isEmpty()) {
        std::cout << "(empty)" << std::endl;
        printDivLine();
        return;
    }

    Employee* employee = head;

    while (employee) {
        employee->printInfo();
        printDivLine();
        employee = employee->next;
    }

    printDivLine();
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

void EmpLinkedList::find(int id) const {
    if (!isEmpty()) {
        Employee* mover = head;
        while (mover) {
            if (mover->m_id == id) {
                mover->printInfo();
                return;
            }
            mover = mover->next;
        }
    }
    std::cout << "Find: employee witd ID " << id << " was not found.";
    printLine();
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
