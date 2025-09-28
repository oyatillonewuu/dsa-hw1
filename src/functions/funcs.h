#pragma once
#include <string>
#define SUB_CMD_SIGN "~> "

class EmpLinkedList; // forward declaration
class Employee;

int _insertEmployeeMultiAction(EmpLinkedList& employeeList, bool front);
int _deleteFrontOrBack(EmpLinkedList& employeeList, bool front);
void _printDeleteMessage(int employeeID);
int _preventEmptyAction(EmpLinkedList& employeeList);
Employee* _findEmployeeById(EmpLinkedList& employeeList);

int readNewEmployeeInfo(
    std::string&,
    std::string&,
    std::string&,
    std::string&,
    bool failEmpty
);
int frontEmployeeInfo(EmpLinkedList&);
int backEmployeeInfo(EmpLinkedList&);
int printEmployeesInfo(EmpLinkedList&);
int insertEmployeeFront(EmpLinkedList&);
int insertEmployeeBack(EmpLinkedList&);
int deleteEmployeeFront(EmpLinkedList&);
int deleteEmployeeBack(EmpLinkedList&);
int searchEmployeeById(EmpLinkedList&);
int modifyEmployeeData(EmpLinkedList&);
int addEmployeeById(EmpLinkedList&);
int deleteEmployeeById(EmpLinkedList&);
int printEmployeeCount(EmpLinkedList&);
