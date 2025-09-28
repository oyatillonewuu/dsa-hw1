#include <iostream>
#include <stdexcept>
#include <string>
#include "cmd.h"
#include "../data_structures/employeeds.h"
#include "../functions/export_decl.h"
#include "../utils/utils.h"


Command::Command(
    std::string name,
    CommandFunction funcPtr
)
    : m_name{ name }
    , m_funcPtr{ funcPtr }
{};

std::string Command::getName() const {
    return m_name;
}

int Command::exec(EmpLinkedList& employeeList) const {
    return m_funcPtr(employeeList);
}

int CommandManager::init() {
    registerCommands(*this);
    int statusCode = listen();
    return statusCode;
}

void CommandManager::addCommand(Command&& command) {
    commands.push_back(std::move(command));
}

void CommandManager::addCommand(Command& command) {
    commands.push_back(command);
}

int CommandManager::listen() {
    // Guard against missed call of CommandManager::init
    if (commands.size() == 0) {
        std::cout << RED << BOLD << "CommandManager::init was not called.";
        std::cout << RESET;
        printLine();
        return FAIL;
    }

    printLine();
    std::cout << GREEN << BOLD << "Command Line Unit is active." << RESET;
    printLine(2);
    std::cout << RED << BOLD << "Tip: " RESET << "type `help` to get available commands";
    printLine();
    std::cout << ORANGE << "Litening to input..." << RESET;
    printLine(2);

    int statusCode = SUCCESS;
    while (statusCode != EXIT) {
        std::string input = "";
        std::cout << GREEN << cmdSignature << RESET;
        getline(std::cin, input);
        std::vector commandVec = parse(input);
        statusCode = execCommand(commandVec);
    }
    return statusCode;
}

std::vector<std::string> CommandManager::parse(const std::string& input) {
    std::string part = "";
    std::vector<std::string> commandVec {};

    for (char ch: input) {
        if (ch == ' ') {
            commandVec.push_back(part);
            part = "";
            continue;
        }
        part += ch;
    }
    if (part.length() != 0) {
        commandVec.push_back(part);
    }

    return commandVec;
}

int CommandManager::execCommand(std::vector<std::string>& commandVec) {
    if (commandVec.size() == 0) return SUCCESS;
    if (!isValidCommand(commandVec)) {
        std::cout << RED << BOLD << "Invalid command." << RESET;
        printLine();
        return FAIL;
    }
    std::string command = commandVec.front();
    int statusCode = SUCCESS;

    if (command == "help") {
        printCommands();
    }
    else if (command == "clear") {
        clearScreen();
    }
    else if (command == "exit") {
        return EXIT;
    }
    else {
        int commandNum = stoi(command);
        statusCode = commands.at(commandNum - 1).exec(employeeList);
    }
    return statusCode;
}

bool CommandManager::isValidCommand(std::vector<std::string>& commandVec) {
    if (commandVec.size() != 1) return false;
    std::string command = commandVec.front();
    if (helperCmds.find(command) != helperCmds.end()) return true;
    if (!isNumeric(command)) return false;
    if (command[0] == '0') return false; // must be non-zero
    if (stoi(command) > commands.size()) return false; // must not exceed
                                                        // the number of
                                                        // available commands
    return true;
}

void CommandManager::printCommands() const {
    printLine();
    std::cout << ORANGE << BOLD << "Available commands:" << RESET;
    printLine();

    for (size_t i = 0; i < commands.size(); i++) {
        std::cout << ORANGE << BOLD << i + 1 << ". " << RESET;
        std::cout << commands[i].getName();
        printLine();
    }

    printLine();
    std::cout << ORANGE << BOLD << "Helper commands: " << RESET;
    printLine();

    for (auto& elem: helperCmds) {
        std:: cout << elem;
        printLine();
    }

    printLine();
    std::cout << ORANGE << BOLD << "Note: " << RESET;
    std::cout << "type the number of function from the numbered functions to execute.";
    printLine(2);
}

std::string CommandManager::getCmdSignature() const {
    return cmdSignature;
}
