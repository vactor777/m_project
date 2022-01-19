#include <iostream>
#include "telbase.h"
int main() {
	//g
	using std::cout;
	cout << "enter commmand: ";
	

	Telbase my;
	my.createAbonent("Viktor");
	my.getAbonent();
	my.changeAbonent("alex");
	my.changeAbonent(8888, 1);
	my.getAbonent();
	//ss
	return 0;
}