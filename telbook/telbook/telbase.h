#ifndef TELBASE_H
#define TELBASE_H
#include <string>
#include <iostream>
class Abonent {
private:	
	char* name_;
	ulong telHome_;
	ulong telWork_;
	std::string otherInfo_;
public:
	Abonent();
	Abonent(const char* name, ulong telHome, ulong telWork, std::string otherInfo);
	~Abonent();
	void setName(const char* name);
	void setTel(ulong telephone, int keys);
	void setInfo(std::string otherInfo);
	void sh(){std::cout << name_ << " " << telHome_ << " " << telWork_ << " " << otherInfo_ << '\n';};
	
};
class Telbase
{
private:
	int countObj;
	Abonent* ptrAbonent;
public:
	Telbase();
	~Telbase();
	void createAbonent(const char* name, ulong telHome = 0, ulong telWork = 0, std::string otherInfo = "empty");
	void changeAbonent(const char* name);
	void changeAbonent(ulong telHome_telWork, int keys = 0);
	void changeAbonent(std::string otherInfo);
	//void deleteAbonent();
	//void showAbonent();
	void getAbonent(){ ptrAbonent->sh(); }


};

#endif


