#include "Airplane.h"

Airplane::Airplane() {
	string depList[] = { "인천", "김포", "김해", "제주", "포항" };
	string destList[] = { "인천", "김포", "김해", "제주", "포항" };
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			where[i][j].setDepart(depList[i]);
			where[i][j].setDest(destList[j]);
		}
	}
}

void Airplane::showStatistics(AirplaneInfo aMember) {
	cout << "회원님의 예약 횟수를 보기 : 1 / 좌석별 예약된 횟수를 보기 : 2 >> ";
	int whatStatistics;
	cin >> whatStatistics;
	if (whatStatistics == 1) {
		cout << "회원님께서는 " << aMember.getInfoReservationNum() << "회 예약하셨습니다." << endl;
	}
	else {
		for (int i = 0; i < 8; ++i) {
			cout << i + 1 << "번째 자리는 " << seatResNum[i] << "회 예약되었습니다." << endl;
		}
	}
}

void Airplane::AirplaneReservation(AirplaneInfo &aMember) {
	cout << "출발지를 골라주세요." << '\n';
	cout << "인천 : 1, 김포 ; 2, 김해 : 3, 제주 : 4, 포항 : 5 >> ";
	int dep;
	cin >> dep;

	cout << "도착지를 골라주세요." << '\n';
	cout << "인천 : 1, 김포 ; 2, 김해 : 3, 제주 : 4, 포항 : 5 >> ";
	int dest;
	cin >> dest;

	cout << "왕복 : 1, 편도 : 2 >> ";
	int roundTrip;
	cin >> roundTrip;

	if (roundTrip == 1) { // 왕복
		cout << "가는 편 날짜를 골라주세요" << '\n';
		cout << "3월 1일 : 1, 3월 2일 : 2, 3월 3일 : 3, 3월 4일 : 4, 3월 5일 : 5, 3월 6일 : 6, 3월 7일 : 7 >> ";
		int goDate;
		cin >> goDate;

		cout << "시간을 골라주세요" << '\n';
		cout << "07시 : 1, 12시 : 2, 17시 : 3 >> ";
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
		cout << "좌석을 골라주세요" << '\n';
		for (int i = 0; i < 8; ++i) {
			cout << goTmpTime.getName(i) << ' ';
		}
		cout << '\n';
		int goSeatNum;
		cout << "좌석번호를 입력해주세요. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
		cin >> goSeatNum;
		where[dep - 1][dest - 1].setName(goDate - 1, goTime - 1, goSeatNum - 1, aMember.getInfoName());
		aMember.setInfoMileage(aMember.getInfoMileage() + 100);
		aMember.setInfoBudget(aMember.getInfoBudget() - where[dep - 1][dest - 1].getCost(goDate - 1, goTime - 1, goSeatNum - 1));
		++seatResNum[goSeatNum - 1];
		string tDate = "3월 " + to_string(goDate) + "일";
		string tTime;
		if (goTime == 1) tTime = "07시";
		else if (goTime == 2)tTime = "12시";
		else if (goTime == 3)tTime = "17시";
		string tSeat = to_string(goSeatNum);
		string data1 = "비행기 좌석 예약 프로그램 : " + aMember.getInfoName() + "님은" + ' ' + tDate + " " + tTime + ' ' + tSeat + "번 자리를 예약하였습니다.";
		ofstream fout("reservationData.txt", ios::out | ios::app);
		fout << data1 << endl;
		fout.close();

		cout << "오는 편 날짜를 골라주세요" << '\n';
		cout << "3월 1일 : 1, 3월 2일 : 2, 3월 3일 : 3, 3월 4일 : 4, 3월 5일 : 5, 3월 6일 : 6, 3월 7일 : 7 >> ";
		int comeDate;
		cin >> comeDate;

		cout << "시간을 골라주세요" << '\n';
		cout << "07시 : 1, 12시 : 2, 17시 : 3 >> ";
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
		cout << "좌석을 골라주세요" << '\n';
		for (int i = 0; i < 8; ++i) {
			cout << comeTmpTime.getName(i) << ' ';
		}
		cout << '\n';
		int comeSeatNum;
		cout << "좌석번호를 입력해주세요. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
		cin >> comeSeatNum;
		where[dest - 1][dep - 1].setName(comeDate - 1, comeTime - 1, comeSeatNum - 1, aMember.getInfoName());
		aMember.setInfoMileage(aMember.getInfoMileage() + 100);
		aMember.setInfoBudget(aMember.getInfoBudget() - where[dest - 1][dep - 1].getCost(comeDate - 1, comeTime - 1, comeSeatNum - 1));
		aMember.setInfoReservationNum(aMember.getInfoReservationNum() + 1);
		++seatResNum[comeSeatNum - 1];

		string tDate2 = "3월 " + to_string(comeDate) + "일";
		string tTime2;
		if (comeTime == 1) tTime2 = "07시";
		else if (comeTime == 2)tTime2 = "12시";
		else if (comeTime == 3)tTime2 = "17시";
		string tSeat2 = to_string(comeSeatNum);
		string data2 = "비행기 좌석 예약 프로그램 : " + aMember.getInfoName() + "님은" + ' ' + tDate2 + " " + tTime2 + ' ' + tSeat2 + "번 자리를 예약하였습니다.";
		ofstream fout2("reservationData.txt", ios::out | ios::app);
		fout2 << data2 << endl;
		fout2.close();

	}
	else if (roundTrip == 2) { // 편도
		cout << "날짜를 골라주세요" << '\n';
		cout << "3월 1일 : 1, 3월 2일 : 2, 3월 3일 : 3, 3월 4일 : 4, 3월 5일 : 5, 3월 6일 : 6, 3월 7일 : 7 >> ";
		int date;
		cin >> date;

		cout << "시간을 골라주세요" << '\n';
		cout << "07시 : 1, 12시 : 2, 17시 : 3 >> ";
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
		cout << "좌석을 골라주세요" << '\n';
		for (int i = 0; i < 8; ++i) {
			cout << tmpTime.getName(i) << ' ';
		}
		cout << '\n';
		int seatNum;
		cout << "좌석번호를 입력해주세요. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
		cin >> seatNum;
		where[dep - 1][dest - 1].setName(date - 1, time - 1, seatNum - 1, aMember.getInfoName());
		aMember.setInfoMileage(aMember.getInfoMileage() + 100);
		aMember.setInfoBudget(aMember.getInfoBudget() - where[dep - 1][dest - 1].getCost(date - 1, time - 1, seatNum - 1));
		aMember.setInfoReservationNum(aMember.getInfoReservationNum() + 1);
		++seatResNum[seatNum - 1];
		string tDate3 = "3월 " + to_string(date) + "일";
		string tTime3;
		if (time == 1) tTime3 = "07시";
		else if (time == 2)tTime3 = "12시";
		else if (time == 3)tTime3 = "17시";
		string tSeat3 = to_string(seatNum);
		string data3 = "비행기 좌석 예약 프로그램 : " + aMember.getInfoName() + "님은" + ' ' + tDate3 + " " + tTime3 + ' ' + tSeat3 + "번 자리를 예약하였습니다.";
		ofstream fout3("reservationData.txt", ios::out | ios::app);
		fout3 << data3 << endl;
		fout3.close();
	}
}

void Airplane::AirplaneCancel(AirplaneInfo &aMember) {
	cout << "출발지를 골라주세요." << '\n';
	cout << "인천 : 1, 김포 ; 2, 김해 : 3, 제주 : 4, 포항 : 5 >> ";
	int dep;
	cin >> dep;

	cout << "도착지를 골라주세요." << '\n';
	cout << "미국 : 1, 중국 ; 2, 일본 : 3 >> ";
	int dest;
	cin >> dest;

	cout << "날짜를 골라주세요" << '\n';
	cout << "3월 1일 : 1, 3월 2일 : 2, 3월 3일 : 3, 3월 4일 : 4, 3월 5일 : 5, 3월 6일 : 6, 3월 7일 : 7 >> ";
	int date;
	cin >> date;

	cout << "시간을 골라주세요" << '\n';
	cout << "07시 : 1, 12시 : 2, 17시 : 3 >> ";
	int time;
	cin >> time;
	cout << "좌석을 골라주세요" << '\n';
	for (int i = 0; i < 8; ++i) {
		cout << where[dep - 1][dest - 1].getName(date - 1, time - 1, i) << ' ';
	}
	cout << '\n';
	int seatNum;
	cout << "좌석번호를 입력해주세요. (1, 2, 3, 4, 5, 6, 7, 8) >> ";
	cin >> seatNum;
	where[dep - 1][dest - 1].setName(date - 1, time - 1, seatNum - 1, "---");
	aMember.setInfoMileage(aMember.getInfoMileage() - 100);
	aMember.setInfoBudget(aMember.getInfoBudget() + where[dep - 1][dest - 1].getCost(date - 1, time - 1, seatNum - 1));
	aMember.setInfoReservationNum(aMember.getInfoReservationNum() - 1);
	--seatResNum[seatNum - 1];
	string tDate4 = "3월 " + to_string(date) + "일";
	string tTime4;
	if (time == 1) tTime4 = "07시";
	else if (time == 2)tTime4 = "12시";
	else if (time == 3)tTime4 = "17시";
	string tSeat4 = to_string(seatNum);
	string data4 = "비행기 좌석 예약 프로그램 : " + aMember.getInfoName() + "님은" + ' ' + tDate4 + " " + tTime4 + ' ' + tSeat4 + "번 자리를 예약을 취소하였습니다.";
	ofstream fout4("reservationData.txt", ios::out | ios::app);
	fout4 << data4 << endl;
	fout4.close();
}

void Airplane::AirplaneLook(AirplaneInfo aMember) {
	cout << "출발지를 골라주세요." << '\n';
	cout << "인천 : 1, 김포 ; 2, 김해 : 3, 제주 : 4, 포항 : 5 >> ";
	int dep;
	cin >> dep;

	cout << "도착지를 골라주세요." << '\n';
	cout << "미국 : 1, 중국 ; 2, 일본 : 3 >> ";
	int dest;
	cin >> dest;

	cout << "날짜를 골라주세요" << '\n';
	cout << "3월 1일 : 1, 3월 2일 : 2, 3월 3일 : 3, 3월 4일 : 4, 3월 5일 : 5, 3월 6일 : 6, 3월 7일 : 7 >> ";
	int date;
	cin >> date;

	cout << "시간을 골라주세요" << '\n';
	cout << "07시 : 1, 12시 : 2, 17시 : 3 >> ";
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
	cout << "예약 시스템을 종료합니다." << '\n';
}
