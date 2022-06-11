#include "RestaurantInfo.h"

RestaurantInfo::RestaurantInfo() {
	age = 0;
	peopleNum = 0;
}
void RestaurantInfo::setInfoAge(int age) {
	this->age = age;
}
int RestaurantInfo::getInfoAge() {
	return age;
}
void RestaurantInfo::SetInfoPeopleNum(int peopleNum) {
	this->peopleNum = peopleNum;
}
int RestaurantInfo::getInfoPeopleNum() {
	return peopleNum;
}