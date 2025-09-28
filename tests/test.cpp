/*
 * Main author: Claude.ai
 * 
 * Oyatillo: used Claude.ai to speed up the
 *           the development.
 *
 * */

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
#include "../src/data_structures/employeeds.h"

// Test counter
int testsPassed = 0;
int testsTotal = 0;

#define TEST(condition, message) \
    testsTotal++; \
    if (condition) { \
        std::cout << "[PASS] " << message << std::endl; \
        testsPassed++; \
    } else { \
        std::cout << "[FAIL] " << message << std::endl; \
    }

#define TEST_EXCEPTION(code, exception_type, message) \
    testsTotal++; \
    try { \
        code; \
        std::cout << "[FAIL] " << message << " (no exception thrown)" << std::endl; \
    } catch (const exception_type& e) { \
        std::cout << "[PASS] " << message << std::endl; \
        testsPassed++; \
    } catch (...) { \
        std::cout << "[FAIL] " << message << " (wrong exception type)" << std::endl; \
    }

void testEmployeeConstruction() {
    std::cout << "\n=== Testing Employee Construction ===" << std::endl;
    
    Employee emp(1, "John Doe", "1990-01-01", "555-1234", "123 Main St");
    
    // Note: These tests will fail if getters don't exist in your implementation
    // TEST(emp.getId() == 1, "Employee ID set correctly");
    // TEST(emp.getName() == "John Doe", "Employee name set correctly");
    emp.printInfo();
    
    std::cout << "Employee constructed successfully (manual verification needed)" << std::endl;
}

void testEmptyList() {
    std::cout << "\n=== Testing Empty List Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    TEST(list.isEmpty(), "New list is empty");
    TEST(list.count() == 0, "Empty list count is 0");
    
    TEST_EXCEPTION(list.front(), std::runtime_error, "front() throws on empty list");
    TEST_EXCEPTION(list.back(), std::runtime_error, "back() throws on empty list");
    TEST_EXCEPTION(list.deleteFront(), std::runtime_error, "deleteFront() throws on empty list");
    TEST_EXCEPTION(list.deleteBack(), std::runtime_error, "deleteBack() throws on empty list");
}

void testAddFront() {
    std::cout << "\n=== Testing Add Front Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addFront("Alice", "1985-05-15", "555-0001", "100 Oak St");
    list.printList();
    TEST(!list.isEmpty(), "List not empty after addFront");
    TEST(list.count() == 1, "Count is 1 after first addFront");
    
    list.addFront("Bob", "1990-10-20", "555-0002", "200 Pine St");
    list.printList();
    TEST(list.count() == 2, "Count is 2 after second addFront");
    
    list.addFront("Charlie", "1988-03-12", "555-0003", "300 Elm St");
    list.printList();
    TEST(list.count() == 3, "Count is 3 after third addFront");
}

void testAddBack() {
    std::cout << "\n=== Testing Add Back Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addBack("David", "1992-07-08", "555-0004", "400 Maple St");
    list.printList();
    TEST(!list.isEmpty(), "List not empty after addBack");
    TEST(list.count() == 1, "Count is 1 after first addBack");
    
    list.addBack("Eve", "1987-12-25", "555-0005", "500 Cedar St");
    list.printList();
    TEST(list.count() == 2, "Count is 2 after second addBack");
    
    list.addBack("Frank", "1995-04-30", "555-0006", "600 Birch St");
    list.printList();
    TEST(list.count() == 3, "Count is 3 after third addBack");
}

void testMixedAddOperations() {
    std::cout << "\n=== Testing Mixed Add Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addFront("First", "1980-01-01", "555-1111", "111 First St");
    list.printList();
    list.addBack("Last", "1980-12-31", "555-9999", "999 Last St");
    list.printList();
    list.addFront("VeryFirst", "1979-06-15", "555-0000", "000 Zero St");
    list.printList();
    list.addBack("VeryLast", "1981-06-15", "555-1010", "1010 End St");
    list.printList();
    
    TEST(list.count() == 4, "Count is 4 after mixed operations");
}

void testDeleteFront() {
    std::cout << "\n=== Testing Delete Front Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    // Add some employees
    list.addFront("Alice", "1985-05-15", "555-0001", "100 Oak St");
    list.addFront("Bob", "1990-10-20", "555-0002", "200 Pine St");
    list.addFront("Charlie", "1988-03-12", "555-0003", "300 Elm St");
    list.printList();
    
    TEST(list.count() == 3, "Initial count is 3");
    
    list.deleteFront();
    list.printList();
    TEST(list.count() == 2, "Count is 2 after first deleteFront");
    
    list.deleteFront();
    list.printList();
    TEST(list.count() == 1, "Count is 1 after second deleteFront");
    
    list.deleteFront();
    list.printList();
    TEST(list.count() == 0, "Count is 0 after third deleteFront");
    TEST(list.isEmpty(), "List is empty after deleting all elements");
}

void testDeleteBack() {
    std::cout << "\n=== Testing Delete Back Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    // Add some employees
    list.addBack("David", "1992-07-08", "555-0004", "400 Maple St");
    list.addBack("Eve", "1987-12-25", "555-0005", "500 Cedar St");
    list.addBack("Frank", "1995-04-30", "555-0006", "600 Birch St");
    list.printList();
    
    TEST(list.count() == 3, "Initial count is 3");
    
    list.deleteBack();
    list.printList();
    TEST(list.count() == 2, "Count is 2 after first deleteBack");
    
    list.deleteBack();
    list.printList();
    TEST(list.count() == 1, "Count is 1 after second deleteBack");
    
    list.deleteBack();
    list.printList();
    TEST(list.count() == 0, "Count is 0 after third deleteBack");
    TEST(list.isEmpty(), "List is empty after deleting all elements");
}

void testSingleElementOperations() {
    std::cout << "\n=== Testing Single Element Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addFront("Solo", "1990-01-01", "555-SOLO", "Solo Street");
    list.printList();
    
    const Employee* front = nullptr;
    const Employee* back = nullptr;
    
    try {
        front = list.front();
        back = list.back();
        TEST(front == back, "front() and back() return same element in single-element list");
    } catch (const std::exception& e) {
        std::cout << "[FAIL] Exception in single element access: " << e.what() << std::endl;
    }
    
    list.deleteFront();
    list.printList();
    TEST(list.isEmpty(), "List empty after deleting single element");
}

void testFindOperations() {
    std::cout << "\n=== Testing Find Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addFront("Alice", "1985-05-15", "555-0001", "100 Oak St");
    list.addFront("Bob", "1990-10-20", "555-0002", "200 Pine St");
    list.addFront("Charlie", "1988-03-12", "555-0003", "300 Elm St");
    
    std::cout << "Testing find operations (check output manually):" << std::endl;
    list.find(1, true);  // Should find Alice
    list.find(2, true);  // Should find Bob
    list.find(3, true);  // Should find Charlie
    list.find(999, true); // Should not find
    
    // Test find on empty list
    EmpLinkedList emptyList;
    emptyList.find(1, true);
}

void testModifyOperations() {
    std::cout << "\n=== Testing Modify Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addFront("Original", "1990-01-01", "555-0000", "Original St");
    
    const Employee* emp = nullptr;
    try {
        emp = list.front();
        // Cast away const for modify operation (your design choice)
        list.modify(const_cast<Employee*>(emp), "Modified", "1991-02-02", "555-1111", "Modified Ave");
        list.printList();
        std::cout << "Employee modified successfully" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "[FAIL] Exception in modify: " << e.what() << std::endl;
    }
    
    TEST_EXCEPTION(list.modify(nullptr, "Test", "1990-01-01", "555-0000", "Test St"), 
                   std::runtime_error, "modify() throws on null pointer");
}

void testAddWithSorting() {
    std::cout << "\n=== Testing Add with Sorting ===" << std::endl;
    
    EmpLinkedList list;
    
    // Test the add() method that seems to maintain order
    list.add("First", "1990-01-01", "555-1111", "First St");
    list.printList();
    TEST(list.count() == 1, "Count is 1 after first add");
    
    list.add("Second", "1991-02-02", "555-2222", "Second St");
    list.printList();
    TEST(list.count() == 2, "Count is 2 after second add");
    
    list.add("Third", "1992-03-03", "555-3333", "Third St");
    list.printList();
    TEST(list.count() == 3, "Count is 3 after third add");
}

void testDeleteNode() {
    std::cout << "\n=== Testing Delete Node Operations ===" << std::endl;
    
    EmpLinkedList list;
    
    list.addFront("ToDelete", "1990-01-01", "555-DELETE", "Delete St");
    list.addFront("ToKeep", "1991-02-02", "555-KEEP", "Keep St");
    list.printList();
    
    const Employee* empToDelete = nullptr;
    try {
        empToDelete = list.back(); // Get the "ToDelete" employee
        list.deleteNode(const_cast<Employee*>(empToDelete));
    list.printList();
        TEST(list.count() == 1, "Count is 1 after deleteNode");
    } catch (const std::exception& e) {
        std::cout << "[FAIL] Exception in deleteNode: " << e.what() << std::endl;
    }
    
    TEST_EXCEPTION(list.deleteNode(nullptr), std::runtime_error, 
                   "deleteNode() throws on null pointer");
}

void testPrintOperations() {
    std::cout << "\n=== Testing Print Operations (Manual Verification) ===" << std::endl;
    
    std::cout << "\n--- Testing Employee printInfo ---" << std::endl;
    Employee testEmp(99, "Test Employee", "1995-05-05", "555-TEST", "Test Address");
    testEmp.printInfo();
    
    std::cout << "\n--- Testing Empty List Print ---" << std::endl;
    EmpLinkedList emptyList;
    emptyList.printList();
    
    std::cout << "\n--- Testing List with Multiple Employees ---" << std::endl;
    EmpLinkedList list;
    list.addFront("Alice Johnson", "1985-03-15", "555-0001", "123 Oak Street");
    list.addBack("Bob Smith", "1990-07-22", "555-0002", "456 Pine Avenue");
    list.addFront("Charlie Brown", "1988-11-08", "555-0003", "789 Elm Drive");
    list.printList();
    
    std::cout << "\n--- Testing Single Employee List ---" << std::endl;
    EmpLinkedList singleList;
    singleList.addFront("Solo Worker", "1992-12-01", "555-SOLO", "999 Lonely Lane");
    singleList.printList();
}

void testEdgeCases() {
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;
    
    // Empty strings
    EmpLinkedList list;
    list.addFront("", "", "", "");
    TEST(list.count() == 1, "Can add employee with empty strings");
    
    // Very long strings
    std::string longString(1000, 'A');
    list.addBack(longString, longString, longString, longString);
    TEST(list.count() == 2, "Can add employee with long strings");
    
    // Special characters
    list.addFront("José María", "1990-01-01", "+1-555-123-4567", "123 Main St., Apt #2B");
    TEST(list.count() == 3, "Can add employee with special characters");
}

void testMemoryOperations() {
    std::cout << "\n=== Testing Memory Management ===" << std::endl;
    
    // Create and destroy multiple lists
    for (int i = 0; i < 10; ++i) {
        EmpLinkedList* list = new EmpLinkedList();
        
        for (int j = 0; j < 100; ++j) {
            list->addFront("Employee" + std::to_string(j), 
                          "1990-01-01", "555-" + std::to_string(j), 
                          "Address " + std::to_string(j));
        }
        
        TEST(list->count() == 100, "Large list created successfully");
        delete list;
    }
    
    std::cout << "Memory stress test completed (check for leaks externally)" << std::endl;
}

int main() {
    std::cout << "Starting Comprehensive Employee Tests" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    try {
        testEmployeeConstruction();
        testEmptyList();
        testAddFront();
        testAddBack();
        testMixedAddOperations();
        testDeleteFront();
        testDeleteBack();
        testSingleElementOperations();
        testFindOperations();
        testModifyOperations();
        testAddWithSorting();
        testDeleteNode();
        testPrintOperations();
        testEdgeCases();
        testMemoryOperations();
    } catch (const std::exception& e) {
        std::cout << "\nUnexpected exception in main: " << e.what() << std::endl;
    }
    
    std::cout << "\n=====================================" << std::endl;
    std::cout << "Test Results: " << testsPassed << "/" << testsTotal << " passed" << std::endl;
    
    if (testsPassed == testsTotal) {
        std::cout << "All tests passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Some tests failed. Check implementation." << std::endl;
        return 1;
    }
}
