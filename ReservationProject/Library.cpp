#include "Library.h"

Library::Library() {
	date = new LibraryDate[7];
	date[0].setDate("3월 1일");
	date[1].setDate("3월 2일");
	date[2].setDate("3월 3일");
	date[3].setDate("3월 4일");
	date[4].setDate("3월 5일");
	date[5].setDate("3월 6일");
	date[6].setDate("3월 7일");

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
	cout << "회원님의 예약 횟수를 보기 : 1 / 좌석별 예약된 횟수를 보기 : 2 / 성별 예약 횟수 : 3 >> ";
	int whatStatistics;
	cin >> whatStatistics;
	if (whatStatistics == 1) {
		cout << "회원님께서는 " << lMember.getInfoReservationNum() << "회 예약하셨습니다." << endl;
	}
	else if (whatStatistics == 2) {
		cout << "자리별 예약 횟수를 보여드리겠습니다." << endl;
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				cout << seatResNum[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else {
		cout << "남자 예약 횟수 : " << getMale() << endl;
		cout << "여자 예약 횟수 : " << getFemale() << endl;
	}
}

void Library::sameGender(int& newSeatNum, int newDate, int newTime[], int i) {
	cout << "앞뒤, 양옆, 같은 성의 사용자를 배치할 수 없습니다." << '\n';
	cout << "자리 예약 현황을 보여드리겠습니다." << '\n';
	for (int j = 0; j < 15; ++j) {//자리 보여주기
		for (int k = 0; k < 15; ++k) {
			cout << date[newDate - 1].getName(newTime[i] - 1, j, k) << '/' << date[newDate - 1].getSex(newTime[i] - 1, j, k) << ' ';
		}
		cout << '\n';
	}
	cout << "그에 따른 좌석번호를 보여드리겠습니다." << '\n';
	for (int m = 0; m < 15; ++m) {
		for (int n = 1; n <= 15; ++n) {
			cout << m * 15 + n << ' ';
		}
		cout << '\n';
	}
	cout << "좌석번호를 선택해주세요." << '\n';
	cin >> newSeatNum;
}

void Library::differentGender(int newDate, int newTime[], int newSeatNum, int i, LibraryInfo &lMember) {
	date[newDate - 1].setName(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15, lMember.getInfoName());
	date[newDate - 1].setSex(newTime[i] - 1, (newSeatNum - 1) / 15, (newSeatNum - 1) % 15, lMember.getInfoSex());
	lMember.setInfoReservationNum(lMember.getInfoReservationNum() + 1);

		string tDate = "3월 " + to_string(newDate) + "일";
		string tTime = to_string(8 + newTime[i]) +  "~" + to_string(9 + newTime[i]);
		string tSeat = to_string(newSeatNum);
		string data1 = "도서관 예약 프로그램 : " + lMember.getInfoName() + "님은" + ' ' + tDate + " " + tTime + ' ' + tSeat + "번 자리를 예약하였습니다.";
		ofstream fout("reservationData.txt", ios::out | ios::app);
		fout << data1 << endl;
		fout.close();

	++seatResNum[(newSeatNum - 1) / 15][(newSeatNum - 1) % 15];
	if (lMember.getInfoSex() == "남") {
		addMale();
	}
	else if (lMember.getInfoSex() == "여") {
		addFemale();
	}
	cout << "예약 확인되었습니다." << '\n';
}

void Library::LibraryReservation(LibraryInfo &lMember) {
	cout << "날짜를 골라주세요" << '\n';
	cout << "3월 1일 : 1, 3월 2일 : 2, 3월 3일 : 3, 3월 4일 : 4, 3월 5일 : 5, 3월 6일 : 6, 3월 7일 : 7 >> ";
	int newDate;
	cin >> newDate;

	int LibrarySum = 0;//총 예약시간
	cout << "시간을 골라주세요" << '\n';
	int newTime[4] = { -1 };
	for (int i = 0; i < 4; ++i) {
		cout << "예약 중단 : 0, 09시~10시 : 1, 10시~11시 : 2, 11시~12시 : 3, 12시~13시 : 4, 13시~14시 : 5, 14시~15시 : 6, 15시~16시 : 7, 16시~17시 : 8, 17시~18시 : 9, 18시~19시 : 10, 19시~20시 : 11, 20시~21시 : 12, 21시~22시 : 13, 22시~23시 : 14" << '\n';
		cin >> newTime[i];
		if (newTime[i] == 0) {
			newTime[i] = -1;
			LibrarySum = i;
			cout << "프로그램을 종료하겠습니다." << '\n';
			break;
		}
		cout << "자리 예약 현황을 보여드리겠습니다." << '\n';
		for (int j = 0; j < 15; ++j) {//자리 보여주기
			for (int k = 0; k < 15; ++k) {
				cout << date[newDate - 1].getName(newTime[i] - 1, j, k) << '/' << date[newDate - 1].getSex(newTime[i] - 1, j, k) << ' ';
			}
			cout << '\n';
		}
		cout << "그에 따른 좌석번호를 보여드리겠습니다." << '\n';
		for (int m = 0; m < 15; ++m) {
			for (int n = 1; n <= 15; ++n) {
				cout << m * 15 + n << ' ';
			}
			cout << '\n';
		}
		cout << "좌석번호를 선택해주세요." << '\n';
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
		if (i == 3) cout << "예약 가능 시간이 없습니다. 프로그램을 종료하겠습니다." << '\n';
	}
}