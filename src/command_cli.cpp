#include <iostream>
#include <string>
#include <vector>

#include "map"
#include "module.h"
// #include "ui.h"

using namespace std;

// Command interface
class Command
{
protected:
    Module *module;
    // UI *ui;

public:
    // Command(Module *module, UI *ui) : module(module) {}
    Command(Module *module) : module(module) {}
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Create module command classes
class CreateModuleCommand : public Command
{
public:
    CreateModuleCommand(Module *module) : Command(module) {}
    void execute() override
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
        // module->setModuleDescription(moduleDescription);
        // module->setModuleAuthor(moduleAuthor);
    }
};

// Invoker class
class CommandInvoker
{
private:
    vector<Command *> commands;
    map<string, Command *> commandMap;

public:
    void addCommand(string commandName, Command *cmd)
    {
        commandMap[commandName] = cmd;
    }

    void executeCommands()
    {
        for (Command *cmd : commands)
        {
            cmd->execute();
        }
    }

    void executeCommand(string commandName)
    {
        commandMap[commandName]->execute();
    }

};