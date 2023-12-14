#include "config.h"
#include "module.h"
#include "stdio.h"
#include "command_cli.h"

#include <ctime>
#include <iostream>

int main() {

    cout << "[+] Starting program ..." << endl;

    Module module("Bubble Sort Algorithm");
//     module.printModuleInfo();


    // Create command objects
    Command *createModuleCommand = new CreateModuleCommand(&module);

    // Create invoker
    CommandInvoker invoker;
    invoker.addCommand("createmodule", createModuleCommand);

    // Execute commands
    invoker.executeCommand("createmodule");

//    // Print module info
//    // module.printModuleInfo();
//
//    // Clean up
//    delete createModuleCommand;
    return 0;
}
