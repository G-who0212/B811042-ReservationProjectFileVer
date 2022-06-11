#include "LibraryDate.h"

LibraryDate::LibraryDate() {
	time = new LibraryTime[14];
	time[0].setTime("09시~10시");
	time[1].setTime("10시~11시");
	time[2].setTime("11시~12시");
	time[3].setTime("12시~13시");
	time[4].setTime("13시~14시");
	time[5].setTime("14시~15시");
	time[6].setTime("15시~16시");
	time[7].setTime("16시~17시");
	time[8].setTime("17시~18시");
	time[9].setTime("18시~19시");
	time[10].setTime("19시~20시");
	time[11].setTime("20시~21시");
	time[12].setTime("21시~22시");
	time[13].setTime("22시~23시");
}

LibraryDate::~LibraryDate() {
	delete[] time;
}

void LibraryDate::setDate(string date) {
	this->date = date;
}

string LibraryDate::getDate() {
	return date;
}

void LibraryDate::setTime(int index, string time) {
	this->time[index].setTime(time);
}

string LibraryDate::getTime(int index) {
	return time[index].getTime();
}

void LibraryDate::setName(int index, int indexX, int indexY, string name) {
	time[index].setName(indexX, indexY, name);
}

string LibraryDate::getName(int index, int indexX, int indexY) {
	return time[index].getName(indexX, indexY);
}

void LibraryDate::setSex(int index, int indexX, int indexY, string sex) {
	time[index].setSex(indexX, indexY, sex);
}

string LibraryDate::getSex(int index, int indexX, int indexY) {
	return time[index].getSex(indexX, indexY);
}