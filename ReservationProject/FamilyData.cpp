#include "FamilyData.h"

FamilyData::FamilyData() {
	registerdFamily = 0;
	family = new Family[300];
}

FamilyData::~FamilyData() {
	delete[] family;
}

void FamilyData::setRegisteredFamily(int registeredFamily) {
	this->registerdFamily = registeredFamily;
}

int FamilyData::getRegisteredFamily() {
	return registerdFamily;
}

void FamilyData::addFamilyData(Family family) {
	this->family[registerdFamily] = family;
}

Family FamilyData::getFamilyData(int index) {
	return family[index];
}
