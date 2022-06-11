#include "AirplaneInfo.h"

AirplaneInfo::AirplaneInfo() {
	budget = 0;
	mileage = 0;
}

void AirplaneInfo::setInfoBudget(int budget) {
	this->budget = budget;
}

int AirplaneInfo::getInfoBudget() {
	return budget;
}

void AirplaneInfo::setInfoMileage(int mileage) {
	this->mileage = mileage;
}

int AirplaneInfo::getInfoMileage() {
	return mileage;
}
