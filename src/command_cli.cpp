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
//void CreateModuleCommand::collectSystemInformation()
//{
//    // Get local time
//    time_t epoch = time(0);
//    printf("%s", asctime(localtime(&epoch)));
//    module->setModuleCreationDate(asctime(localtime((&epoch))));
//
//    // Get OS
//    cout << getOSName() << endl;
//    module->setModuleOSName(getOSName());
//}

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

// Creates a module instance given the required fields
void CreateModuleCommand::execute()
{
    // Step 1: Collect system information and necessary module information from user
//    collectSystemInformation();

//    string moduleName;
//    string moduleDescription;
//    string moduleAuthor;
//    string moduleSourceCodePath;
//
     cout << "Creating a new project..." << endl;
//
//     cout << "Enter module name: ";
//     cin >> moduleName;
//
//     cout << "Enter module description: ";
//     cin >> moduleDescription;
//
//     cout << "Enter module author: ";
//     cin >> moduleAuthor;
//
//     Set default properties
//     module->setModuleName(moduleName);
//     module->setModuleDescription(moduleDescription);
//     module->setModuleAuthor(moduleAuthor);
//     module->setModuleID(module->generateModuleID());
//     module->setModuleVersion("v0.0");
//     module->setModuleCreationDate(timestamp);
//     module->setModuleLastModifiedDate(timestamp);
//     cout << "Module instance is created...." << endl;

    // Step 2: Source file validation
//    cout << "Enter file path (only gzip or zip accepted!!): ";
//    cin >> moduleSourceCodePath;
//
//    path p(moduleSourceCodePath);
//    string fileExtension = p.extension();
//
//    if(fileExtension != ".zip" && fileExtension != ".gz") {
//        cout << "File extension is not supported use either .gz or .zip" << endl;
//        return;
//    }

    // Step 3: Load source code and automate given tasks from the config file

    // Step 4: Do a sanity check

    // Step 5: If everything is verified and working robust, through sanity check, then load the module to
    // module catalogue, by also preserving the data produced through sanity check (benchmarking, complexity analysis,
    // program correctness)

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
