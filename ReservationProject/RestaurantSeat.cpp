#include "RestaurantSeat.h"

RestaurantSeat::RestaurantSeat() {
	name = { "---" };
}

void RestaurantSeat::setCapacity(int capacity) {
	this->capacity = capacity;
}
int RestaurantSeat::getCapacity() {
	return capacity;
}
void RestaurantSeat::setName(string name) {
	this->name = name;
}
string RestaurantSeat::getName() {
	return name;
}