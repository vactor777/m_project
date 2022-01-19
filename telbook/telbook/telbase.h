#ifndef TELBASE_H
#define TELBASE_H
#include <string>
#include <iostream>

class Abonent {
private:	
	char* name_;
	unsigned long telHome_;
	unsigned long telWork_;
	std::string otherInfo_;
	Abonent* ptr_next_Obj_;
public:
	Abonent();
	Abonent(const char* name, unsigned long telHome, unsigned long telWork, std::string otherInfo);
	~Abonent();
	void setName(const char* name);
	void setTel(unsigned long telephone, int keys);
	void setInfo(const std::string otherInfo);
	void setPtrNextObj(Abonent* ptr) { ptr_next_Obj_ = ptr; };
	void to_string() const{std::cout << name_ << " " << telHome_ << " " << telWork_ << " " << otherInfo_ << '\n';};
	Abonent* getNextObj() const { return ptr_next_Obj_; };
};
class Telbase
{
private:
	int countObj;
	Abonent* ptrStartAbonent;
	Abonent* ptrAbonent;
public:
	Telbase();
	~Telbase();
	void createAbonent(const char* name, unsigned long telHome = 0, unsigned long telWork = 0, std::string otherInfo = "empty");
	void changeName(const char* name);
	void changeTelephone(unsigned long telHome_telWork, int keys = 0);
	void changeOtherInfo(const std::string otherInfo);
	//void deleteAbonent();
	//void showAbonent();
	void getAbonent();
	int getCount() { return countObj; }

};

#endif


