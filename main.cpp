#include "config.h"
#include "module.h"
#include "stdio.h"
#include "command_cli.h"

#include <ctime>
#include <iostream>

int main() {
    // Module module("Bubble Sort Algorithm");
    // module.printModuleInfo();
    
    Module module;
    // Create command objects

    Command *createModuleCommand = new CreateModuleCommand(&module);

    // Create invoker
    CommandInvoker invoker;
    invoker.addCommand("createproject", createModuleCommand);

    // Execute commands
    invoker.executeCommand("createproject");

    // Clean up
    delete createModuleCommand;
    return 0;
}
