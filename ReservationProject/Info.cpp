#include "Info.h"

Info::Info() {
	this->reservationNum = 0;
}

void Info::setInfoName(string name) {
	this->name = name;
}

string Info::getInfoName() {
	return name;
}

void Info::setInfoID(string ID) {
	this->ID = ID;
}

string Info::getInfoID() {
	return ID;
}

void Info::setInfoPW(string PW) {
	this->PW = PW;
}

string Info::getInfoPW() {
	return PW;
}

void Info::setInfoReservationNum(int reservationNum) {
	this->reservationNum = reservationNum;
}

int Info::getInfoReservationNum() {
	return reservationNum;
}
