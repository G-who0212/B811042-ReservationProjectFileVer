#include "RestaurantDate.h"

RestaurantDate::RestaurantDate() {
	time = new RestaurantTime[6];
	time[0].setTime("12��");
	time[1].setTime("1��");
	time[2].setTime("2��");
	time[3].setTime("7��");
	time[4].setTime("8��");
	time[5].setTime("9��");
}

RestaurantDate::~RestaurantDate() {
	delete[] time;
}

void RestaurantDate::setDate(string date) {
	this->date = date;
}
string RestaurantDate::getDate() {
	return date;
}
void RestaurantDate::setTime(int index, string time) {
	this->time[index].setTime(time);
}
string RestaurantDate::getTime(int index) {
	return this->time[index].getTime();
}
void RestaurantDate::setCapacity(int index1, int index2, int capacity) {
	time[index1].setCapacity(index2, capacity);
}
int RestaurantDate::getCapacity(int index1, int index2) {
	return time[index1].getCapacity(index2);
}
void RestaurantDate::setName(int index1, int index2, string name) {
	time[index1].setName(index2, name);
}
string RestaurantDate::getName(int index1, int index2) {
	return time[index1].getName(index2);
}