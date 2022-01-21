#include "command_iterface.h"
//#include <cstring>
void Comand::startProgram(){
    bool flag = true;
    while(flag){
        std::cout << "enter command: ";
        std::string command;
        getline(std::cin,command);
        Com chek;
        chek = findComand(command);
        switch (chek)
        {
            case help:
            {
                std::cout << "it is help\n";
            }
            break;
            case add:
            {
                std::cout << "it is add\n";
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
                std::cout << "it is allshow\n";
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

Com Comand::findComand(std::string& com){
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