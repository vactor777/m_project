#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H
#include "telbase.h"

enum Com{help, add, change, show, allshow, deleted, write, unknown, close};//enum command

class Comand{
//private:
    
    
public:
    //command
 
    Com findCommand(const std::string& com);
    void startProgram();
    void helpCommand(const std::string& command);
    void createAbonCommand(Telbase& obj, std::string& command);
    void allshowComand(Telbase& obj, std::string& command);
    void showAbonent(Telbase& obj, std::string& command);
    void deletedAbonent(Telbase& obj, std::string& command);
    void writeToFile(Telbase& obj, std::string& command);
};


#endif