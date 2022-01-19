#include "telbase.h"
#include <cstring>
Abonent::Abonent()
{
	name_ = new char[1];
	name_[0] = '\0';
	telHome_ = telWork_ = 0;
	otherInfo_ = "empty";
}

Abonent::Abonent(const char* name, ulong telHome, ulong telWork, std::string otherInfo)
{
	int len = strlen(name);
	name_ = new char[len + 1];
	strcpy(name_, name);
	telHome_ = telHome;
	telWork_ = telWork;
	otherInfo_ = otherInfo;
	
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
	if (keys = 0)
		telHome_ = telephone;
	else
		telWork_ = telephone;

}
void Abonent::setInfo(std::string otherInfo){}

//CLass Telbase
Telbase::Telbase(){
	ptrAbonent = nullptr;
	countObj = 0;
}
Telbase::~Telbase(){
	
	//delete ptrAbonent;
}
void Telbase::createAbonent(const char* name,ulong telHome, ulong telWork, std::string otherInfo){
	Abonent* abonent = new Abonent(name, telHome, telWork, otherInfo);
	ptrAbonent = abonent; 
	countObj++;
}
void Telbase::changeAbonent(const char* name){
	ptrAbonent->setName(name);
}
void Telbase::changeAbonent(ulong telHome_telWork, int keys){
	ptrAbonent->setTel(telHome_telWork, keys);
}
void Telbase::changeAbonent(std::string otherInfo){}
