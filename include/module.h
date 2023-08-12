#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Module
{
public:
    Module(string name);
    Module();
    ~Module();

    // Get functions
    string getName();
    string getModuleID();
    string getModuleRunTimeInfo();
    string getModuleMemoryProfiling();
    string getModuleCPUProfiling();

    // Module source code files
    string getModuleSourceCode(); 

    // Set functions
    void setName(string name);
    void setModuleID(string moduleID);
    void setModuleDescription(string moduleDescription);
    void setModuleVersion(string moduleVersion);
    void setModuleAuthor(string moduleAuthor);

    // Utility functions
    string generateModuleID();

    // Mounts the module related source code to the module object and returns the module ID
    // mounted modules later on can be used to do memory profiling, CPU profiling and run time info
    string mountModule();

    // Unmounts the module from the system and returns the module ID, freeing up CPU load and memory
    // all the mounting and unmounting actions are recorded in a system log file or a database
    string unmountModule();

    // Prints the project meta-data (run time info, such as uptime) and static module information
    // (such as module name, module ID, etc.)
    void printModuleInfo();

private:
    // Module static meta-data
    string name;
    string moduleID;
    string moduleDescription;
    string moduleVersion;
    string moduleAuthor;
    string moduleUpTime;
    string moduleCompileInstruction;
    string moduleCreationDate;
    string moduleLastModifiedDate;

    // Module dynamic data
    vector<Module> mountedModules;

    // Property that stored the module source code
    vector<string> moduleSourceCode;

    // Memory Profiling
    string memoryAllocation;
    string memoryBlockTable;
    string memoryAllocationLiftime;
    string memoryHeapFragmentation;
    string memoryStackFragmentation;
    string memoryVirtualMemoryFragmentation;

    // CPU profiling
    string moduleCpuUsage;
    string moduleFunctionExecutionTime;
    string moduleCallStackSampling;
    string moduleIoOperations;
    string moduleCacheUtilization;
    string moduleInstructionTable;
};

#endif