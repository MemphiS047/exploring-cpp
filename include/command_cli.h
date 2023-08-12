#ifndef COMMAND_H
#define COMMAND_H

#include "module.h"
#include "map"

using namespace std;

class Command
{
protected:
    Module *module;


public:
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
    void addCommand(string commandName, Command *cmd);
    void executeCommands();
    void executeCommand(string commandName);
};

#endif // COMMAND_H
