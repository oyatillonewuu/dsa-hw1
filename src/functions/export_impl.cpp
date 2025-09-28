#include "funcs.h"
#include "export_decl.h"
#include "../cmdunit/cmd.h"

void registerCommands(CommandManager& cmdManager) {
    cmdManager.addCommand(
        Command("Get front employee's info", &frontEmployeeInfo)
    );
    cmdManager.addCommand(
        Command("Get back employee's info", &backEmployeeInfo)
    );
    cmdManager.addCommand(
        Command("Print all employees' info", &printEmployeesInfo)
    );
    cmdManager.addCommand(
        Command("Insert employee to front", &insertEmployeeFront)
    );
    cmdManager.addCommand(
        Command("Insert employee to back", &insertEmployeeBack)
    );
    cmdManager.addCommand(
        Command("Delete employee at front", &deleteEmployeeFront)
    );
    cmdManager.addCommand(
        Command("Delete employee at back", &deleteEmployeeBack)
    );
    cmdManager.addCommand(
        Command("Search employee by ID", &searchEmployeeById)
    );
    cmdManager.addCommand(
        Command("Modify employee data", &modifyEmployeeData)
    );
    cmdManager.addCommand(
        Command("Auto-add employee by ID", &addEmployeeById)
    );
    cmdManager.addCommand(
        Command("Delete employee by ID", &deleteEmployeeById) // Would be a
                                                              // good joke if we
                                                              // said "Fire employee" :)
    );
    cmdManager.addCommand(
        Command("Print employee count", &printEmployeeCount)
    );
}
