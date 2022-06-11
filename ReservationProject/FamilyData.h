#pragma once
#ifndef FAMILYDATA_H
#define FAMILYDATA_H
#include "Family.h"
class FamilyData {
	int registerdFamily;
	Family* family;
public:
	FamilyData();

	~FamilyData();

	void setRegisteredFamily(int registeredFamily);

	int getRegisteredFamily();

	void addFamilyData(Family family);

	Family getFamilyData(int index);
};

#endif