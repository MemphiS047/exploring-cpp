#include "module.h"

#include <ctime>
#include <string>
#include <cstring>

// Constructor with name parameter
Module::Module(string name)
{
    time_t curr_t;
    time(&curr_t);
    struct tm *local_time = localtime(&curr_t);
    string timestamp = to_string(local_time->tm_year + 1900) + 
                       to_string(local_time->tm_mon + 1) + 
                       to_string(local_time->tm_mday);

    this->name = name;
    this->moduleID = generateModuleID();
    this->moduleCreationDate = timestamp;
    this->moduleLastModifiedDate = timestamp;
    this->moduleVersion = "v0.0";

}

// Default constructor
Module::Module() {}

// Destructor
Module::~Module() {}

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
void Module::setName(string name) { this->name = name; }
void Module::setModuleID(string moduleID) { this->moduleID = moduleID; }
void Module::setModuleDescription(string moduleDescription) { this->moduleDescription = moduleDescription; }
void Module::setModuleVersion(string moduleVersion) { this->moduleVersion = moduleVersion; }
void Module::setModuleAuthor(string moduleAuthor) { this->moduleAuthor = moduleAuthor; }
void Module::setModuleUpTime(string moduleUpTime) { this->moduleUpTime = moduleUpTime; }
void Module::setModuleCompileInstruction(string moduleCompileInstruction) { this->moduleCompileInstruction = moduleCompileInstruction; }
void Module::setModuleCreationDate(string moduleCreationDate) { this->moduleCreationDate = moduleCreationDate; }
void Module::setModuleLastModifiedDate(string moduleLastModifiedDate) { this->moduleLastModifiedDate = moduleLastModifiedDate; }
