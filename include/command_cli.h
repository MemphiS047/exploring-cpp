#ifndef COMMAND_H
#define COMMAND_H

#include "module.h"
#include "ui.h"

#include "map"
#include "vector"

using namespace std;

class Command
{
protected:
    Module *module;
    UI *ui;

public:
    Command(Module *module, UI *ui);
    Command(Module *module);
    virtual ~Command();
    virtual void execute() = 0;
};

class CreateModuleCommand : public Command
{
public:
    CreateModuleCommand(Module *module);
    void execute() override;
};

class CommandInvoker
{
private:
    vector<Command *> commands;
    map<string, Command *> commandMap;

public:
    CommandInvoker();
    ~CommandInvoker();
    void addCommand(string commandName, Command *command);
    void executeCommand(string commandName);
};    

#endif // COMMAND_H
