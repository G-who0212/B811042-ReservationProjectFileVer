#include "Date.h"

Date::Date() {
	time = new Time[3];
	time[0].setTime("07½Ã");
	time[1].setTime("12½Ã");
	time[2].setTime("17½Ã");
}

Date::~Date() {
	delete[] time;
}

void Date::setDate(string date) {
	this->date = date;
}

string Date::getDate() {
	return date;
}

void Date::setTime(int index, string time) {
	this->time[index].setTime(time);
}

string Date::getTime(int index) {
	return time[index].getTime();
}

void Date::setName(int index1, int index2, string name) {
	time[index1].setName(index2, name);
}

string Date::getName(int index1, int index2) {
	return time[index1].getName(index2);
}

void Date::setSeatClass(int index1, int index2, string seatClass) {
	time[index1].setSeatClass(index2, seatClass);
}

string Date::getSeatClass(int index1, int index2) {
	return time[index1].getSeatClass(index2);
}

void Date::setCost(int index1, int index2, int cost) {
	time[index1].setCost(index2, cost);
}

int Date::getCost(int index1, int index2) {
	return time[index1].getCost(index2);
}
