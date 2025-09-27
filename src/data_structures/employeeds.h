#pragma once
#include <string>


class Employee
{
private:
    int m_id;
    std::string m_name;
    std::string m_birthDate;
    std::string m_phNumber;
    std::string m_address;

    Employee* next;

public:
    friend class EmpLinkedList;
    Employee(
        int id,
        std::string name,
        std::string birthDate,
        std::string phNumber,
        std::string address
    );

    void printInfo() const;
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
    void printList() const; // used this naming case instead
                            // of print_list to ensure consistency
                            // accross naming
    void addFront(std::string, std::string, std::string, std::string);
    void addBack(std::string, std::string, std::string, std::string);
    void deleteFront();
    void deleteBack();
    void find(int id) const;
    void modify(Employee*, std::string, std::string, std::string, std::string);
    void add(std::string, std::string, std::string, std::string);
    void deleteNode(Employee*); // using this name
                                // instead of 'delete' because
                                // 'delete' is a reserved name
    int count() const;
};
