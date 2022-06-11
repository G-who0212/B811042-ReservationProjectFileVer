#pragma once//¿Ï·á
#ifndef INFO_H
#define INFO_H
#include <iostream>
#include <string>
using namespace std;

class Info {
	string name;
	string ID;
	string PW;
	int reservationNum;
public:
	Info();
	void setInfoName(string name);

	string getInfoName();

	void setInfoID(string ID);

	string getInfoID();

	void setInfoPW(string PW);

	string getInfoPW();

	void setInfoReservationNum(int reservationNum);

	int getInfoReservationNum();
};

#endif