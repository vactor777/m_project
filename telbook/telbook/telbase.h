#ifndef TELBASE_H
#define TELBASE_H
#include <string>
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
};
class telbase
{
private:
	Abonent* ptrAbonent;
public:

};

#endif


