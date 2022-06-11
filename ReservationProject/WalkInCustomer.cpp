#include "WalkInCustomer.h"

WalkInCustomer::WalkInCustomer(string name, int Vsize) {
	this->name = name;
	waitNum = Vsize + 1;
}
void WalkInCustomer::setName(string name) {
	this->name = name;
}
string WalkInCustomer::getName() {
	return name;
}
void WalkInCustomer::setWaitNum(int waitNum) {
	this->waitNum = waitNum;
}
int WalkInCustomer::getWaitNum() {
	return waitNum;
}