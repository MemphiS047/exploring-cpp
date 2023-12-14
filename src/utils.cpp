#include "utils.h"
#include "fstream"

using namespace std;

// bool FileUtils::fileExists(const char *fileName)
// {
//     ifstream infile(fileName);
//     return infile.good();
// }


void FileUtils::moveFile(const char *source, const char *destination)
{
    ifstream sourceFile(source, ios::binary);
    ofstream destFile(destination, ios::binary);
    destFile << sourceFile.rdbuf();
    sourceFile.close();
    destFile.close();
}