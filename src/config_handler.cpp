//
// Created by hakve on 12/19/2023.
//

#include "config_handler.h"
#include <iostream>
#include <fstream>

using namespace std;

ConfigHandler::ConfigHandler() {}
ConfigHandler::~ConfigHandler() {}

string ConfigHandler::parseForModuleName() {

    string line;
    ifstream f;

    f.open(this->configFileLocation, ios::in);

    if(f.is_open()) {
        while(getline(f, line)) {
            cout << line << '\n';
        }
    }

    f.close();
    return "";
}

string ConfigHandler::getConfigFilePath() {return  this->configFileLocation; }
void ConfigHandler::setConfigFilePath(std::string userProvidedPath) { this->configFileLocation = userProvidedPath; }