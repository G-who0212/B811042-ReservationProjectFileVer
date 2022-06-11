#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "Where.h"
#include "MemberData.h"
#include <fstream>
class Airplane {
	Where where[5][5];
	int seatResNum[8] = {0};
public:
	Airplane();

	void showStatistics(AirplaneInfo aMember);

	void AirplaneReservation(AirplaneInfo &aMember);

	void AirplaneCancel(AirplaneInfo &aMember);

	void AirplaneLook(AirplaneInfo aMember);

	void AirplaneEnd();

};
	

#endif