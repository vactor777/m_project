#include <iostream>
#include "telbase.h"

int main() {
	//g
//	setlocale(LC_ALL, "rus");
	using std::cout;
	using std::endl;
	

	Telbase my;
	my.createAbonent("Viktor");
	my.createAbonent("Stepan");
	my.createAbonent("Angol");
	my.createAbonent("Lera");
	my.getAbonent();
	cout << my.getCount() << endl;
	
//	my.deleteAbonent("Lera");
//	my.deleteAbonent("alex");
	my.deleteAbonent("Lera");
	my.deleteAbonent("Angol");
	cout << endl;
	cout << endl;
	cout << endl;
	my.getAbonent();

	cout << endl;
	cout << endl;
	cout << endl;
	my.createAbonent("alex");
	my.createAbonent("gg");
	my.changeName("Viktor", "Mitja");
	my.changeTelephone("Stepan", 865456);
	my.getAbonent();
	my.deleteAbonent("Mitja");
	my.deleteAbonent("gg");
	cout << endl;
	cout << endl;
	my.getAbonent();
	
	cout << my.getCount() << endl;
	//ss
	return 0;
}