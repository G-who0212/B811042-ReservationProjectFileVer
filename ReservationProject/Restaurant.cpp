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
	cout << "ȸ������ ���� Ƚ���� ���� : 1 / �¼��� ����� Ƚ���� ���� : 2 >> ";
	int whatStatistics;
	cin >> whatStatistics;
	if (whatStatistics == 1) {
		cout << "ȸ���Բ����� " << rMember.getInfoReservationNum() << "ȸ �����ϼ̽��ϴ�." << endl;
	}
	else {
		for (int i = 0; i < 8; ++i) {
			cout << i + 1 << "��° �ڸ��� " << seatResNum[i] << "ȸ ����Ǿ����ϴ�." << endl;
		}
	}
}

void Restaurant::RestaurantReservation(RestaurantInfo &rMember, RestaurantWalkInSeat &walkin) {
	cout << "�����Ͻ� �մ��̽ø� : 1, Walk In �մ��̽ø� : 2 >> ";
	int ResOrWalk;
	cin >> ResOrWalk;
	cout << "3�� 1�� : 1 / 3�� 2�� : 2 / 3�� 3�� : 3 / 3�� 4�� : 4 / 3�� 5�� : 5 / 3�� 6�� : 6 / 3�� 7�� : 7 >> ";
	int whatDate;
	cin >> whatDate;
	cout << "9��~10�� : 1 / 10��~11�� : 2 / 11��~12�� : 3 / 7��~8�� : 4 / 8��~9�� : 5 / 9��~10�� : 6 >> ";
	int whatTime;
	cin >> whatTime;
	switch (ResOrWalk) {
	case 1:
		if (rMember.getInfoPeopleNum() <= 2) {
			cout << "�� �Ĵ��� �ڸ��� 2�μ� 3�ڸ�, 4�μ� 3�ڸ�, 6�μ� 1�ڸ��� �� 7�ڸ� �Դϴ�." << endl;
			cout << "�ο��� 2�������̹Ƿ� ��� �¼� ����� �����մϴ�. ��� �����帮�ڽ��ϴ�." << endl;
			for (int i = 0; i < 7; ++i) {
				cout << date[whatDate - 1].getName(whatTime - 1, i) << ' ';
			}
			cout << '\n';
			cout << "�¼���ȣ�� �Է����ּ���. (1, 2, 3, 4, 5, 6, 7) >> ";
			int whatSeat;
			cin >> whatSeat;
			date[whatDate - 1].setName(whatTime - 1, whatSeat - 1, rMember.getInfoName());
			rMember.SetInfoPeopleNum(rMember.getInfoPeopleNum() + 1);

			string tDate = "3�� " + to_string(whatDate) + "��";
			string tTime;
			if (whatTime == 1) tTime = "9��~10��";
			else if (whatTime == 2) tTime = "10��~11��";
			else if (whatTime == 3) tTime = "11��~12��";
			else if (whatTime == 4) tTime = "7��~8��";
			else if (whatTime == 5) tTime = "8��~9��";
			else if (whatTime == 6) tTime = "9��~10��";
			string tSeat = to_string(whatSeat);
			string data = "�Ĵ� ���� ���α׷� : " + rMember.getInfoName() + "����" + tDate + " " + tTime + ' ' + tSeat + "�� �ڸ��� �����Ͽ����ϴ�.";
			ofstream fout("reservationData.txt", ios::out | ios::app);
			fout << data << endl;
			fout.close();

			++seatResNum[whatSeat - 1];
		}
		else if (rMember.getInfoPeopleNum() <= 4) {
			cout << "�� �Ĵ��� �ڸ��� 2�μ� 3�ڸ�, 4�μ� 3�ڸ�, 6�μ� 1�ڸ��� �� 7�ڸ� �Դϴ�." << endl;
			cout << "�ο��� 3�� �̻��̹Ƿ� 2�μ� �ڸ��� 1, 2, 3�� �ڸ��� �����ϰ� �����帮�ڽ��ϴ�." << endl;
			for (int i = 3; i < 7; ++i) {
				cout << date[whatDate - 1].getName(whatTime - 1, i) << ' ';
			}
			cout << '\n';
			cout << "�¼���ȣ�� �Է����ּ���. (4, 5, 6, 7) >> ";
			int whatSeat;
			cin >> whatSeat;
			date[whatDate - 1].setName(whatTime - 1, whatSeat - 1, rMember.getInfoName());
			rMember.SetInfoPeopleNum(rMember.getInfoPeopleNum() + 1);
			string tDate = "3�� " + to_string(whatDate) + "��";
			string tTime;
			if (whatTime == 1) tTime = "9��~10��";
			else if (whatTime == 2) tTime = "10��~11��";
			else if (whatTime == 3) tTime = "11��~12��";
			else if (whatTime == 4) tTime = "7��~8��";
			else if (whatTime == 5) tTime = "8��~9��";
			else if (whatTime == 6) tTime = "9��~10��";
			string tSeat = to_string(whatSeat);
			string data = "�Ĵ� ���� ���α׷� : " + rMember.getInfoName() + "����" + tDate + " " + tTime + ' ' + tSeat + "�� �ڸ��� �����Ͽ����ϴ�.";
			ofstream fout("reservationData.txt", ios::out | ios::app);
			fout << data << endl;
			fout.close();
			++seatResNum[whatSeat - 1];
		}
		else if (rMember.getInfoPeopleNum() <= 6) {
			cout << "�� �Ĵ��� �ڸ��� 2�μ� 3�ڸ�, 4�μ� 3�ڸ�, 6�μ� 1�ڸ��� �� 7�ڸ� �Դϴ�." << endl;
			for (int i = 6; i < 7; ++i) {
				if (date[whatDate - 1].getName(whatTime - 1, i) == "---") {
					cout << "���� �ο����� ������ ���̺��� 6�μ� �ϳ��Դϴ�. 6�μ� ���̺�� �����ص帮�ڽ��ϴ�." << '\n';
					date[whatDate - 1].setName(whatTime - 1, 6, rMember.getInfoName());
					rMember.SetInfoPeopleNum(rMember.getInfoPeopleNum() + 1);
					++seatResNum[6];
					string tDate = "3�� " + to_string(whatDate) + "��";
					string tTime;
					if (whatTime == 1) tTime = "9��~10��";
					else if (whatTime == 2) tTime = "10��~11��";
					else if (whatTime == 3) tTime = "11��~12��";
					else if (whatTime == 4) tTime = "7��~8��";
					else if (whatTime == 5) tTime = "8��~9��";
					else if (whatTime == 6) tTime = "9��~10��";
					string tSeat = to_string(7);
					string data = "�Ĵ� ���� ���α׷� : " + rMember.getInfoName() + "����" + tDate + " " + tTime + ' ' + tSeat + "�� �ڸ��� �����Ͽ����ϴ�.";
					ofstream fout("reservationData.txt", ios::out | ios::app);
					fout << data << endl;
					fout.close();
				}
				else {
					cout << "6�μ� �ڸ��� ��� á���ϴ�. ������ �Ұ����� �� �����ϴ�. �˼��մϴ�." << endl;
				}
			}
		}
		else cout << "�� �Ĵ��� ���밡�� �ο��� �ִ� 6���Դϴ�. ������ �Ұ����� �� �����ϴ�. �˼��մϴ�." << endl;
		break;
	case 2:
		int WaitOrNot = walkin.addWaiter(rMember);
		if (WaitOrNot == 1) {
			while (1) {
				cout << "��ø� ��ٷ� �ֽʽÿ�." << '\n';
				cout << "(�Ŵ����� 2�� ���̺� �Ļ簡 ������ 1, 4�� ���̺� �Ļ簡 ������ 2, 3�� ���̺� �Ļ簡 ������ 3�� ������. / ���α׷��� �����Ϸ��� 0�� ������.)" << '\n';
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

