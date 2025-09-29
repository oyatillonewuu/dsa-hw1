### Note

```
All the parts, other than tests, are solely written by me -- a human.
I stand strongly committed to honesty and take responsibility for my claim.
```

### Running

**Note:** the scripts are targeted for Linux machines. I don't take responsibility for whether they work on MacOS or Windows.

```bash
bash build.sh
./app
```

If the script does not work, try to compile all `*.cpp` files yourself, EXCLUDING `tests` folder.

### Testing

The test is only available for data_structures.

**Note:** the scripts are targeted for Linux machines. I don't take responsibility for whether they work on MacOS or Windows.

```bash
bash test.sh && ./test
```

If the script does not work, you should compile source files from these directories:

- data_structures
- utils
- tests

### Program Organization

This program is organized into several modules, each serving different responsibility.

The `data_structures` module implements the **linked list** structure of employees used in the program and provides the header file.

The module `cmdunit` manages the following tasks:
- Interactive session
- Input parsing
- Command validation
- Command execution
- Program state tracking

These tasks are performed using `CommandManager` class.

Furthermore, `cmdunit` defines `Command` class which is helpful to store commands of the program with their *names* and also make use of contiguous behavior of `std::vector`.

`CommandManager` uses command registry pattern thanks to `Command` class.

The module `functions` defines the program's core commands and provides `cmdunit` with registrar functions that will register all commands in `functions` to `CommandManager`'s vector as a `Command` instance.

The `Command` class facilitates easy command execution (in fact, the command comes from another module) using **pointer function** to the original command function (in `functions`).

Though the above obviously outline the program behavior, here is a polished one:

1. `main` creates `CommandManager` instance and initializes it (which will call `CommandManager.listen`).
2. Upon instantiation, `CommandManager` creates `EmpLinkedList` instance as its member variable.
3. The program loop (or interactive session) is started by `CommandManager::listen` called by `CommandManager.init`.


4. The input of user is parsed as *vector of `std::string`*.
5. The parsed input is passed to `CommandManager::execCommand` which validates the command and, if valid, executes it.
6. The execution is facilitated by accessing `CommandManager::std::cout << "\033[2J\033[1;1H";commands`, the storage of registered commands, and calling the original function-command (at `functions`) through function pointer.
7. `CommandManager::employeeList` is passed to the command (function) to be executed.
8. Then, the executed function (at `functions`) performs requested operation on `CommandManager::employeeList`.
9. The control returns to `CommandManager::listen`.


P.S.: *If you're interested how this organization came to my mind, you can view [simulOS](https://github.com/loga4m/simulOS) (a project in my freshman year).
