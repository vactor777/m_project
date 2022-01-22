#include "command_interface.h"
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
                std::cout << "under development\n";
            }
            break;
            case show:
            {
                std::cout << "under development\n";
            }
                break;
            case allshow:
            {
                allshowComand(objProgram, command);
            }
                break;
            case deleted:
            {
                deletedAbonent(objProgram, command);
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
        std::cout << "command add [nameabonent] (add new abonent)\n";
        std::cout << "command change [nameabonent] [newnameabonent] (change abonent)\n";
        std::cout << "command show [nameabonent] (show abonent)\n";
        std::cout << "command allshow -- (show all abonent)\n";
        std::cout << "command close (close program)\n";
        std::cout << "command deleted [nameabonent] (deleted abonent)\n";
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
        obj.getAbonent();//change to_tsring return string
    else
        std::cout << "Operation incorrect\n";
}
void Comand::deletedAbonent(Telbase& obj, std::string& command)
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
    obj.deleteAbonent(tmp);
    delete[] tmp;
}
Com Comand::findCommand(const std::string& com){
    Com tmp = unknown;
    if (com == "close")
        return close;
    std::string tmpStr = "";
    for (int i = 0; com[i] != ' '; i++)
        tmpStr+=com[i];
    std::string command_str[8]{"help", "add", "change", "show", "allshow","deleted", "unknown", "close"};
    for (int i = 0; i < 6; i++)
        if (tmpStr == command_str[i])
            tmp = Com(i);
    return tmp;
}