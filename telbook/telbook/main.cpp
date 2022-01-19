#include <iostream>
#include "telbase.h"

int main() {
	//g
//	setlocale(LC_ALL, "rus");
	using std::cout;
	using std::endl;
	Abonent myss;

	Telbase my;
	my.createAbonent("Viktor");
	my.changeName("alex");
	my.changeTelephone(89441244353, 1);
	my.changeTelephone(89133683208);
	my.changeOtherInfo("This is my abonent");
	my.createAbonent("Stepan");
	my.createAbonent("Angol");
	my.createAbonent("Lera");
	my.getAbonent();
	cout << my.getCount() << endl;
	my.findAbonent("Stepan");
	//ss
	return 0;
}