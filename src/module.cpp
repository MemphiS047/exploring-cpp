#include "./../include/module.h"

#include <ctime>
#include <string>
#include <cstring>

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

Module::Module() {}

Module::~Module() {}

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

void Module::printModuleInfo() {
    cout << "Module name: " << this->name << endl;
    cout << "Module ID: " << this->moduleID << endl;
    cout << "Module creation time: " << this->moduleCreationDate << endl;
    cout << "Module last modified: " << this->moduleLastModifiedDate << endl;
    cout << "Module version: " << this->moduleVersion << endl;
}