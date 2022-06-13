#include "Library.h"

Library::Library() {
	date = new LibraryDate[7];
	date[0].setDate("3�� 1��");
	date[1].setDate("3�� 2��");
	date[2].setDate("3�� 3��");
	date[3].setDate("3�� 4��");
	date[4].setDate("3�� 5��");
	date[5].setDate("3�� 6��");
	date[6].setDate("3�� 7��");

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			seatResNum[i][j] = 0;
		}
	}
	male = 0;
	female = 0;
}

Library::~Library() {
	delete[] date;
}

void Library::setDate(int index, string date) {
	this->date[index].setDate(date);
}
string Library::getDate(int index) {
	return date[index].getDate();
}
void Library::setTime(int index1, int index2, string time) {
	date[index1].setTime(index2, time);
}
string Library::getTime(int index1, int index2) {
	return date[index1].getTime(index2);
}
void Library::setName(int index1, int index2, int indexX, int indexY, string name) {
	date[index1].setName(index2, indexX, indexY, name);
}
string Library::getName(int index1, int index2, int indexX, int indexY) {
	return date[index1].getName(index2, indexX, indexY);
}
void Library::setSex(int index1, int index2, int indexX, int indexY, string sex) {
	date[index1].setSex(index2, indexX, indexY, sex);
}
string Library::getSex(int index1, int index2, int indexX, int indexY) {
	return date[index1].getSex(index2, indexX, indexY);
}

void Library::addMale() {
	++male;
}
int Library::getMale() {
	return male;
}
void Library::addFemale() {
	++female;
}
int Library::getFemale() {
	return female;
}

void Library::showStatistics(LibraryInfo lMember) {
	cout << "ȸ������ ���� Ƚ���� ���� : 1 / �¼��� ����� Ƚ���� ���� : 2 / ���� ���� Ƚ�� : 3 >> ";
	int whatStatistics;
	cin >> whatStatistics;
	if (whatStatistics == 1) {
		cout << "ȸ���Բ����� " << lMember.getInfoReservationNum() << "ȸ �����ϼ̽��ϴ�." << endl;
	}
	else if (whatStatistics == 2) {
		cout << "�ڸ��� ���� Ƚ���� �����帮�ڽ��ϴ�." << endl;
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				cout << seatResNum[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else {
		cout << "���� ���� Ƚ�� : " << getMale() << endl;
		cout << "���� ���� Ƚ�� : " << getFemale() << endl;
	}
}

void Library::sameGender(int& newSeatNum, int newDate, int newTime[], int i) {
	cout << "�յ�, �翷, ���� ���� ����ڸ� ��ġ�� �� �����ϴ�." << '\n';
	cout << "�ڸ� ���� ��Ȳ�� �����帮�ڽ��ϴ�." << '\n';
	for (int j = 0; j < 15; ++j) {//�ڸ� �����ֱ�
		for (int k = 0; k < 15; ++k) {
			cout << date[newDate - 1].getName(newTime[i] - 1, j, k) << '/' << date[newDate - 1].getSex(newTime[i] - 1, j, k) << ' ';
		}
		cout << '\n';
	}
	cout << "�׿� ���� �¼���ȣ�� �����帮�ڽ��ϴ�." << '\n';
	for (int m = 0; m < 15; ++m) {
		for (int n = 1; n <= 15; ++n) {
			cout << m * 15 + n << ' ';
		}
		cout << '\n';
	}
	cout << "�¼���ȣ�� �������ּ���." << '\n';
	cin >> newSeatNum;
}

void Library::differentGender(int newDate, int newTime[], int newSeatNum, int i, LibraryInfo &lMember) {
	date[newDate - 1].setName(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15, lMember.getInfoName());
	date[newDate - 1].setSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15, lMember.getInfoSex());
	lMember.setInfoReservationNum(lMember.getInfoReservationNum() + 1);

		string tDate = "3�� " + to_string(newDate) + "��";
		string tTime = to_string(8 + newTime[i]) +  "~" + to_string(9 + newTime[i]);
		string tSeat = to_string(newSeatNum);
		string data1 = "������ ���� ���α׷� : " + lMember.getInfoName() + "����" + ' ' + tDate + " " + tTime + ' ' + tSeat + "�� �ڸ��� �����Ͽ����ϴ�.";
		ofstream fout("reservationData.txt", ios::out | ios::app);
		fout << data1 << endl;
		fout.close();

	++seatResNum[(newSeatNum - 1) / 15][(newSeatNum - 1) % 15];
	if (lMember.getInfoSex() == "��") {
		addMale();
	}
	else if (lMember.getInfoSex() == "��") {
		addFemale();
	}
	cout << "���� Ȯ�εǾ����ϴ�." << '\n';
}

void Library::LibraryReservation(LibraryInfo &lMember) {
	cout << "��¥�� ����ּ���" << '\n';
	cout << "3�� 1�� : 1, 3�� 2�� : 2, 3�� 3�� : 3, 3�� 4�� : 4, 3�� 5�� : 5, 3�� 6�� : 6, 3�� 7�� : 7 >> ";
	int newDate;
	cin >> newDate;

	int LibrarySum = 0;//�� ����ð�
	cout << "�ð��� ����ּ���" << '\n';
	int newTime[4] = { -1 };
	for (int i = 0; i < 4; ++i) {
		cout << "���� �ߴ� : 0, 09��~10�� : 1, 10��~11�� : 2, 11��~12�� : 3, 12��~13�� : 4, 13��~14�� : 5, 14��~15�� : 6, 15��~16�� : 7, 16��~17�� : 8, 17��~18�� : 9, 18��~19�� : 10, 19��~20�� : 11, 20��~21�� : 12, 21��~22�� : 13, 22��~23�� : 14" << '\n';
		cin >> newTime[i];
		if (newTime[i] == 0) {
			newTime[i] = -1;
			LibrarySum = i;
			cout << "���α׷��� �����ϰڽ��ϴ�." << '\n';
			break;
		}
		cout << "�ڸ� ���� ��Ȳ�� �����帮�ڽ��ϴ�." << '\n';
		for (int j = 0; j < 15; ++j) {//�ڸ� �����ֱ�
			for (int k = 0; k < 15; ++k) {
				cout << date[newDate - 1].getName(newTime[i] - 1, j, k) << '/' << date[newDate - 1].getSex(newTime[i] - 1, j, k) << ' ';
			}
			cout << '\n';
		}
		cout << "�׿� ���� �¼���ȣ�� �����帮�ڽ��ϴ�." << '\n';
		for (int m = 0; m < 15; ++m) {
			for (int n = 1; n <= 15; ++n) {
				cout << m * 15 + n << ' ';
			}
			cout << '\n';
		}
		cout << "�¼���ȣ�� �������ּ���." << '\n';
		int newSeatNum;
		cin >> newSeatNum;
		while (1) {
			if ((newSeatNum % 15 != 1) && (newSeatNum % 15 != 0)) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 - 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 + 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 - 1) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 + 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}
			}
			else if (newSeatNum == 1) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 + 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 + 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}

			}
			else if (newSeatNum == 15) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 + 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 - 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}
			}
			else if (newSeatNum == 211) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 - 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 + 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}
			}
			else if (newSeatNum == 225) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 - 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 - 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}
			}
			else if ((newSeatNum >= 2) && (newSeatNum <= 14)) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 + 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 + 1) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 - 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}

			}
			else if ((newSeatNum >= 212) && (newSeatNum <= 224)) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 - 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 + 1) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 - 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}

			}
			else if (newSeatNum % 15 == 1) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 + 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 - 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 + 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}

			}
			else if (newSeatNum % 15 == 0) {
				if (lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 + 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15 - 1, (newSeatNum - 1) % 15) || lMember.getInfoSex() == date[newDate - 1].getSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15 - 1)) {
					sameGender(newSeatNum, newDate, newTime, i);
				}
				else {
					differentGender(newDate, newTime, newSeatNum, i, lMember);
					break;
				}
			}
		}
		if (i == 3) cout << "���� ���� �ð��� �����ϴ�. ���α׷��� �����ϰڽ��ϴ�." << '\n';
	}
}