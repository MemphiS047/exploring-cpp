#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Module
{

    // TODO;
    // For the properties research more on the extern keyword whether it can be used in the below variable declarations
    // etc. Such as the extern is used when the declared variable is declared w/o definition or a value given instead
    // they are defined or given a value somewhere else.
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

    // Utility functions
    string generateModuleID();

    // Mounts the module related source code to the module object and returns the module ID mounted modules later on
    // can be used to do memory profiling, CPU profiling and run time info
    string mountModule();

    // Unmounts the module from the system and returns the module ID, freeing up CPU load and memory all the mounting
    // and unmounting actions are recorded in a system log file or a database
    string unmountModule();

    // Prints the project meta-data (run time info, such as uptime) and static module information (such as module name,
    // module ID, etc.)
    void printModuleInfo();

    // Set functions
    void setModuleName(string name);
    void setModuleDescription(string moduleDescription);
    void setModuleVersion(string moduleVersion);
    void setModuleAuthor(string moduleAuthor);
    void setModuleUpTime(double moduleUpTime);
    void setModuleCompileInstruction(string moduleCompileInstruction);
    void setModuleID(string moduleID);
    void setModuleCreationDate(string moduleCreationDate);
    void setModuleLastModifiedDate(string moduleLastModifiedDate);
    void setModuleOSName(string moduleOSName);

    // Module methods for runtime calculations, telemetry calculations, APIs for initializing runtime properties of
    // module using system runtime information etc.
    void calculateModuleUpTime();

private:
    // Module static meta-data, below information is filled inside constructor, on
    // object creation time
    string moduleVersion;
    string moduleAuthor;
    string moduleCreationDate;
    string moduleLastModifiedDate;
    string moduleOSName;

    double moduleUpTime;

    // Module epoch time
    // TODO;
    // Referencing to the things to do on the implementation file, further development of timestamp class is to be
    // replaced with the following temporary, placeholder value for uptime calculation
    time_t moduleInitDate;
    time_t moduleTerminationDate;

    // Validation data, for validation further status of the module to flow the control to different mechanisms such as
    // if the module is initialized before it has to be created w/o using the logic of setting the creation timestamp
    // rather it needs to obtain related time, telemetry data from protocol buffer to further initialize and update
    // on it
    bool isInitializedFirstTime = moduleUpTime == 0.0;

    // Module main data
    string name;
    string moduleID;
    string moduleDescription;

    // Module configuration
    string moduleCompileInstruction;

    // Module dynamic data
    vector<Module> mountedModules;

    // Memory profiling data
    string memoryAllocation;
    string memoryBlockTable;
    string memoryAllocationLifeTime;
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