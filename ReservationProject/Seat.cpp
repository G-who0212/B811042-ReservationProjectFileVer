#include "Seat.h"

Seat::Seat() {
	name = { "---" };
}
void Seat::setName(string name) {
	this->name = name;
}
string Seat::getName() {
	return name;
}
void Seat::setSeatClass(string seatClass) {
	this->seatClass = seatClass;
}
string Seat::getSeatClass() {
	return seatClass;
}
void Seat::setCost(int cost) {
	this->cost = cost;
}
int Seat::getCost() {
	return cost;
}