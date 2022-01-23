#include "command_interface.h"
#include "telbase.h"
void Comand::startProgram() {
	Telbase objProgram;
	bool flag = true;
	while (flag) {
		std::cout << "enter command: ";
		std::string command;
		getline(std::cin, command);
		if (command[command.length() - 1] == ' ')
			for (int i = command.length() - 1; command[i] == ' '; i--)
				command = command.substr(0, command.size() - 1);
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
	std::cout << "               [nameoldabonent] [-h] [changeHometelephone]\n";
	std::cout << "               [nameoldabonent] [-w] [changeWorktelephone]\n";
	std::cout << "               [nameoldabonent] [-w] [changeohtherinfo]\n";
	std::cout << "command show [nameabonent] (show abonent)\n";
	std::cout << "command allshow (show all abonent)\n";
	std::cout << "command close (close program)\n";
	std::cout << "command deleted [nameabonent] (deleted abonent)\n";
	std::cout << "command write (write allabonent to file)\n";
	std::cout << "command read (under development)\n";
}

void Comand::createAbonCommand(Telbase& obj, const std::string& command)
{
	//Key keys_;
	const int sizeK = 4;
	int positionKey_n = 0;
	int countKeys = 0;
	std::string keys[4]{ "-n", "-h", "-w", "-o" };
	for (int i = 1; i < sizeK; i++) {
		positionKey_n = findKey(command, keys[i]);
		if (positionKey_n != -1) { break; }
	}
	std::string com = command;
	if (positionKey_n != -1) {
		com.clear();
		for (int i = 0; i < positionKey_n - 3; i++) { com += command[i]; }
	}
	char* tmp = findName(com);
	obj.createAbonent(tmp);
	delete[] tmp;
	//считаем колво ключей
	if (positionKey_n != -1) {
		for (int i = 1; i < sizeK; i++) {
			positionKey_n = findKey(command, keys[i]);
			if (positionKey_n != -1) { countKeys++; }
		}
	}
	std::cout << "keys = " << countKeys << std::endl;
	//определяем что меняет первый ключ меняем черк changeAbonent
	// и т.д


	/*
	switch (countKeys)
	{
	case 1:
	{
		char* tmp = findName(command);
		obj.createAbonent(tmp);
		delete[] tmp;
	}
	break;
	case 2:
	{
		std::cout << "obj 2 pereg\n";
		for (int i = 0; i < sizeK; i++) {
			positionKey_n = findKey(command, keys[i]);
			if (positionKey_n != -1) {
				keys_ = Key(i);
				break;
			}
		}
		std::string strtmp;
		for (int i = 0; i < positionKey_n - 3; i++)
			strtmp += command[i];

		switch (keys_)
		{
		case hometel_:
		{
			std::string twoArg = findName(command, positionKey_n + 1, ' ');
			char* tmp = findName(strtmp);
			obj.createAbonent(tmp, twoArg);
			delete[] tmp;
		}
		break;
		case worktel_:
		{
			std::string twoArg = findName(command, positionKey_n + 1, ' ');
			char* tmp = findName(strtmp);
			obj.createAbonent(tmp, "000", twoArg);
			delete[] tmp;
		}
		break;
		case other_:
		{
			std::string twoArg;
			for (int i = positionKey_n + 1; i < command.length(); i++) { twoArg += command[i]; }
			char* tmp = findName(strtmp);
			obj.createAbonent(tmp, "000", "000", twoArg);
			delete[] tmp;
		}
		break;
		}
	}
	break;
	case 3:
	{
		Key keys_1, keys_2;
		int positionKey_n1 = 0;
		for (int i = 0; i < sizeK; i++) {
			positionKey_n1 = findKey(command, keys[i]);
			if (positionKey_n != -1) {
				keys_1 = Key(i);
				break;
			}
		}
		int positionKey_n2 = 0;
		std::string comModif = findName(command, positionKey_n1);
		for (int i = 0; i < sizeK; i++) {
			positionKey_n2 = findKey(comModif, keys[i]);
			if (positionKey_n2 != -1) {
				keys_2 = Key(i);
				break;
			}
		}
		std::string strtmp;
		for (int i = 0; i < positionKey_n1 - 3; i++)
			strtmp += command[i];
		switch (keys_1)
		{
		case hometel_:
		{
			std::string twoArg = findName(command, positionKey_n1 + 1, ' ');
			std::string threeArg = findName(command, positionKey_n2 + 1, ' ');
			char* tmp = findName(strtmp);
			obj.createAbonent(tmp, twoArg);
			delete[] tmp;
		}
		break;
		case worktel_:
		{
			std::string twoArg = findName(command, positionKey_n + 1, ' ');
			char* tmp = findName(strtmp);
			obj.createAbonent(tmp, "000", twoArg);
			delete[] tmp;
		}
		break;
		case other_:
		{
			std::string twoArg;
			for (int i = positionKey_n + 1; i < command.length(); i++) { twoArg += command[i]; }
			char* tmp = findName(strtmp);
			obj.createAbonent(tmp, "000", "000", twoArg);
			delete[] tmp;
		}
		break;
		}
		std::cout << "obj 3 pereg\n";
	}
	break;
	case 4:
	{
		//ищем что за ключи и создаем объек с 4 перегрузками
		std::cout << "obj 4 pereg\n";
	}
	break;

	}
	*/
}

void Comand::allshowComand(Telbase& obj, const std::string& command) { obj.getAbonent(); }

void Comand::deletedAbonent(Telbase& obj, const std::string& command)
{
	char* tmp = findName(command);
	obj.deleteAbonent(tmp);
	delete[] tmp;
}

void Comand::writeToFile(Telbase& obj, const std::string& command) { obj.writeToFile(); }

int Comand::findKey(const std::string& command, const std::string& key) const
{
	std::string keyNewName = key;
	int countK = command.length() - 1;
	std::string keyTmp;
	int positionKey_n = -1;
	for (int i = 0; i < command.length(); i++)
	{
		if (command[i] == ' ')
			continue;
		keyTmp += command[i];
		if (command[i + 1] == ' ')
		{
			if (keyTmp == keyNewName) {
				positionKey_n = i + 1;
				break;
			}
			else {
				keyTmp.clear();
			}
		}
	}
	return positionKey_n;
}

char* Comand::findName(const std::string& command) const
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
	return tmp;
}

std::string Comand::findName(const std::string& command, int startpos, char symb) const
{
	std::string newstr;
	for (int i = startpos; i < command.length(); i++) {
		if (command[i] == symb)
			break;
		newstr += command[i];
	}
	return newstr;
}

std::string Comand::findName(const std::string& command, int startpos) const
{
	std::string newstr;
	for (int i = startpos; i < command.length(); i++) {	newstr += command[i]; }
	return newstr;
}

Com Comand::findCommand(const std::string& com) {
	Com tmp = unknown;
	std::string tmpStr = "";
	int counSpace = 0;
	for (int i = 0; i < com.length(); i++)
		if (com[i] == ' ')
			counSpace++;
	if (!counSpace) {
		tmpStr = com;
	}
	else {
		for (int i = 0; com[i] != ' '; i++)
			tmpStr += com[i];
	}
	const int size = 10;
	std::string command_str[size]{ "--help", "add", "change", "show", "allshow","deleted", "write", "read", "unknown", "close" };
	for (int i = 0; i < size; i++)
		if (tmpStr == command_str[i])
			tmp = Com(i);
	return tmp;
}

void Comand::changeAbonent(Telbase& obj, const std::string& command) {

	//ищем ключ
	Key keys_;
	const int sizeK = 4;
	int positionKey_n = 0;
	std::string keys[sizeK]{ "-n", "-h", "-w", "-o" };
	for (int i = 0; i < sizeK; i++) {
		positionKey_n = findKey(command, keys[i]);
		if (positionKey_n != -1) {
			keys_ = Key(i);
			break;
		}
	}
	if (positionKey_n == -1)
		return;
	std::string strtmp;
	for (int i = 0; i < positionKey_n - 3; i++)
		strtmp += command[i];
	char* tmp = findName(strtmp);
	//новое поле
	std::string newNameTmp;
	for (int i = positionKey_n + 1; i < command.length(); i++) { newNameTmp += command[i]; }
	int lenChar = newNameTmp.length();
	char* newNameTmpChar = new char[lenChar + 1];
	for (int i = 0; i < lenChar; i++)
		newNameTmpChar[i] = newNameTmp[i];
	newNameTmpChar[lenChar] = '\0';
	Abonent* ptr = obj.findAbonent(tmp);
	if (ptr != nullptr) {
		switch (keys_)
		{
		case name_:
			ptr->setName(newNameTmpChar);
			break;
		case hometel_:
			ptr->setTel(newNameTmp, 0);
			break;
		case worktel_:
			ptr->setTel(newNameTmp, 1);
			break;
		case other_:
			ptr->setInfo(newNameTmp);
			break;
		}
	}
	delete[] newNameTmpChar;
	delete[] tmp;
}

void Comand::showAbonent(Telbase& obj, const std::string& command)
{
	char* tmp = findName(command);
	Abonent* ptr = obj.findAbonent(tmp);
	if (ptr != nullptr)
		std::cout << ptr->to_string(1) << std::endl;
	delete[] tmp;
}

//void readTofille(){}