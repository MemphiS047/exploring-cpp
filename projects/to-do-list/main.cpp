#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Task
{
private:
    string name;
    string description;
    bool completed;
    int priority;
    int spentTime;

public:
    Task();
    Task(string name, string description, int priority)
    {
        this->name = name;
        this->description = description;
        this->priority = priority;
        this->completed = false;
        this->spentTime = 0;
    };

    ~Task();

    // Set functions
    void setName(string name) { this->name = name; }
    void setSpentTime(int spentTime) { this->spentTime = spentTime; }
    void setDescription(string description) { this->description = description; }
    void setCompleted(bool completed) { this->completed = completed; }
    void setPriority(int priority) { this->priority = priority; }

    // Get functions
    string getName() { return this->name; }
    string getDescription() { return this->description; }
    bool getCompleted() { return this->completed; }
    int getPriority() { return this->priority; }
    int getSpentTime() { return this->spentTime; }
};

class UI()
{
    
};

int main()
{

    return 0;
}