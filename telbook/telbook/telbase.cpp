#pragma warning(disable : 4996) //for visual studio

#include <fstream>
#include "telbase.h"
#include <cstring>

Abonent::Abonent(){
	name_ = new char[1];
	name_[0] = '\0';
	telHome_ = telWork_ = "000";
	otherInfo_ = "empty";
	ptr_next_Obj_ = nullptr;
}

Abonent::Abonent(const char* name, std::string telHome, std::string telWork, std::string otherInfo)
	: telHome_ (telHome), telWork_ (telWork), otherInfo_ (otherInfo){
	int len = strlen(name);
	name_ = new char[len + 1];
	strcpy(name_, name);
	ptr_next_Obj_ = nullptr;
}

Abonent::~Abonent()
{
	delete[] name_;
}

void Abonent::setName(const char* name){
	int len = strlen(name);
	delete name_;
	name_ = new char[len + 1];
	strcpy(name_, name);
}

void Abonent::setTel(std::string telephone, int keys){
	if (keys == 0)
		telHome_ = telephone;
	else
		telWork_ = telephone;
}

void Abonent::setInfo(const std::string otherInfo){otherInfo_ = otherInfo;}

void Abonent::to_string() const
{
	//для вывода в консоль через cout	
	std::cout << "Name: " << name_;
	std::cout << ", Home Telephone: " << telHome_;
	std::cout << ", Work Telephone: " << telWork_;
	std::cout << ", Other Info: " << otherInfo_;
	std::cout << std::endl;
}

std::string Abonent::to_string(int anyKeys) const 
{
    //возвращает строку с информацией об абоненте
	std::string st = name_;
	return "Name: " + st + ", Home telephone: " + telHome_
	+ ", Work Telephone: " + telWork_ + ", Other Info: " + otherInfo_;// +"\n";
}


//CLass Telbase
Telbase::Telbase(){	ptrAbonent = nullptr; ptrStartAbonent = nullptr; countObj = 0;}
Telbase::~Telbase(){}
void Telbase::createAbonent(const char* name, std::string telHome, std::string telWork, std::string otherInfo){
		
	Abonent* abonent = new Abonent(name, telHome, telWork, otherInfo);
	if (countObj) {
		//устанавливаем текущему абоненту указатель на новый созданный абонент
		ptrAbonent->setPtrNextObj(abonent);
		ptrAbonent = abonent;
	}
	else {
		ptrAbonent = abonent;
		ptrStartAbonent = abonent;
	}
	countObj++;
}

void Telbase::changeName(const char* name, const char* new_name){
	Abonent* ptrTmp = findAbonent(name);
	if (ptrTmp == nullptr)
		return;
	ptrTmp->setName(new_name);
}

void Telbase::changeTelephone(const char* name, std::string telHome_telWork, int keys){
	Abonent* ptrTmp = findAbonent(name);
	if (ptrTmp == nullptr)
		return;
	ptrTmp->setTel(telHome_telWork, keys);
}

void Telbase::changeOtherInfo(const char* name, const std::string otherInfo){
	Abonent* ptrTmp = findAbonent(name);
	if (ptrTmp == nullptr)
		return;
	ptrTmp->setInfo(otherInfo);
}

Abonent* Telbase::findAbonent(const char* name) const
{
	//ишем абонента по имени и возвращаем указазатель найденого абонента
	Abonent* ptrTmp = ptrStartAbonent;
	bool count = true;
	for (int i = 0; i < countObj; i++) {
		const char* strTmp = ptrTmp->getName();
		if (strcmp(name, strTmp) == 0)
			return ptrTmp;
		Abonent* ptrTmp2 = ptrTmp;
		ptrTmp = ptrTmp2->getNextObj();
	}
	if (count)
		return nullptr;
	else
		return nullptr;	
}

void Telbase::deleteAbonent(const char* name)
{
	//удаляем абоненты по имени, код нужно пересмотреть и по возможности сократить
	Abonent* ptrTmp = ptrStartAbonent;
	Abonent* ptrOld = ptrStartAbonent;
	for (int i = 0; i < countObj; i++) {
		char* strTmp = ptrTmp->getName();
		if (strcmp(name, strTmp) == 0) {
			
			if (i == 0) {
				ptrStartAbonent = ptrStartAbonent->getNextObj();
				delete ptrTmp;
				countObj--;
				return;
			}
			if (i == (countObj -1)) {
				ptrOld->setPtrNextObj(nullptr);
				ptrAbonent = ptrOld;
				delete ptrTmp;
				countObj--;
				return;
			}
		    ptrOld->setPtrNextObj(ptrTmp->getNextObj());
			delete ptrTmp;
			countObj--;
			return;
		}
		Abonent* ptrTmp2 = ptrTmp;
		ptrOld = ptrTmp2;
		ptrTmp = ptrTmp2->getNextObj();
	}
	if (countObj == 0) {
		ptrAbonent = nullptr;
		ptrStartAbonent = nullptr;
	}
}

void Telbase::getAbonent()
{
	//функция показать всех абонентов 
	//использует to_string который выводит через cout
	//нужно переделать чтобы использовал to_string() который возвращает строку
	if (countObj == 1)
		ptrStartAbonent->to_string();
	else {
		Abonent* ptrTmp = ptrStartAbonent;
		for (int i = 0; i < countObj; i++) {
			ptrTmp->to_string();
			Abonent* ptrTmp2 = ptrTmp;
			ptrTmp = ptrTmp->getNextObj();
		}
	}
}

void Telbase::writeToFile(){
	using std::ofstream;
	ofstream fout;
	fout.open("baseabonent.txt");
	if (countObj == 1)
		fout << ptrStartAbonent->to_string(1) << std::endl;
	else {
		Abonent* ptrTmp = ptrStartAbonent;
		for (int i = 0; i < countObj; i++) {
			fout << ptrTmp->to_string(1) << std::endl;
			ptrTmp = ptrTmp->getNextObj();
		}
	}
	fout.close();
}

void Telbase::readToFile(){
	using std::ifstream;
	ifstream inFile;
	inFile.open("baseabonent.txt");
	if (!inFile.is_open()){
		std::cout << "file unknown\n";
		exit (EXIT_FAILURE);
	}
	else{
		std::string command;
		while (!inFile.eof())
		{
			command.clear();
			getline(inFile, command);
			if (command.empty())
				continue;
			//заменяем строку на строку команд
			std::string newcom;
			for (int i = 1; i < command.length(); i++)
			{
				if (command[i-1] == ':')
				{
					for (int j = i+1; j < command.length(); j++, i++)
					{
						if(command[i-1] == ',')
							break;
						newcom += command[j];
					}
				}
			}
			//разбиваем строку
			int countPosition = 0;
			char stNmame[100]{"\0"};
			for (int i = countPosition; newcom[i] != ','; i++){ stNmame[i] = newcom[i]; countPosition++;}
			countPosition+=2;
			std::string homeNum;
			for (int i = countPosition; newcom[i] != ','; i++){ homeNum += newcom[i]; countPosition++;}
			countPosition+=2;
			std::string workNum;
			for (int i = countPosition; newcom[i] != ','; i++){ workNum += newcom[i]; countPosition++;}
			countPosition+=2;
			std::string otherInfo;
			for (int i = countPosition; i < newcom.length(); i++){ otherInfo += newcom[i]; countPosition++;}
			//создаем абонента на информации полученной из файла
			createAbonent(stNmame, homeNum, workNum, otherInfo);
		}
		inFile.close();
	}
}

