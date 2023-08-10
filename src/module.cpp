#include "./../include/module.h"

#include <ctime>
#include <string>
#include <cstring>

string Module::generateModuleID()
{
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
        for (int i = 1; i < formattedName.length(); i++)
        {
            formattedName[i] = tolower(formattedName[i]);
        }
        return formattedName;
    };
    this->name = formatName(Module::name);
    this->name = this->name + " " + day + month + year;
}

Module::Module(string name)
{
    this->name = name;
    this->moduleID = generateModuleID();
}

Module::Module()
{
    cout << "Default constructor called" << endl;
}

Module::~Module()
{
    cout << "Module " << this->name << " has been destroyed" << endl;
}