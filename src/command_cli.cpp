#include "command_cli.h"
#include "module.h"

using namespace std;

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

    cout << "Creating a new project..." << endl;

    cout << "Enter module name: ";
    cin >> moduleName;

    cout << "Enter module description: ";
    cin >> moduleDescription;

    cout << "Enter module author: ";
    cin >> moduleAuthor;

    module->setName(moduleName);
    module->setModuleDescription(moduleDescription);
    module->setModuleAuthor(moduleAuthor);
    module->setModuleID(module->generateModuleID());
    module->setModuleVersion("v0.0");
    module->setModuleCreationDate(timestamp);
    module->setModuleLastModifiedDate(timestamp);
}

// Command Invoker
void CommandInvoker::addCommand(string commandName, Command *cmd)
{
    commandMap[commandName] = cmd;
}

void CommandInvoker::executeCommands()
{
    for (Command *cmd : commands)
    {
        cmd->execute();
    }
}

void CommandInvoker::executeCommand(string commandName)
{
    commandMap[commandName]->execute();
}