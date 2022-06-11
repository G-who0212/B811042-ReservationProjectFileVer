#include "RestaurantTIme.h"

RestaurantTime::RestaurantTime() {
	resSeat = new RestaurantSeat[7];
	resSeat[0].setCapacity(2);
	resSeat[1].setCapacity(2);
	resSeat[2].setCapacity(2);
	resSeat[3].setCapacity(4);
	resSeat[4].setCapacity(4);
	resSeat[5].setCapacity(4);
	resSeat[6].setCapacity(6);
}

RestaurantTime::~RestaurantTime() {
	delete[] resSeat;
}
void RestaurantTime::setTime(string time) {
	this->time = time;
}
string RestaurantTime::getTime() {
	return time;
}
void RestaurantTime::setCapacity(int index, int capacity) {
	resSeat[index].setCapacity(capacity);
}
int RestaurantTime::getCapacity(int index) {
	return resSeat[index].getCapacity();
}
void RestaurantTime::setName(int index, string name) {
	resSeat[index].setName(name);
}
string RestaurantTime::getName(int index) {
	return resSeat[index].getName();
}