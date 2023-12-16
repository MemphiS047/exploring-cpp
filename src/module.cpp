#include "module.h"

#include <ctime>
#include <string>
#include <cstring>

// Constructor with name parameter
Module::Module(string name)
{
    // Module creation date
    // TODO
    // Might store it as a timestamp object instead of storing plain string, class could be my own class that I
    // developed instead of using pure standard library constraints
    time_t epoch = time(0);
    printf("%s", asctime(localtime(&epoch)));
    this->moduleCreationDate = (asctime(localtime((&epoch))));
    this->moduleInitDate = epoch;

    // OS Name
    // TODO;
    // For temporarily, statically initialized it to Windows, later on will port it to Linux and Windows
    this->moduleOSName = "Windows 11";

    // Default or initial version of the module
    // TODO;
    // A versioning system could be implemented for the projects such that there is a granular git versioning for each
    // modules (projects) for temporarily versioning is manually done by the creator of the module, and stored as plain
    // strings, this could also have it's own class structure as well
    this->moduleVersion = "v0.1";

    // Module author is default initialized using the credentials of the authorized to the system
    // TODO;
    // Could build an authorization protocol from scratch using industry standards
    this->moduleAuthor = "admin";

    // Initializes module uptime, if the module is created for the first time then it is initialized to 0 in the
    // beginning, if the module is already created and source code is included in the program then metadata information
    // from protocol buffer is retrieved and initialized with previous recorded value on destruction time
    // TODO;
    // Since protocol buffers are not implemented currently, by default the program initializes module instance uptime
    // to 0 as string, for further implementations, calculateModuleUpTime(); is implemented at the destructor
    this->moduleUpTime = 0.0;
}

// Calculates the module uptime information at runtime
void Module::calculateModuleUpTime()
{
    this->moduleUpTime = (difftime(this->moduleTerminationDate, this->moduleInitDate));
}

// Default constructor
Module::Module() {}

// Destructor
Module::~Module()
{

    // Get the epoch when destructor is called and update the last modified date as we did with first initialization of
    // module instance
    time_t epoch = time(0);
    printf("%s", asctime(localtime(&epoch)));
    this->moduleLastModifiedDate = (asctime(localtime((&epoch))));
    this->moduleTerminationDate = epoch;

    // Calculate the time passed in epoch units using module initialization time in epochs and module termination time
    // in epochs
    calculateModuleUpTime();

    // TODO;
    // Write it to related fields in the protocol buffer, for later when the same module is opened, related fields
    // needs to be further updated on top of previous data recorded.

}

// Generates module ID using name and current date
string Module::generateModuleID() {
    time_t curr_t;
    time(&curr_t);
    struct tm *local_time = localtime(&curr_t);

    string year = to_string(local_time->tm_year + 1900);
    string month = to_string(local_time->tm_mon + 1);
    string day = to_string(local_time->tm_mday);

    auto formatName = [](string name)
    {
        string formattedName = "";
        for (int i = 0; i < name.length(); i++)
        {
            if (name[i] != ' ')
            {
                formattedName += name[i];
            }
        }
        for (int i = 0; i < formattedName.length(); i++)
        {
            formattedName[i] = tolower(formattedName[i]);
        }
        return formattedName;
    };
    return formatName(this->name + day + month + year);
}

// Shows overview of the referenced module instance
void Module::printModuleInfo() {
    cout << "Module name: " << this->name << endl;
    cout << "Module ID: " << this->moduleID << endl;
    cout << "Module creation time: " << this->moduleCreationDate << endl;
    cout << "Module last modified: " << this->moduleLastModifiedDate << endl;
    cout << "Module version: " << this->moduleVersion << endl;
}

// Set functions
void Module::setModuleOSName(std::string moduleOSName) { this->moduleOSName = moduleOSName; }
void Module::setModuleName(string name) { this->name = name; }
void Module::setModuleID(string moduleID) { this->moduleID = moduleID; }
void Module::setModuleDescription(string moduleDescription) { this->moduleDescription = moduleDescription; }
void Module::setModuleVersion(string moduleVersion) { this->moduleVersion = moduleVersion; }
void Module::setModuleAuthor(string moduleAuthor) { this->moduleAuthor = moduleAuthor; }
void Module::setModuleUpTime(double moduleUpTime) { this->moduleUpTime = moduleUpTime; }
void Module::setModuleCompileInstruction(string moduleCompileInstruction) { this->moduleCompileInstruction = moduleCompileInstruction; }
void Module::setModuleCreationDate(string moduleCreationDate) { this->moduleCreationDate = moduleCreationDate; }
void Module::setModuleLastModifiedDate(string moduleLastModifiedDate) { this->moduleLastModifiedDate = moduleLastModifiedDate; }
