#include "Time.h"

Time::Time() {
	seat = new Seat[8];
	seat[0].setSeatClass("Business");
	seat[0].setCost(250000);
	seat[1].setSeatClass("Business");
	seat[1].setCost(250000);
	seat[2].setSeatClass("Economy");
	seat[2].setCost(100000);
	seat[3].setSeatClass("Economy");
	seat[3].setCost(100000);
	seat[4].setSeatClass("Economy");
	seat[4].setCost(100000);
	seat[5].setSeatClass("Economy");
	seat[5].setCost(100000);
	seat[6].setSeatClass("Economy");
	seat[6].setCost(100000);
	seat[7].setSeatClass("Economy");
	seat[7].setCost(100000);
}

Time::~Time() {
	delete[] seat;
}
void Time::setTime(string time) {
	this->time = time;
}
string Time::getTime() {
	return time;
}
void Time::setName(int index, string name) {
	seat[index].setName(name);
}
string Time::getName(int index) {
	return seat[index].getName();
}
void Time::setSeatClass(int index, string seatClass) {
	seat[index].setSeatClass(seatClass);
}
string Time::getSeatClass(int index) {
	return seat[index].getSeatClass();
}
void Time::setCost(int index, int cost) {
	seat[index].setCost(cost);
}
int Time::getCost(int index) {
	return seat[index].getCost();
}