#include "LibraryTime.h"

void LibraryTime::setTime(string time) {
	this->time = time;
}
string LibraryTime::getTime() {
	return time;
}
void LibraryTime::setName(int indexX, int indexY, string name) {
	seat[indexX][indexY].setName(name);
}
string LibraryTime::getName(int indexX, int indexY) {
	return seat[indexX][indexY].getName();
}
void LibraryTime::setSex(int indexX, int indexY, string sex) {
	seat[indexX][indexY].setSex(sex);
}
string LibraryTime::getSex(int indexX, int indexY) {
	return seat[indexX][indexY].getSex();
}