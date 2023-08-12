#include "command_cli.h"
#include "module.h"

using namespace std;

Command::Command(Module *module) : module(module) {}

Command::~Command() {}

CreateModuleCommand::CreateModuleCommand(Module *module) : Command(module) {}

void CreateModuleCommand::execute()
{
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
}

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
