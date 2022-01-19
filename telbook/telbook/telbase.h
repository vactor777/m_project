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
	void changeAbonent(Abonent& abon, const char* name);
	void changeAbonent(Abonent& abon, ulong telHome);
	void changeAbonent(Abonent& abon, ulong telWork);
	void changeAbonent(Abonent& abon, std::string otherInfo);
	//void deleteAbonent();
	//void showAbonent();
	void getAbonent(){ ptrAbonent->sh(); }


};

#endif


