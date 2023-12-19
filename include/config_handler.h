//
// Created by hakve on 12/19/2023.
//

#ifndef EXPLORINGCPP_CONFIG_HANDLER_H
#define EXPLORINGCPP_CONFIG_HANDLER_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class ConfigHandler {
private:
    string configFileLocation;
    map<string, vector<string>> keywords = {
            {"meta",{"name", "description", "language", "input", "output", "source", "tags", "version", "dependencies"}}
    };
public:
    ConfigHandler();
    ConfigHandler(string configFileLocation);
    ~ConfigHandler();

    // Get methods
    string getConfigFilePath();

    // Set methods
    void setConfigFilePath(string userProvidedPath);

    // Parser functionalities


    string parseForModuleName();
    string parseModuleMetaData();


};


#endif //EXPLORINGCPP_CONFIG_HANDLER_H
