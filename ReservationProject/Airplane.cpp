#include "Airplane.h"

Airplane::Airplane() {
	string depList[] = { "��õ", "����", "����", "����", "����" };
	string destList[] = { "��õ", "����", "����", "����", "����" };
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			where[i][j].setDepart(depList[i]);
			where[i][j].setDest(destList[j]);
		}
	}
}

void Airplane::showStatistics(AirplaneInfo aMember) {
	cout << "ȸ������ ���� Ƚ���� ���� : 1 / �¼��� ����� Ƚ���� ���� : 2 >> ";
	int whatStatistics;
	cin >> whatStatistics;
	if (whatStatistics == 1) {
		cout << "ȸ���Բ����� " << aMember.getInfoReservationNum() << "ȸ �����ϼ̽��ϴ�." << endl;
	}
	else {
		for (int i = 0; i < 8; ++i) {
			cout << i + 1 << "��° �ڸ��� " << seatResNum[i] << "ȸ ����Ǿ����ϴ�." << endl;
		}
	}
}

void Airplane::AirplaneReservation(AirplaneInfo &aMember) {
	cout << "������� ����ּ���." << '\n';
	cout << "��õ : 1, ���� ; 2, ���� : 3, ���� : 4, ���� : 5 >> ";
	int dep;
	cin >> dep;

	cout << "�������� ����ּ���." << '\n';
	cout << "��õ : 1, ���� ; 2, ���� : 3, ���� : 4, ���� : 5 >> ";
	int dest;
	cin >> dest;

	cout << "�պ� : 1, �� : 2 >> ";
	int roundTrip;
	cin >> roundTrip;

	if (roundTrip == 1) { // �պ�
		cout << "���� �� ��¥�� ����ּ���" << '\n';
		cout << "3�� 1�� : 1, 3�� 2�� : 2, 3�� 3�� : 3, 3�� 4�� : 4, 3�� 5�� : 5, 3�� 6�� : 6, 3�� 7�� : 7 >> ";
		int goDate;
		cin >> goDate;

		cout << "�ð��� ����ּ���" << '\n';
		cout << "07�� : 1, 12�� : 2, 17�� : 3 >> ";
		int goTime;
		cin >> goTime;
		Time goTmpTime;
		for (int i = 0; i < 8; ++i) {
			if (aMember.getInfoBudget() >= where[dep - 1][dest - 1].getCost(goDate - 1, goTime - 1, i)) {
				goTmpTime.setName(i, where[dep - 1][dest - 1].getName(goDate - 1, goTime - 1, i));
			}
			else {
				goTmpTime.setName(i, "No-Budget");
			}
		}
		cout << "�¼��� ����ּ���" << '\n';
		for (int i = 0; i < 8; ++i) {
			cout << goTmpTime.getName(i) << ' ';
		}
		cout << '\n';
		int goSeatNum;
		cout << "�¼���ȣ�� �Է����ּ���. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
		cin >> goSeatNum;
		where[dep - 1][dest - 1].setName(goDate - 1, goTime - 1, goSeatNum - 1, aMember.getInfoName());
		aMember.setInfoMileage(aMember.getInfoMileage() + 100);
		aMember.setInfoBudget(aMember.getInfoBudget() - where[dep - 1][dest - 1].getCost(goDate - 1, goTime - 1, goSeatNum - 1));
		++seatResNum[goSeatNum - 1];
		string tDate = "3�� " + to_string(goDate) + "��";
		string tTime;
		if (goTime == 1) tTime = "07��";
		else if (goTime == 2)tTime = "12��";
		else if (goTime == 3)tTime = "17��";
		string tSeat = to_string(goSeatNum);
		string data1 = "����� �¼� ���� ���α׷� : " + aMember.getInfoName() + "����" + ' ' + tDate + " " + tTime + ' ' + tSeat + "�� �ڸ��� �����Ͽ����ϴ�.";
		ofstream fout("reservationData.txt", ios::out | ios::app);
		fout << data1 << endl;
		fout.close();

		cout << "���� �� ��¥�� ����ּ���" << '\n';
		cout << "3�� 1�� : 1, 3�� 2�� : 2, 3�� 3�� : 3, 3�� 4�� : 4, 3�� 5�� : 5, 3�� 6�� : 6, 3�� 7�� : 7 >> ";
		int comeDate;
		cin >> comeDate;

		cout << "�ð��� ����ּ���" << '\n';
		cout << "07�� : 1, 12�� : 2, 17�� : 3 >> ";
		int comeTime;
		cin >> comeTime;
		Time comeTmpTime;
		for (int i = 0; i < 8; ++i) {
			if (aMember.getInfoBudget() >= where[dest - 1][dep - 1].getCost(comeDate - 1, comeTime - 1, i)) {
				comeTmpTime.setName(i, where[dest - 1][dep - 1].getName(comeDate - 1, comeTime - 1, i));
			}
			else {
				comeTmpTime.setName(i, "No-Budget");
			}
		}
		cout << "�¼��� ����ּ���" << '\n';
		for (int i = 0; i < 8; ++i) {
			cout << comeTmpTime.getName(i) << ' ';
		}
		cout << '\n';
		int comeSeatNum;
		cout << "�¼���ȣ�� �Է����ּ���. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
		cin >> comeSeatNum;
		where[dest - 1][dep - 1].setName(comeDate - 1, comeTime - 1, comeSeatNum - 1, aMember.getInfoName());
		aMember.setInfoMileage(aMember.getInfoMileage() + 100);
		aMember.setInfoBudget(aMember.getInfoBudget() - where[dest - 1][dep - 1].getCost(comeDate - 1, comeTime - 1, comeSeatNum - 1));
		aMember.setInfoReservationNum(aMember.getInfoReservationNum() + 1);
		++seatResNum[comeSeatNum - 1];

		string tDate2 = "3�� " + to_string(comeDate) + "��";
		string tTime2;
		if (comeTime == 1) tTime2 = "07��";
		else if (comeTime == 2)tTime2 = "12��";
		else if (comeTime == 3)tTime2 = "17��";
		string tSeat2 = to_string(comeSeatNum);
		string data2 = "����� �¼� ���� ���α׷� : " + aMember.getInfoName() + "����" + ' ' + tDate2 + " " + tTime2 + ' ' + tSeat2 + "�� �ڸ��� �����Ͽ����ϴ�.";
		ofstream fout2("reservationData.txt", ios::out | ios::app);
		fout2 << data2 << endl;
		fout2.close();

	}
	else if (roundTrip == 2) { // ��
		cout << "��¥�� ����ּ���" << '\n';
		cout << "3�� 1�� : 1, 3�� 2�� : 2, 3�� 3�� : 3, 3�� 4�� : 4, 3�� 5�� : 5, 3�� 6�� : 6, 3�� 7�� : 7 >> ";
		int date;
		cin >> date;

		cout << "�ð��� ����ּ���" << '\n';
		cout << "07�� : 1, 12�� : 2, 17�� : 3 >> ";
		int time;
		cin >> time;
		Time tmpTime;
		for (int i = 0; i < 8; ++i) {
			if (aMember.getInfoBudget() >= where[dep - 1][dest - 1].getCost(date - 1, time - 1, i)) {
				tmpTime.setName(i, where[dep - 1][dest - 1].getName(date - 1, time - 1, i));
			}
			else {
				tmpTime.setName(i, "No-Budget");
			}
		}
		cout << "�¼��� ����ּ���" << '\n';
		for (int i = 0; i < 8; ++i) {
			cout << tmpTime.getName(i) << ' ';
		}
		cout << '\n';
		int seatNum;
		cout << "�¼���ȣ�� �Է����ּ���. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
		cin >> seatNum;
		where[dep - 1][dest - 1].setName(date - 1, time - 1, seatNum - 1, aMember.getInfoName());
		aMember.setInfoMileage(aMember.getInfoMileage() + 100);
		aMember.setInfoBudget(aMember.getInfoBudget() - where[dep - 1][dest - 1].getCost(date - 1, time - 1, seatNum - 1));
		aMember.setInfoReservationNum(aMember.getInfoReservationNum() + 1);
		++seatResNum[seatNum - 1];
		string tDate3 = "3�� " + to_string(date) + "��";
		string tTime3;
		if (time == 1) tTime3 = "07��";
		else if (time == 2)tTime3 = "12��";
		else if (time == 3)tTime3 = "17��";
		string tSeat3 = to_string(seatNum);
		string data3 = "����� �¼� ���� ���α׷� : " + aMember.getInfoName() + "����" + ' ' + tDate3 + " " + tTime3 + ' ' + tSeat3 + "�� �ڸ��� �����Ͽ����ϴ�.";
		ofstream fout3("reservationData.txt", ios::out | ios::app);
		fout3 << data3 << endl;
		fout3.close();
	}
}

void Airplane::AirplaneCancel(AirplaneInfo &aMember) {
	cout << "������� ����ּ���." << '\n';
	cout << "��õ : 1, ���� ; 2, ���� : 3, ���� : 4, ���� : 5 >> ";
	int dep;
	cin >> dep;

	cout << "�������� ����ּ���." << '\n';
	cout << "�̱� : 1, �߱� ; 2, �Ϻ� : 3 >> ";
	int dest;
	cin >> dest;

	cout << "��¥�� ����ּ���" << '\n';
	cout << "3�� 1�� : 1, 3�� 2�� : 2, 3�� 3�� : 3, 3�� 4�� : 4, 3�� 5�� : 5, 3�� 6�� : 6, 3�� 7�� : 7 >> ";
	int date;
	cin >> date;

	cout << "�ð��� ����ּ���" << '\n';
	cout << "07�� : 1, 12�� : 2, 17�� : 3 >> ";
	int time;
	cin >> time;
	cout << "�¼��� ����ּ���" << '\n';
	for (int i = 0; i < 8; ++i) {
		cout << where[dep - 1][dest - 1].getName(date - 1, time - 1, i) << ' ';
	}
	cout << '\n';
	int seatNum;
	cout << "�¼���ȣ�� �Է����ּ���. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
	cin >> seatNum;
	where[dep - 1][dest - 1].setName(date - 1, time - 1, seatNum - 1, "---");
	aMember.setInfoMileage(aMember.getInfoMileage() - 100);
	aMember.setInfoBudget(aMember.getInfoBudget() + where[dep - 1][dest - 1].getCost(date - 1, time - 1, seatNum - 1));
	aMember.setInfoReservationNum(aMember.getInfoReservationNum() - 1);
	--seatResNum[seatNum - 1];
	string tDate4 = "3�� " + to_string(date) + "��";
	string tTime4;
	if (time == 1) tTime4 = "07��";
	else if (time == 2)tTime4 = "12��";
	else if (time == 3)tTime4 = "17��";
	string tSeat4 = to_string(seatNum);
	string data4 = "����� �¼� ���� ���α׷� : " + aMember.getInfoName() + "����" + ' ' + tDate4 + " " + tTime4 + ' ' + tSeat4 + "�� �ڸ��� ������ ����Ͽ����ϴ�.";
	ofstream fout4("reservationData.txt", ios::out | ios::app);
	fout4 << data4 << endl;
	fout4.close();
}

void Airplane::AirplaneLook(AirplaneInfo aMember) {
	cout << "������� ����ּ���." << '\n';
	cout << "��õ : 1, ���� ; 2, ���� : 3, ���� : 4, ���� : 5 >> ";
	int dep;
	cin >> dep;

	cout << "�������� ����ּ���." << '\n';
	cout << "�̱� : 1, �߱� ; 2, �Ϻ� : 3 >> ";
	int dest;
	cin >> dest;

	cout << "��¥�� ����ּ���" << '\n';
	cout << "3�� 1�� : 1, 3�� 2�� : 2, 3�� 3�� : 3, 3�� 4�� : 4, 3�� 5�� : 5, 3�� 6�� : 6, 3�� 7�� : 7 >> ";
	int date;
	cin >> date;

	cout << "�ð��� ����ּ���" << '\n';
	cout << "07�� : 1, 12�� : 2, 17�� : 3 >> ";
	int time;
	cin >> time;
	Time tmpTime;
	for (int i = 0; i < 8; ++i) {
		if (aMember.getInfoBudget() >= where[dep - 1][dest - 1].getCost(date - 1, time - 1, i)) {
			tmpTime.setName(i, where[dep - 1][dest - 1].getName(date - 1, time - 1, i));
		}
		else {
			tmpTime.setName(i, "No-Budget");
		}
	}
	for (int i = 0; i < 8; ++i) {
		cout << tmpTime.getName(i) << ' ';
	}
	cout << '\n';
}

void Airplane::AirplaneEnd() {
	cout << "���� �ý����� �����մϴ�." << '\n';
}
