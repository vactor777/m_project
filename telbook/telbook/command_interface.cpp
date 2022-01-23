#include "command_interface.h"
#include "telbase.h"
void Comand::startProgram(){
    Telbase objProgram;
    bool flag = true;
    while(flag){
        std::cout << "enter command: ";
        std::string command;
        getline(std::cin,command);
        if (command[command.length()-1] == ' ')
            for (int i = command.length()-1; command[i] == ' '; i--)
                command = command.substr(0, command.size() -1);
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
                changeAbonent(objProgram, command);
            }
            break;
            case show:
            {
                showAbonent(objProgram, command);
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
            case write:
            {
                writeToFile(objProgram, command);
            }
                break;
            case read:
            {
                std::cout << "under development\n";
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
        std::cout << "Help about comand\n";
        std::cout << "command --help (help about program)\n";
        std::cout << "command add [nameabonent] (add new abonent)\n";
        std::cout << "command change [nameoldabonent] [-n] [namenewabonent] (change abonent)\n";
        std::cout << "command show [nameabonent] (show abonent)\n";
        std::cout << "command allshow (show all abonent)\n";
        std::cout << "command close (close program)\n";
        std::cout << "command deleted [nameabonent] (deleted abonent)\n";
        std::cout << "command write (write allabonent to file)\n";
        std::cout << "command read (under development)\n";
}

void Comand::createAbonCommand(Telbase& obj, std::string& command)
{
    std::string strtmp;
    for (int i = 1; i < command.length(); i++)
        if (command[i - 1] == ' ')
            for (int j = i; j < command.length(); j++, i++)
                strtmp += command[j];
    int lenName = strtmp.length();
    char* tmpName = new char[lenName + 1];
    for (int i = 0; i < lenName; i++)
        tmpName[i] = strtmp[i];
    tmpName[lenName] = '\0';
    obj.createAbonent(tmpName);
    delete[] tmpName;
}

void Comand::allshowComand(Telbase& obj, std::string& command){obj.getAbonent();}

void Comand::deletedAbonent(Telbase& obj, std::string& command)
{
    std::string strtmp = "";
    for (int i = 1; i < command.length(); i++)
        if (command[i - 1] == ' ')
            for (int j = i; j < command.length(); j++, i++)
                strtmp += command[j];
    int len = strtmp.length();
    char* tmp = new char[len + 1];
    for (int i = 0; i < len; i++)
        tmp[i] = strtmp[i];
    tmp[len] = '\0';
    obj.deleteAbonent(tmp);
    delete[] tmp;
}

void Comand::writeToFile(Telbase& obj, std::string& command) {obj.writeToFile();}

Com Comand::findCommand(const std::string& com){
    Com tmp = unknown;
    std::string tmpStr = "";
    int counSpace = 0;
    for (int i = 0; i < com.length(); i++)
        if (com[i] == ' ')
            counSpace++;
    if (!counSpace){
        tmpStr = com;
    }
    else{
    for (int i = 0; com[i] != ' '; i++)
        tmpStr+=com[i];
    }
    const int size = 10;    
    std::string command_str[size]{"--help", "add", "change", "show", "allshow","deleted", "write", "read", "unknown", "close"};
    for (int i = 0; i < size; i++)
        if (tmpStr == command_str[i])
            tmp = Com(i);
    return tmp;
}

void Comand::changeAbonent(Telbase& obj, std::string& command){
    
    //ищем ключ
    std::string keyNewName = "-n";
    int countK = command.length() - 1;
    std::string keyTmp;
    int positionKey_n = 0;
    for (int i = 0; i < command.length(); i++)
    {
        if (command[i] == ' ')
            continue;
        keyTmp += command[i];
        if ( command[i+1] == ' ')
        {
            if (keyTmp == keyNewName){
                positionKey_n = i + 1;
                break; 
            }
            else{
                keyTmp.clear();
            }
        }
    }
    if (!positionKey_n)
        return;
    //основное имя
    std::string strtmp;
    for (int i = 1; i < command.length(); i++)
        if (command[i - 1] == ' ')
            for (int j = i; j < positionKey_n - 3; j++, i++)
                strtmp += command[j];
     
    int len = strtmp.length();
    char* tmp = new char[len + 1];
    for (int i = 0; i < len; i++)
        tmp[i] = strtmp[i];
    tmp[len] = '\0';
    //новое имя
    std::string newNameTmp;
    for(int i = positionKey_n+1; i < command.length(); i++) {
        newNameTmp += command[i];    
    }
    int lenChar = newNameTmp.length();
    char* newNameTmpChar = new char[lenChar + 1];
    for (int i = 0; i < lenChar; i++)
        newNameTmpChar[i] = newNameTmp[i];
    newNameTmpChar[lenChar] = '\0';
    Abonent* ptr = obj.findAbonent(tmp);
    if (ptr != nullptr)
       ptr->setName(newNameTmpChar);
    delete[] newNameTmpChar;
    delete[] tmp;
}

void Comand::showAbonent(Telbase& obj, std::string& command)
{
    std::string strtmp;
    for (int i = 1; i < command.length(); i++)
        if (command[i - 1] == ' ')
            for (int j = i; j < command.length(); j++, i++)
                strtmp += command[j];
    int len = strtmp.length();
    char* tmp = new char[len + 1];
    for (int i = 0; i < len; i++)
        tmp[i] = strtmp[i];
    tmp[len] = '\0';
    Abonent* ptr = obj.findAbonent(tmp);
    if (ptr != nullptr)
       std::cout << ptr->to_string(1) << std::endl;
    delete[] tmp;
}

//void readTofille(){}