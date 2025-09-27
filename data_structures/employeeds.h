#pragma once
#include <string>


class Employee
{
private:
    int m_id;
    std::string m_name;
    std::string m_birth_date;
    std::string m_ph_number;
    std::string m_address;

    Employee* next;

public:
    Employee(
        int id,
        std::string name,
        std::string brith_date,
        std::string ph_number,
        std::string m_address
    );

    void print_info() const;
};


class EmpLinkedList
{
private:
    Employee* head;
    int lastId;
    void validateAccess() const;

public:
    EmpLinkedList();
    ~EmpLinkedList();

    bool isEmpty() const;
    const Employee* front() const;
    const Employee* back() const;
    void print_list() const;
    void addFront(std::string, std::string, std::string, std::string);
    void addBack(std::string, std::string, std::string, std::string);
    void deleteFront();
    void deleteBack();
    void find(int id) const;
    void modify(Employee*, std::string, std::string, std::string, std::string);
    void add(Employee*);
    void deleteNode(Employee*);
    int count() const;
};
