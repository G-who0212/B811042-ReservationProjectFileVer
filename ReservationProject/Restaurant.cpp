#include "Restaurant.h"

Restaurant::Restaurant() {
	date = new RestaurantDate[7];
	date[0].setDate("3/1");
	date[1].setDate("3/2");
	date[2].setDate("3/3");
	date[3].setDate("3/4");
	date[4].setDate("3/5");
	date[5].setDate("3/6");
	date[6].setDate("3/7");
}

Restaurant::~Restaurant() {
	delete[] date;
}

void Restaurant::showStatistics(RestaurantInfo rMember) {
	cout << "회원님의 예약 횟수를 보기 : 1 / 좌석별 예약된 횟수를 보기 : 2 >> ";
	int whatStatistics;
	cin >> whatStatistics;
	if (whatStatistics == 1) {
		cout << "회원님께서는 " << rMember.getInfoReservationNum() << "회 예약하셨습니다." << endl;
	}
	else {
		for (int i = 0; i < 8; ++i) {
			cout << i + 1 << "번째 자리는 " << seatResNum[i] << "회 예약되었습니다." << endl;
		}
	}
}

void Restaurant::RestaurantReservation(RestaurantInfo &rMember, RestaurantWalkInSeat &walkin) {
	cout << "예약하실 손님이시면 : 1, Walk In 손님이시면 : 2 >> ";
	int ResOrWalk;
	cin >> ResOrWalk;
	cout << "3월 1일 : 1 / 3월 2일 : 2 / 3월 3일 : 3 / 3월 4일 : 4 / 3월 5일 : 5 / 3월 6일 : 6 / 3월 7일 : 7 >> ";
	int whatDate;
	cin >> whatDate;
	cout << "9시~10시 : 1 / 10시~11시 : 2 / 11시~12시 : 3 / 7시~8시 : 4 / 8시~9시 : 5 / 9시~10시 : 6 >> ";
	int whatTime;
	cin >> whatTime;
	switch (ResOrWalk) {
	case 1:
		if (rMember.getInfoPeopleNum() <= 2) {
			cout << "이 식당의 자리는 2인석 3자리, 4인석 3자리, 6인석 1자리로 총 7자리 입니다." << endl;
			cout << "인원이 2명이하이므로 모든 좌석 사용이 가능합니다. 모두 보여드리겠습니다." << endl;
			for (int i = 0; i < 7; ++i) {
				cout << date[whatDate - 1].getName(whatTime - 1, i) << ' ';
			}
			cout << '\n';
			cout << "좌석번호를 입력해주세요. (1, 2, 3, 4, 5, 6, 7) >> ";
			int whatSeat;
			cin >> whatSeat;
			date[whatDate - 1].setName(whatTime - 1, whatSeat - 1, rMember.getInfoName());
			rMember.SetInfoPeopleNum(rMember.getInfoPeopleNum() + 1);

			string tDate = "3월 " + to_string(whatDate) + "일";
			string tTime;
			if (whatTime == 1) tTime = "9시~10시";
			else if (whatTime == 2) tTime = "10시~11시";
			else if (whatTime == 3) tTime = "11시~12시";
			else if (whatTime == 4) tTime = "7시~8시";
			else if (whatTime == 5) tTime = "8시~9시";
			else if (whatTime == 6) tTime = "9시~10시";
			string tSeat = to_string(whatSeat);
			string data = "식당 예약 프로그램 : " + rMember.getInfoName() + "님은" + tDate + " " + tTime + ' ' + tSeat + "번 자리를 예약하였습니다.";
			ofstream fout("reservationData.txt", ios::out | ios::app);
			fout << data << endl;
			fout.close();

			++seatResNum[whatSeat - 1];
		}
		else if (rMember.getInfoPeopleNum() <= 4) {
			cout << "이 식당의 자리는 2인석 3자리, 4인석 3자리, 6인석 1자리로 총 7자리 입니다." << endl;
			cout << "인원이 3명 이상이므로 2인석 자리인 1, 2, 3번 자리는 제외하고 보여드리겠습니다." << endl;
			for (int i = 3; i < 7; ++i) {
				cout << date[whatDate - 1].getName(whatTime - 1, i) << ' ';
			}
			cout << '\n';
			cout << "좌석번호를 입력해주세요. (4, 5, 6, 7) >> ";
			int whatSeat;
			cin >> whatSeat;
			date[whatDate - 1].setName(whatTime - 1, whatSeat - 1, rMember.getInfoName());
			rMember.SetInfoPeopleNum(rMember.getInfoPeopleNum() + 1);
			string tDate = "3월 " + to_string(whatDate) + "일";
			string tTime;
			if (whatTime == 1) tTime = "9시~10시";
			else if (whatTime == 2) tTime = "10시~11시";
			else if (whatTime == 3) tTime = "11시~12시";
			else if (whatTime == 4) tTime = "7시~8시";
			else if (whatTime == 5) tTime = "8시~9시";
			else if (whatTime == 6) tTime = "9시~10시";
			string tSeat = to_string(whatSeat);
			string data = "식당 예약 프로그램 : " + rMember.getInfoName() + "님은" + tDate + " " + tTime + ' ' + tSeat + "번 자리를 예약하였습니다.";
			ofstream fout("reservationData.txt", ios::out | ios::app);
			fout << data << endl;
			fout.close();
			++seatResNum[whatSeat - 1];
		}
		else if (rMember.getInfoPeopleNum() <= 6) {
			cout << "이 식당의 자리는 2인석 3자리, 4인석 3자리, 6인석 1자리로 총 7자리 입니다." << endl;
			for (int i = 6; i < 7; ++i) {
				if (date[whatDate - 1].getName(whatTime - 1, i) == "---") {
					cout << "현재 인원으로 가능한 테이블은 6인석 하나입니다. 6인석 테이블로 예약해드리겠습니다." << '\n';
					date[whatDate - 1].setName(whatTime - 1, 6, rMember.getInfoName());
					rMember.SetInfoPeopleNum(rMember.getInfoPeopleNum() + 1);
					++seatResNum[6];
					string tDate = "3월 " + to_string(whatDate) + "일";
					string tTime;
					if (whatTime == 1) tTime = "9시~10시";
					else if (whatTime == 2) tTime = "10시~11시";
					else if (whatTime == 3) tTime = "11시~12시";
					else if (whatTime == 4) tTime = "7시~8시";
					else if (whatTime == 5) tTime = "8시~9시";
					else if (whatTime == 6) tTime = "9시~10시";
					string tSeat = to_string(7);
					string data = "식당 예약 프로그램 : " + rMember.getInfoName() + "님은" + tDate + " " + tTime + ' ' + tSeat + "번 자리를 예약하였습니다.";
					ofstream fout("reservationData.txt", ios::out | ios::app);
					fout << data << endl;
					fout.close();
				}
				else {
					cout << "6인석 자리는 모두 찼습니다. 예약이 불가능할 것 같습니다. 죄송합니다." << endl;
				}
			}
		}
		else cout << "이 식당의 수용가능 인원은 최대 6명입니다. 예약이 불가능할 것 같습니다. 죄송합니다." << endl;
		break;
	case 2:
		int WaitOrNot = walkin.addWaiter(rMember);
		if (WaitOrNot == 1) {
			while (1) {
				cout << "잠시만 기다려 주십시오." << '\n';
				cout << "(매니저는 2명 테이블 식사가 끝나면 1, 4번 테이블 식사가 끝나면 2, 3번 테이블 식사가 끝나면 3을 누른다. / 프로그램을 종료하려면 0을 누른다.)" << '\n';
				int n;
				cin >> n;
				if (n == 0) break;
				else {
					walkin.callWaiter(n);
				}
			}
		}
		break;
	}
}

void Restaurant::setDate(int index, string date) {
	this->date[index].setDate(date);
}
string Restaurant::getDate(int index) {
	return date[index].getDate();
}
void Restaurant::setTime(int index1, int index2, string time) {
	date[index1].setTime(index2, time);
}
string Restaurant::getTime(int index1, int index2) {
	return date[index1].getTime(index2);
}
void Restaurant::setCapacity(int index1, int index2, int index3, int capacity) {
	date[index1].setCapacity(index2, index3, capacity);
}
int Restaurant::getCapacity(int index1, int index2, int index3) {
	return date[index1].getCapacity(index2, index3);
}
void Restaurant::setName(int index1, int index2, int index3, string name) {
	date[index1].setName(index2, index3, name);
}
string Restaurant::getName(int index1, int index2, int index3) {
	return date[index1].getName(index2, index3);
}
void Restaurant::setSeatResNum(int index, int seatResNum) {
	this->seatResNum[index] = seatResNum;
}
int Restaurant::getSeatResNum(int index) {
	return seatResNum[index];
}

