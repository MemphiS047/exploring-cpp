#include "command_cli.h"
#include "module.h"
#include "stdio.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;
using namespace filesystem;

Command::Command(Module *module) : module(module) {}

Command::~Command() {}

CreateModuleCommand::CreateModuleCommand(Module *module) : Command(module) {}

void CreateModuleCommand::execute()
{
    time_t curr_t;
    time(&curr_t);
    struct tm *local_time = localtime(&curr_t);
    string timestamp = to_string(local_time->tm_year + 1900) +
                       to_string(local_time->tm_mon + 1) +
                       to_string(local_time->tm_mday);

    string moduleName;
    string moduleDescription;
    string moduleAuthor;
    string moduleSourceCodePath;

    cout << "Creating a new project..." << endl;

    cout << "Enter module name: ";
    cin >> moduleName;

    cout << "Enter module description: ";
    cin >> moduleDescription;

    cout << "Enter module author: ";
    cin >> moduleAuthor;

    // Set default properties
    module->setName(moduleName);
    module->setModuleDescription(moduleDescription);
    module->setModuleAuthor(moduleAuthor);
    module->setModuleID(module->generateModuleID());
    module->setModuleVersion("v0.0");
    module->setModuleCreationDate(timestamp);
    module->setModuleLastModifiedDate(timestamp);
    cout << "Module instance is created...." << endl;

    cout << "Enter file path: ";
    cin >> moduleSourceCodePath;

    // Check the type of provided files for registering modules
    vector<string> magic_bytes = {
        "\x50\x4B\x03\x04",
        "\x1F\x8B",
        "\x75\x73\x74\x61\x72",
        "\x75\x73\x74\x61\x72",
        "\x52\x61\x72\x21\x1A\x07\x00",
        "\x42\x5A\x68"
    };

    char buffer[100];
    ifstream sourceFile (moduleDescription, ios::binary);
    sourceFile.read(buffer, 100);
    for (int i = 0; i < 100; i++)
    {
        cout << buffer[i];
    }
    cout << endl;    
}

// Command Invoker
void CommandInvoker::addCommand(string commandName, Command *cmd)
{
    commandMap[commandName] = cmd;
}

void CommandInvoker::executeCommand(string commandName)
{
    commandMap[commandName]->execute();
}