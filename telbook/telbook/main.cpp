#include <iostream>
#include "telbase.h"

int main() {
	//g
	setlocale(LC_ALL, "rus");
	using std::cout;
	cout << "enter commmand: ";
	
	Telbase my;
	my.createAbonent("Viktor");
	my.getAbonent();
	my.changeName("alex");
	my.changeTelephone(89441244353, 1);
	my.changeTelephone(89133683208);
	my.changeOtherInfo("This is my abonent");
	my.getAbonent();
	//ss
	return 0;
}