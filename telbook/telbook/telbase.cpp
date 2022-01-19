#pragma warning(disable : 4996) //для visual studio
#include "telbase.h"
#include <cstring>

 
Abonent::Abonent()
{
	name_ = new char[1];
	name_[0] = '\0';
	telHome_ = telWork_ = 0;
	otherInfo_ = "empty";
	ptr_next_Obj_ = nullptr;
}

Abonent::Abonent(const char* name, unsigned long telHome, unsigned long telWork, std::string otherInfo)
{
	int len = strlen(name);
	name_ = new char[len + 1];
	strcpy(name_, name);
	telHome_ = telHome;
	telWork_ = telWork;
	otherInfo_ = otherInfo;
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
void Abonent::setTel(unsigned long telephone, int keys){
	if (keys == 0)
		telHome_ = telephone;
	else
		telWork_ = telephone;

}
void Abonent::setInfo(const std::string otherInfo){
	otherInfo_ = otherInfo;
}

//CLass Telbase
Telbase::Telbase(){
	ptrAbonent = nullptr;
	ptrStartAbonent = nullptr;
	countObj = 0;
}
Telbase::~Telbase(){
	
	//delete ptrAbonent;
}
void Telbase::createAbonent(const char* name, unsigned long telHome, unsigned long telWork, std::string otherInfo){
	
	Abonent* abonent = new Abonent(name, telHome, telWork, otherInfo);
	if (countObj) {
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
	ptrTmp->setName(new_name);
}
void Telbase::changeTelephone(const char* name, unsigned long telHome_telWork, int keys){
	Abonent* ptrTmp = findAbonent(name);
	ptrTmp->setTel(telHome_telWork, keys);
}
void Telbase::changeOtherInfo(const char* name, const std::string otherInfo){
	Abonent* ptrTmp = findAbonent(name);
	ptrTmp->setInfo(otherInfo);

}

Abonent* Telbase::findAbonent(const char* name)
{
	Abonent* ptrTmp = ptrStartAbonent;
	int count = 0;
	for (int i = 0; i < countObj; i++) {
		char* strTmp = ptrTmp->getName();
		if (strcmp(name, strTmp) == 0)
			return ptrTmp;//пока выход, но можно продолжить если есть с одинаковыми именами абоненты
		Abonent* ptrTmp2 = ptrTmp;
		ptrTmp = ptrTmp2->getNextObj();
	}
	if (!count) {
		std::cout << "abonent don't found";
		return nullptr;
	}
	return ptrTmp;

}
//соединить поиск и удаление сделать одну функцию по поиску в private поле
void Telbase::deleteAbonent(const char* name)
{
	Abonent* ptrTmp = ptrStartAbonent;
	Abonent* ptrOld = ptrStartAbonent;
	for (int i = 0; i < countObj; i++) {
		char* strTmp = ptrTmp->getName();
		if (strcmp(name, strTmp) == 0) {
			//если удаляем первого абонента
			if (i == 0) {
				ptrStartAbonent = ptrStartAbonent->getNextObj();
				delete ptrTmp;
				countObj--;
				return;
			}
			//если удаляем последнео абонента
			if (i == (countObj -1)) {
			//	Abonent* ptrT = nullptr;
				ptrOld->setPtrNextObj(nullptr);
				ptrAbonent = ptrOld;
				delete ptrTmp;
				countObj--;
				return;
			}
		    ptrOld->setPtrNextObj(ptrTmp->getNextObj());
			delete ptrTmp;
			countObj--;
			return;//пока выход, но можно продолжить если есть с одинаковыми именами абоненты
		}
		Abonent* ptrTmp2 = ptrTmp;
		ptrOld = ptrTmp2;
		ptrTmp = ptrTmp2->getNextObj();
	
	}
}

void Telbase::getAbonent()
{
	if (countObj == 1)
		ptrStartAbonent->to_string();
	else {
		Abonent* ptrTmp = ptrStartAbonent;
		for (int i = 0; i < countObj; i++) {
			ptrTmp->to_string();
			Abonent* ptrTmp2 = ptrTmp;
			ptrTmp = ptrTmp2->getNextObj();
		}
	}
}
