#include "LibrarySeat.h"

LibrarySeat::LibrarySeat() {
	name = "---";
	sex = "����";
}

void LibrarySeat::setName(string name) {
	this->name = name;
}
string LibrarySeat::getName() {
	return name;
}
void LibrarySeat::setSex(string sex) {
	this->sex = sex;
}
string LibrarySeat::getSex() {
	return sex;
}