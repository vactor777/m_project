#ifndef TELBASE_H
#define TELBASE_H
#include <string>
#include <iostream>
class Abonent {
private:	
	char* name_;
	long telHome_;
	long telWork_;
	std::string otherInfo_;
public:
	Abonent();
	Abonent(const char* name, long telHome = 0, long telWork = 0, std::string otherInfo = "empty");
	~Abonent();
	void sh(){std::cout << name_;};
	
};
class Telbase
{
private:
	Abonent* ptrAbonent;
public:
	Telbase();
	~Telbase();
	void createAbonent(const char* name);
	void deleteAbonent();
	void showAbonent();
	void getAbonent(){ ptrAbonent->sh(); }


};

#endif


