#include "config.h"
#include "utils.h"
#include "config_handler.h"
#include "module.h"
#include "command_cli.h"

#include <iostream>

using namespace utils;
using namespace std;

utils::FileUtils fileUtils;

int main() {
    cout << "[+] Starting program ..." << endl;

    // File extension test
//    const string &filePath = "/home/yigitwsl/test.gz";
//    const string &defaultRepoPath = "/home/yigitwsl/defrepo/";
//    if(fileUtils.fileExtensionTest(filePath)) {
//        cout << "[+] File passed extension test moving to next step (main.cpp)" << endl;
//    }

    // Testing for config parser
    ConfigHandler configHandler;
    configHandler.setConfigFilePath("/home/yigitwsl/test.cfg");
    configHandler.parseForModuleName();

//    // Create a simple module object
//    Module module("Bubble Sort Algorithm");
//    module.printModuleInfo();
//
//    // Create command objects
//    Command *createModuleCommand = new CreateModuleCommand(&module);
//
//    // Create invoker
//    CommandInvoker invoker;
//    invoker.addCommand("createmodule", createModuleCommand);
//
//    // Execute commands
//    invoker.executeCommand("createmodule");
//
//    // Print module info
//    module.printModuleInfo();
//
//    // Clean up
//    delete createModuleCommand;


    return 0;
}
