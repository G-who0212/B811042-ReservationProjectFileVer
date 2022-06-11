#include "LibraryDate.h"

LibraryDate::LibraryDate() {
	time = new LibraryTime[14];
	time[0].setTime("09��~10��");
	time[1].setTime("10��~11��");
	time[2].setTime("11��~12��");
	time[3].setTime("12��~13��");
	time[4].setTime("13��~14��");
	time[5].setTime("14��~15��");
	time[6].setTime("15��~16��");
	time[7].setTime("16��~17��");
	time[8].setTime("17��~18��");
	time[9].setTime("18��~19��");
	time[10].setTime("19��~20��");
	time[11].setTime("20��~21��");
	time[12].setTime("21��~22��");
	time[13].setTime("22��~23��");
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