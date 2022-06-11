#include "MemberData.h"

void MemberData::addAirplaneInfo(string id, string pw, string name, int budget) {
	AirplaneInfo addA;
	addA.setInfoID(id);
	addA.setInfoPW(pw);
	addA.setInfoName(name);
	addA.setInfoBudget(budget);
	AI.push_back(addA);
}

AirplaneInfo& MemberData::getAirplaneInfo(int index) {
	return AI[index];
}
int MemberData::getAirplaneInfoSize() {
	return AI.size();
}
void MemberData::addRestaurantInfo(string id, string pw, string name, int age, int peopleNum) {
	RestaurantInfo addR;
	addR.setInfoID(id);
	addR.setInfoPW(pw);
	addR.setInfoName(name);
	addR.setInfoAge(age);
	addR.SetInfoPeopleNum(peopleNum);
	RI.push_back(addR);
}
RestaurantInfo& MemberData::getRestaurantInfo(int index) {
	return RI[index];
}
int MemberData::getRestaurantInfoSize() {
	return RI.size();
}
void MemberData::addLibraryInfo(string id, string pw, string name, int age, Family family, int unit, int LID, string sex) {
	LibraryInfo addL;
	addL.setInfoID(id);
	addL.setInfoPW(pw);
	addL.setInfoName(name);
	addL.setInfoAge(age);
	addL.setInfoFamily(family);
	addL.setInfoUnit(unit);
	addL.setInfoLID(LID);
	addL.setInfoSex(sex);
	LI.push_back(addL);
}
LibraryInfo& MemberData::getLibraryInfo(int index) {
	return LI[index];
}
int MemberData::getLibraryInfoSize() {
	return LI.size();
}