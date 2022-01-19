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
