#include "Where.h"

Where::Where() {
	date = new Date[7];
	date[0].setDate("3岿 1老");
	date[1].setDate("3岿 2老");
	date[2].setDate("3岿 3老");
	date[3].setDate("3岿 4老");
	date[4].setDate("3岿 5老");
	date[5].setDate("3岿 6老");
	date[6].setDate("3岿 7老");
}
Where::~Where() {
	delete[] date;
}
void Where::setDepart(string depart) {
	this->depart = depart;
}
string Where::getDepart() {
	return depart;
}
void Where::setDest(string dest) {
	this->dest = dest;
}
string Where::getDest() {
	return dest;
}
void Where::setDate(int index, string date) {
	this->date[index].setDate(date);
}
string Where::getDate(int index) {
	return date[index].getDate();
}
void Where::setTime(int index1, int index2, string time) {
	date[index1].setTime(index2, time);
}
string Where::getTime(int index1, int index2) {
	return date[index1].getTime(index2);
}
void Where::setName(int index1, int index2, int index3, string name) {
	date[index1].setName(index2, index3, name);
}
string Where::getName(int index1, int index2, int index3) {
	return date[index1].getName(index2, index3);
}
void Where::setSeatClass(int index1, int index2, int index3, string seatClass) {
	date[index1].setSeatClass(index2, index3, seatClass);
}
string Where::getSeatClass(int index1, int index2, int index3) {
	return date[index1].getSeatClass(index2, index3);
}
void Where::setCost(int index1, int index2, int index3, int cost) {
	date[index1].setCost(index2, index3, cost);
}
int Where::getCost(int index1, int index2, int index3) {
	return date[index1].getCost(index2, index3);
}