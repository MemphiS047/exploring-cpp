#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

class FileUtils
{
    public:
        static bool fileExists(const char *fileName);
        static void moveFile(const char *source, const char *destination);
        static void unzipFile(const char *source, const char *destination);
        static void zipFile(const char *source, const char *destination);    
    private:
        string filePath;
        string fileExtension;
        string fileName;
};  

#endif // UTILS_H