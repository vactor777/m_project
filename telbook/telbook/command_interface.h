#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H
#include "telbase.h"

enum Com{help, add, change, show, allshow, deleted, write, read, unknown, close};//enum command

class Comand{
    int findKey(const std::string& command, const std::string& key) const;
    char* findName(const std::string& command) const;
    std::string findName(const std::string& command, int startpos, char symb) const;
    std::string findName(const std::string& command, int startpos) const;
    enum Key { name_, hometel_, worktel_, other_ };
public:
    Com findCommand(const std::string& com);
    void startProgram();
    void helpCommand(const std::string& command);
    void createAbonCommand(Telbase& obj, const std::string& command);
    void allshowComand(Telbase& obj, const std::string& command);
    void showAbonent(Telbase& obj, const std::string& command);
    void changeAbonent(Telbase& obj, const std::string& command);
    void deletedAbonent(Telbase& obj, const std::string& command);
    void writeToFile(Telbase& obj, const std::string& command);
    //void readTofille();
};

#endif