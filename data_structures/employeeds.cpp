#include <iostream>
#include <stdexcept>
#include <string>
#include "employeeds.h"
#include "../utils/utils.h"


Employee::Employee(
    int id,
    std::string name,
    std::string birth_date,
    std::string ph_number,
    std::string address,
)
    : m_id{ id }
    , m_name{ name }
    , m_birth_date{ birth_date }
    , m_ph_number{ ph_number }
    , m_address{ address }
    , next{ nullptr }
{};

void Employee::print_info() const {
    print_line();
    std::cout << "ID: " << this->id;
    print_line();
    std::cout << "Name: " << this->name;
    print_line();
    std::cout << "Birth date: " << this->birth_date;
    print_line();
    std::cout << "Phone number: " << this->ph_number;
    print_line();
    std::cout << "Address: " << this->address;
    print_line();
}


EmpLinkedList::EmpLinkedList()
    : head{ nullptr }
    , lastId{ 0 }
{};

void validateAccess() const {
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

void EmpLinkedList::print_list() const {
    print_line();
    std::cout << "Employee List";
    print_line();
    print_div();

    if (isEmpty()) {
        std::cout << "(empty)" << std::endl;
        print_div();
        return;
    }

    Employee* employee = head;

    while (employee) {
        employee->print_info();
        print_div();
        employee = employee->next;
    }

    print_div();
    return;
}

void EmpLinkedList::addFront(
    std::string name,
    std::string birht_date,
    std::string ph_number,
    std::string address
) {
    int nextId = lastId + 1;
    Employee* newEmp = new Employee(
        nextId,
        name, birth_date,
        ph_number, address
    );

    if (isEmpty()) {
        head = newEmp;
        return;
    }

    newEmp->next = head;
    head = newEmp;
    return;
}

void EmpLinkedList::addBack(
    std::strng name,
    std::string birth_date,
    std::string ph_number,
    std::string address
) {
    int nextId = lastId + 1;

    Employee* newEmp = new Employee(
        nextId,
        name, birth_date,
        ph_number, address
    );

    if (isEmpty()) {
        head = newEmp;
        return;
    }

    Employee* lastNode = head;

    while (lastNode->next) {
        lastNode = lastNode->next;
    }

    lastNode->next = newEmp;
    lastNode = newEmp;
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
        while (mover->next) {
            if (mover->id == id) {
                mover->print_info();
                return;
            }
            mover = mover->next;
        }
    }
    std::cout << "Find: employee witd ID " << id << " was not found.";
    print_line();
}

void EmpLinkedList::modify(
    Employee* emp,
    std::string newName,
    std::string newBirthDate,
    std::string newPhoneNumber,
    std::string newAddress
) {
    if (emp == nullptr) {
        throw runtime_error("Error: tried to modify non-existent employee record.");
    }

    emp->name = newName;
    emp->birth_date = newBirthDate;
    emp->ph_number = newPhoneNumber;
    emp->address = newAddress;

    return;
}

void EmpLinkedList::add(
    std::string name,
    std::string birth_date,
    std::string ph_number,
    std::string address
)
{

    Employee* emp = Employee(
        lastId + 1,
        name,
        birth_date,
        ph_number,
        address
    );

    if (isEmpty()) {
        head = emp;
        return;
    }
    int trialLowId = emp->id - 1;
    int posInx = 0;

    Employee* prevCandidate;


    Employee* mover = head;

    while (mover) {
        if (!prevCandidate) {
            if (mover->id <= trialLowId) {
                prevCandidate = mover;
            }
        } else {
            if (mover->id <= trialLowId && mover->id >= prevCandidate->id) {
                prevCandidate = mover;
            }
        }
        mover = mover->next;
        posInx++;
    }

    if (!prevCandidate) {
        emp->next = head;
        head = emp;
        return;
    }

    emp->next = prevCandidate->next;
    prevCandidate->next = emp;
    return;
}

void EmpLinkedList::deleteNode(Employee * emp) {
    if (emp == nullptr) {
        throw runtime_error("Error: tried to remove non-existent employee record.");
    }
    Employee* prev = head;

    while (prev->next != emp) {
        prev = prev->next;
    }

    prev->next = emp->next;
    delete emp;
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
