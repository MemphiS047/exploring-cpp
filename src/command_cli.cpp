#include "command_cli.h"
#include "module.h"
#include "stdio.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iterator>
#include <unordered_map>

#include <ctime>

using namespace std;
using namespace filesystem;

Command::Command(Module *module) : module(module) {}
Command::~Command() {}

CreateModuleCommand::CreateModuleCommand(Module *module) : Command(module) {};
ListModulesCommand::ListModulesCommand(Module *module) : Command(module) {};



// Collects system related information such as, system time, OS version, location etc.
void CreateModuleCommand::collectSystemInformation() {};

// Collects necessary module information for initialization of the module such as name of the module
// description of the module etc.
void CreateModuleCommand::collectModuleInformation()
{
    string userGivenModuleName;
    string userGivenModuleDescription;
    string generatedModuleID;

    // Get the module name it is mandatory to create a module
    cout << "Name your module: " << endl;
    cin >> userGivenModuleName;
    module->setModuleName(userGivenModuleName);

    // Get the description from the user it's optional
    cout << "Give a description (optional): " << endl;
    cin >> userGivenModuleDescription;
    module->setModuleDescription(userGivenModuleDescription);

    // TODO;
    // Assigned ID must be unique to each created module so search for unique ID generation algorithms and implement
    // it somewhere else, for temporarily assign static IDs with the modules
    module->setModuleID("#ID-TEMP");

}

void CreateModuleCommand::loadSourceCode()
{

}

// Creates a module instance given the required fields
void CreateModuleCommand::execute()
{
    // Initialization phase
    collectSystemInformation();
    collectModuleInformation();

    // Processing phase
        // - run following validity test; integrity check, directory structure check and file type check
        // - run the given configuration on the provided source code
        // - if compiled/executed successfully then load the given source code
        // - once loaded do sanity checks and testing of the module (benchmarking, complexity analysis,
        //   program correctness


    // Completion phase
        // - collect all the logs, data generated from the command on processing phase and store it in related places
        //   and save it to model catalogue with it.
    loadSourceCode();

}

// List related modules using the protocol Buffer
void ListModulesCommand::execute(){};

// Command Invoker
void CommandInvoker::addCommand(string commandName, Command *cmd)
{
    commandMap[commandName] = cmd;
}

void CommandInvoker::executeCommand(string commandName)
{
    commandMap[commandName]->execute();
}
