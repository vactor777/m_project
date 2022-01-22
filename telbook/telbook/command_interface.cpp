#include "command_iterface.h"
//#include <cstring>
#include "telbase.h"
void Comand::startProgram(){
    Telbase objProgram;
    bool flag = true;
    while(flag){
        std::cout << "enter command: ";
        std::string command;
        getline(std::cin,command);
        Com chek;
        chek = findCommand(command);
        switch (chek)
        {
            case help:
            {
                helpCommand(command);
            }
            break;
            case add:
            {
                createAbonCommand(objProgram, command);
            }
            break;
            case change:
            {
                std::cout << "it is change\n";
            }
            break;
            case show:
            {
                std::cout << "it is show\n";
            }
                break;
            case allshow:
            {
                allshowComand(objProgram, command);
            }
                break;            
            case unknown:
                std::cout << "unknown comand\n";
                break;
            case close:
                flag = false;
                break;
        }
    }
}

void Comand::helpCommand(const std::string& command)
{
    if (command == "help --") {
        std::cout << "Help about comand\n";
        std::cout << "command help -- (help about program)\n";
        std::cout << "command add (add [nameabonent])\n";
        std::cout << "command change (change [nameabonent] [newnameabonent]) \n";
        std::cout << "command show (show [nameabonent])\n";
        std::cout << "command allshow -- (show all abonent)\n";
        std::cout << "command close (close program)\n";
    }
    else 
        std::cout << "Operation incorrect\n";
}

void Comand::createAbonCommand(Telbase& obj, std::string& command)
{
    std::string strtmp = "";
    for (int i = 1; i < command.length(); i++)
        if (command[i - 1] == ' ')
            for (int j = i; j < command.length(); j++, i++)
                strtmp += command[j];
    //std::cout << strtmp << std::endl;
    int len = strtmp.length();
    char* tmp = new char[len + 1];
    for (int i = 0; i < len; i++)
        tmp[i] = strtmp[i];
    tmp[len] = '\0';
    obj.createAbonent(tmp);
    delete[] tmp;
}

void Comand::allshowComand(Telbase& obj, std::string& command)
{
    if (command == "allshow --")
        obj.getAbonent();
    else
        std::cout << "Operation incorrect\n";
}

Com Comand::findCommand(const std::string& com){
    Com tmp = unknown;
    if (com == "close")
        return close;
    std::string tmpStr = "";
    for (int i = 0; com[i] != ' '; i++)
        tmpStr+=com[i];
    std::string command_str[7]{"help", "add", "change", "show", "allshow", "unknown", "close"};
    for (int i = 0; i < 6; i++)
        if (tmpStr == command_str[i])
            tmp = Com(i);
    return tmp;
}