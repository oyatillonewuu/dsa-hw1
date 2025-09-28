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

    int getId() const;
    std::string getName() const;
    std::string getBirthDate() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;
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
    Employee* front() const;
    Employee* back() const;
    void printList() const; // used this naming case instead
                            // of print_list to ensure consistency
                            // accross naming
    void addFront(std::string, std::string, std::string, std::string);
    void addBack(std::string, std::string, std::string, std::string);
    void deleteFront();
    void deleteBack();
    Employee* find(int id, bool printInfo) const;
    void modify(Employee*, std::string, std::string, std::string, std::string);
    void add(std::string, std::string, std::string, std::string);
    void deleteNode(Employee*); // using this name
                                // instead of 'delete' because
                                // 'delete' is a reserved name
    int count() const;
    int getLastId() const;
};
