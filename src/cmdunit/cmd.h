#pragma once
#include <string>
#include <vector>
#include <set>
#include <functional>
#include "../data_structures/employeeds.h"
#define EXIT 1
#define SUCCESS 0
#define FAIL 2

using CommandFunction = int (*)(EmpLinkedList&);

class Command {
private:
    std::string m_name;
    CommandFunction m_funcPtr;

public:
    Command(std::string name, CommandFunction);
    std::string getName() const;
    void exec(EmpLinkedList&) const;
};


class CommandManager {
private:
    std::vector<Command> commands;
    EmpLinkedList employeeList;
    std::set<std::string> helperCmds {"help", "clear", "exit"};
    std::string cmdSignature = ">>> ";
public:
    int init();
    int listen();
    std::vector<std::string> parse(const std::string& input);

    // Transfers ownership of temporary Command objects
    // to CommandManager instance
    void addCommand(Command&&);
    // Overload for lvalues
    void addCommand(Command&);

    int execCommand(std::vector<std::string>& commandVec);
    bool isValidCommand(std::vector<std::string>& commandVec);
    void printCommands() const;
    std::string getCmdSignature() const;
};
