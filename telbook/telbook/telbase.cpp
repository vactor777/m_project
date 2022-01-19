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

Abonent::Abonent(const char* name, ulong telHome, ulong telWork, std::string otherInfo)
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
void Abonent::setTel(ulong telephone, int keys){
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
	countObj = 0;
}
Telbase::~Telbase(){
	
	//delete ptrAbonent;
}
void Telbase::createAbonent(const char* name,ulong telHome, ulong telWork, std::string otherInfo){
	if (!countObj)
		ptrAbonent->setPtrNextObj();
	Abonent* abonent = new Abonent(name, telHome, telWork, otherInfo);
	

	ptrAbonent = abonent; 
	countObj++;
}
void Telbase::changeName(const char* name){
	ptrAbonent->setName(name);
}
void Telbase::changeTelephone(ulong telHome_telWork, int keys){
	ptrAbonent->setTel(telHome_telWork, keys);
}
void Telbase::changeOtherInfo(const std::string otherInfo){
	ptrAbonent->setInfo(otherInfo);
}
