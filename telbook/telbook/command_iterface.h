#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H
#include "telbase.h"

enum Com{help, add, change, show, allshow, unknown, close};//enum command

class Comand{
//private:
    
    
public:
    //command
 
    Com findComand(std::string& com);
    void startProgram();

};

 


#endif