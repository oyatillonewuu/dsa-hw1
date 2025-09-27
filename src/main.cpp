#include "cmdunit/cmd.h"

int main(void) {
    CommandManager cmdManager;
    int statusCode = cmdManager.init();
    return statusCode;
}
