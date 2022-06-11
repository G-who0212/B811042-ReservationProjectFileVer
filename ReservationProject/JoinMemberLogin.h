#pragma once
#include <iostream>
#include <string>
#include "MemberData.h"
#include "Airplane.h"
#include "Restaurant.h"
#include "Library.h"
#include "FamilyData.h"
using namespace std;

int joinMember(MemberData& data, Airplane& airplane);

int login(MemberData& data, Airplane& airplane) {
	cout << "ID를 입력해주세요" << '\n';
	string checkID;
	cin >> checkID;
	cout << "PW을 입력해주세요" << '\n';
	string checkPW;
	cin >> checkPW;
	int memberIndex = -1;
	for (int i = 0; i < data.getAirplaneInfoSize(); ++i) {
		if ((data.getAirplaneInfo(i).getInfoID() == checkID) && (data.getAirplaneInfo(i).getInfoPW() == checkPW)) {
			memberIndex = i;
			cout << "서비스 진행 : 1 / 통계 보기 : 2" << endl;
			int showStatistics;
			cin >> showStatistics;
			if (showStatistics == 1) {
				while (1) {
					cout << "예약 : 1, 취소 : 2, 보기 : 3, 끝내기 : 4 >>";
					int ReservationAirplaneOption;
					cin >> ReservationAirplaneOption;
					if (ReservationAirplaneOption == 1) {
						airplane.AirplaneReservation(data.getAirplaneInfo(memberIndex));
					}
					else if (ReservationAirplaneOption == 2) {
						airplane.AirplaneCancel(data.getAirplaneInfo(memberIndex));
					}
					else if (ReservationAirplaneOption == 3) {
						airplane.AirplaneLook(data.getAirplaneInfo(memberIndex));
					}
					else if (ReservationAirplaneOption == 4) {
						airplane.AirplaneEnd();
						break;
					}
					else cout << "입력을 잘못하셨습니다. 다시 하세요.";
				}
				break;
			}
			else {
				airplane.showStatistics(data.getAirplaneInfo(memberIndex));
			}
		}
	}
	if (memberIndex == -1) { // 아이디와 비밀번호가 일치하는 것이 없음
		cout << "ID 또는 PW가 잘못되었습니다." << '\n';
		cout << "ID와 PW을 다시 치려면 1, 회원가입을 하려면 2, 프로그램을 종료하려면 3을 누르세요" << '\n';
		int process;
		cin >> process;
		switch (process) {
		case 1:
			login(data, airplane);
			break;
		case 2:
			joinMember(data, airplane);
			break;
		case 3:
			return 0;
			break;
		}
	}
	return 0;
}



int joinMember(MemberData& data, Airplane& airplane) {
	cout << "화원가입을 진행하겠습니다." << '\n';
	cout << "사용하실 ID를 입력해주세요. >>";
	string newID;
	cin >> newID;
	cout << "사용하실 비밀번호를 입력해주세요. >>";
	string newPW;
	cin >> newPW;
	cout << "성함을 입력해주세요. >>";
	string newName;
	cin >> newName;
	cout << "이코노미석 편도 : 100000 / 왕복 : 200000" << endl;
	cout << "비지니스석  편도 : 250000 / 왕복 : 500000" << endl;
	cout << "예산을 입력해주세요 (숫자만 입력.) >>";
	int newBudget;
	cin >> newBudget;
	data.addAirplaneInfo(newID, newPW, newName, newBudget);
	cout << "화원가입이 완료되었습니다" << '\n';
	login(data, airplane);
	return 0;
}

int joinMember(MemberData& data, Restaurant& restaurant, RestaurantWalkInSeat& walkIn);

int login(MemberData& data, Restaurant& restaurant, RestaurantWalkInSeat& walkIn) {
	cout << "ID를 입력해주세요" << '\n';
	string checkID;
	cin >> checkID;
	cout << "PW을 입력해주세요" << '\n';
	string checkPW;
	cin >> checkPW;
	int memberIndex = -1;
	for (int i = 0; i < data.getRestaurantInfoSize(); ++i) {
		if ((data.getRestaurantInfo(i).getInfoID() == checkID) && (data.getRestaurantInfo(i).getInfoPW() == checkPW)) {
			memberIndex = i;
			cout << "서비스 진행 : 1 / 통계 보기 : 2" << endl;
			int showStatistics;
			cin >> showStatistics;
			if (showStatistics == 1) {
				restaurant.RestaurantReservation(data.getRestaurantInfo(i), walkIn);
			}
			else {
				restaurant.showStatistics(data.getRestaurantInfo(i));
			}
		}
	}
	if (memberIndex == -1) { // 아이디와 비밀번호가 일치하는 것이 없음
		cout << "ID 또는 PW가 잘못되었습니다." << '\n';
		cout << "ID와 PW을 다시 치려면 1, 회원가입을 하려면 2, 프로그램을 종료하려면 3을 누르세요" << '\n';
		int process;
		cin >> process;
		switch (process) {
		case 1:
			login(data, restaurant, walkIn);
			break;
		case 2:
			joinMember(data, restaurant, walkIn);
			break;
		case 3:
			return 0;
			break;
		}
	}
	return 0;
}

int joinMember(MemberData& data, Restaurant& restaurant, RestaurantWalkInSeat& walkIn) {
	cout << "화원가입을 진행하겠습니다." << '\n';
	cout << "사용하실 ID를 입력해주세요. >>";
	string newID;
	cin >> newID;
	cout << "사용하실 비밀번호를 입력해주세요. >>";
	string newPW;
	cin >> newPW;
	cout << "성함을 입력해주세요. >>";
	string newName;
	cin >> newName;
	cout << "나이를 입력해주세요. >>";
	int newAge;
	cin >> newAge;
	cout << "일행은 본인 포함 몇명인가요? >>";
	int newPeopleNum;
	cin >> newPeopleNum;
	data.addRestaurantInfo(newID, newPW, newName, newAge, newPeopleNum);
	cout << "화원가입이 완료되었습니다" << '\n';
	login(data, restaurant, walkIn);
	return 0;
}
void login(MemberData& data, FamilyData& familyData, Library& library);

void joinMember(MemberData& data, FamilyData& familyData, Library& library) {
	cout << "화원가입을 진행하겠습니다." << '\n';
	cout << "사용하실 ID를 입력해주세요. >>";
	string newID;
	cin >> newID;
	cout << "사용하실 비밀번호를 입력해주세요. >>";
	string newPW;
	cin >> newPW;
	cout << "성함을 입력해주세요. >>";
	string newName;
	cin >> newName;
	cout << "나이를 입력해주세요. >>";
	int newAge;
	cin >> newAge;
	cout << "성별을 입력해주세요. (남자면 남, 여자면 여)>>";
	string newSex;
	cin >> newSex;
	cout << "몇호에 거주하시나요? (숫자만 써주십시오. ex) 403호 -> 403)>>";
	int newUnit;
	cin >> newUnit;
	int checkIfRegistered = 0;
	for (int i = 0; i < familyData.getRegisteredFamily(); ++i) {
		if (familyData.getFamilyData(i).getUnit() == newUnit) {
			data.addLibraryInfo(newID, newPW, newName, newAge, familyData.getFamilyData(i), familyData.getFamilyData(i).getUnit(), familyData.getFamilyData(i).getLID(), newSex);
			cout << "이미 가입된 세대군요." << '\n';
			cout << "회원가입을 완료했습니다." << '\n';
			checkIfRegistered = 1;
			login(data, familyData, library);
			break;
		}
	}
	if (checkIfRegistered == 0) {
		Family newFamily;
		newFamily.setUnit(newUnit);
		newFamily.setLID(familyData.getRegisteredFamily());
		data.addLibraryInfo(newID, newPW, newName, newAge, newFamily, newUnit, familyData.getRegisteredFamily(), newSex);
		familyData.addFamilyData(newFamily);
		familyData.setRegisteredFamily(familyData.getRegisteredFamily() + 1);
		cout << "당신의 독서실 ID는 " << familyData.getRegisteredFamily() - 1 << "입니다." << '\n';
		cout << "회원가입이 완료되었습니다.";
		login(data, familyData, library);
	}
}

void login(MemberData& data, FamilyData& familyData, Library& library) {
	cout << "ID를 입력해주세요" << '\n';
	string checkID;
	cin >> checkID;
	cout << "PW을 입력해주세요" << '\n';
	string checkPW;
	cin >> checkPW;
	int memberIndex = -1;
	for (int i = 0; i < data.getLibraryInfoSize(); ++i) {
		if ((data.getLibraryInfo(i).getInfoID() == checkID) && (data.getLibraryInfo(i).getInfoPW() == checkPW)) {
			memberIndex = i;
			cout << "서비스 진행 : 1 / 통계 보기 : 2" << endl;
			int showStatistics;
			cin >> showStatistics;
			if (showStatistics == 1) {
				library.LibraryReservation(data.getLibraryInfo(memberIndex));
			}
			else {
				library.showStatistics(data.getLibraryInfo(memberIndex));
			}
		}
	}
	if (memberIndex == -1) { // 아이디와 비밀번호가 일치하는 것이 없음
		cout << "ID 또는 PW가 잘못되었습니다." << '\n';
		cout << "ID와 PW을 다시 치려면 1, 회원가입을 하려면 2, 프로그램을 종료하려면 3을 누르세요" << '\n';
		int process;
		cin >> process;
		switch (process) {
		case 1:
			login(data, familyData, library);
			break;
		case 2:
			joinMember(data, familyData, library);
			break;
		case 3:
			break;
		}
	}
}