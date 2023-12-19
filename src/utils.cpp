#include "utils.h"
#include "stdlib.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>


using namespace std;
using namespace utils;



FileUtils::FileUtils() {}

bool FileUtils::fileExtensionTest(const string& filePath) {

    vector<string> correctFileExtension = {"zip", "gz", "7z"};

    cout << "[+] Checking if the file has the right extension ..." << endl;
    cout << "[+] Testing for the file " << filePath << endl;
    ifstream f(filePath);

    if(!f.is_open()) {
        cout << endl;
        cerr << "[-] Something went wrong when opening the file " << filePath << endl;
        return false;
    }

    else {
        string fileExtension;
        for (int i = 0; i < filePath.size(); ++i) {
               if(filePath.substr(filePath.size()-i, 1) == ".") {
                   // Following implementation of size_type is replaced by integer due to following reasons explained
                   // in the link potential issues with the size conversion between std::string::size_type (which is
                   // typically an unsigned integer) and int. The filePath.size() function returns a value of type
                   // std::string::size_type, which might be a larger unsigned type than int. std::string::size_type
                   // is the appropriate type to represent the length of a string.
                   for (string::size_type j = filePath.size() - i; j < filePath.size(); ++j) {
                       fileExtension += filePath.substr(j + 1, 1);
                   }
            }
        }

        for (const string& ext : correctFileExtension) {
            if(ext == fileExtension) {
                cout << "[+] File has a correct extension: ." << fileExtension << endl;
            }
        }
    }
    return true;
}

//void FileUtils::zipFile(const char *source, const char *destination) {
//    system("");
//}

void FileUtils::moveFile(const string &sourcePath, const string &destinationPath) {
    filesystem::path p;
    p = sourcePath;

    cout << "Path: " << p << endl;
    cout << "Root path: " << p.root_name() << endl;
    // Make a copy of the file
    // Remove file


}

bool FileUtils::isModuleSourceCodeValid(const string &filePath) {

}


