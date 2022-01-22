#ifndef TELBASE_H
#define TELBASE_H
#include <string>
#include <iostream>

class Abonent {
private:	
	char* name_;
	std::string telHome_;
	std::string telWork_;
	std::string otherInfo_;
	Abonent* ptr_next_Obj_;
public:
	Abonent();
	//������� ��������������
	Abonent(const char* name, std::string telHome, std::string telWork, std::string otherInfo);
	~Abonent();
	void setName(const char* name);
	void setTel(std::string telephone, int keys);
	void setInfo(const std::string otherInfo);
	inline void setPtrNextObj(Abonent* ptr) { ptr_next_Obj_ = ptr; };
	inline Abonent* getNextObj() const { return ptr_next_Obj_; };
	inline char* getName() const { return name_; };
	void to_string() const;//change to return function
	std::string to_string(int keys) const ;
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
	void createAbonent(const char* name, std::string telHome = "000", std::string telWork = "000", std::string otherInfo = "empty");
	void changeName(const char* name, const char* new_name);
	void changeTelephone(const char* name, std::string telHome_telWork, int keys = 0);
	void changeOtherInfo(const char* name, const std::string otherInfo);
	Abonent* findAbonent(const char* name);
	void deleteAbonent(const char* name);
	void getAbonent();
	int getCount() { return countObj; }
	void writeToFile();
	void readToFile();
	//void readToFile();
	

};

#endif


