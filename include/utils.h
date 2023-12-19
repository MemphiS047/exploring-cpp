#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <filesystem>

using namespace std;

namespace utils {
    class FileUtils {
    public:
        FileUtils();


        // Basic file utilities
        static bool fileExists(const char *fileName);
        static void moveFile(const string &sourcePath, const string &destinationPath);
        static void unZipFile(const char *source, const char *destination);
        static void zipFile(const string &sourcePath, const string &destinationPath);

        // File type tests
        bool magicTest();
        bool fileExtensionTest(const string &filePath);
        bool languageTest();

        // Module source code file integrity check
        bool isModuleSourceCodeValid(const string &filePath);




    private:
        string filePath;
        string fileName;
    };
}


#endif // UTILS_H