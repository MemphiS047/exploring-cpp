#ifndef COMMAND_H
#define COMMAND_H

#include "module.h"
#include "map"

using namespace std;

// TODO; Later on after completed writing the general logic of Command class and related subclasses, proceed to
// TODO; complete the integration of command lifetime (as described in the documentation) within the Command class
// TODO; rather then, explicitly writing that logic in each related subclasses
class Command
{
protected:
    Module *module;


public:
    Command(Module *module);
    virtual ~Command();
    virtual void execute() = 0;
};

// Creates module, with default parameters and files that will be added also
// given as list of tuples as (fileNames, filePath) 
class CreateModuleCommand : public Command
{
public:
    CreateModuleCommand(Module *module);
    void execute() override;

    // Initialization phase
    void collectSystemInformation();
    void collectModuleInformation();
    string getOSName();

    // Completion phase
    void loadSourceCode();
    void doComplexityAnalysis();
    void doSanityCheck();

    // Operation methods
    void loadModuleToCatalogue();

};

class ListModulesCommand : public Command
{
public:
    ListModulesCommand(Module *module);
    void execute() override;
};

// Deletes the module object, related stored files and records from the module
// repository 
class DeleteModuleCommand : public Command
{
    DeleteModuleCommand(Module *module);
    void execute() override;
};

// Modify existing modules by replacing given list of (filesName, filePath) tuple
class ModifyModuleFilesCommand : public Command
{

};

// Adds related module files to built chain and module repository
class AddModuleFilesCommand : public Command
{

};

// Class or data structure required to execute commands, store command related content at runtime
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
