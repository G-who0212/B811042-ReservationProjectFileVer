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
	cout << "ID�� �Է����ּ���" << '\n';
	string checkID;
	cin >> checkID;
	cout << "PW�� �Է����ּ���" << '\n';
	string checkPW;
	cin >> checkPW;
	int memberIndex = -1;
	for (int i = 0; i < data.getAirplaneInfoSize(); ++i) {
		if ((data.getAirplaneInfo(i).getInfoID() == checkID) && (data.getAirplaneInfo(i).getInfoPW() == checkPW)) {
			memberIndex = i;
			cout << "���� ���� : 1 / ��� ���� : 2" << endl;
			int showStatistics;
			cin >> showStatistics;
			if (showStatistics == 1) {
				while (1) {
					cout << "���� : 1, ��� : 2, ���� : 3, ������ : 4 >>";
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
					else cout << "�Է��� �߸��ϼ̽��ϴ�. �ٽ� �ϼ���.";
				}
				break;
			}
			else {
				airplane.showStatistics(data.getAirplaneInfo(memberIndex));
			}
		}
	}
	if (memberIndex == -1) { // ���̵�� ��й�ȣ�� ��ġ�ϴ� ���� ����
		cout << "ID �Ǵ� PW�� �߸��Ǿ����ϴ�." << '\n';
		cout << "ID�� PW�� �ٽ� ġ���� 1, ȸ�������� �Ϸ��� 2, ���α׷��� �����Ϸ��� 3�� ��������" << '\n';
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
	cout << "ȭ�������� �����ϰڽ��ϴ�." << '\n';
	cout << "����Ͻ� ID�� �Է����ּ���. >>";
	string newID;
	cin >> newID;
	cout << "����Ͻ� ��й�ȣ�� �Է����ּ���. >>";
	string newPW;
	cin >> newPW;
	cout << "������ �Է����ּ���. >>";
	string newName;
	cin >> newName;
	cout << "���ڳ�̼� �� : 100000 / �պ� : 200000" << endl;
	cout << "�����Ͻ���  �� : 250000 / �պ� : 500000" << endl;
	cout << "������ �Է����ּ��� (���ڸ� �Է�.) >>";
	int newBudget;
	cin >> newBudget;
	data.addAirplaneInfo(newID, newPW, newName, newBudget);
	cout << "ȭ�������� �Ϸ�Ǿ����ϴ�" << '\n';
	login(data, airplane);
	return 0;
}

int joinMember(MemberData& data, Restaurant& restaurant, RestaurantWalkInSeat& walkIn);

int login(MemberData& data, Restaurant& restaurant, RestaurantWalkInSeat& walkIn) {
	cout << "ID�� �Է����ּ���" << '\n';
	string checkID;
	cin >> checkID;
	cout << "PW�� �Է����ּ���" << '\n';
	string checkPW;
	cin >> checkPW;
	int memberIndex = -1;
	for (int i = 0; i < data.getRestaurantInfoSize(); ++i) {
		if ((data.getRestaurantInfo(i).getInfoID() == checkID) && (data.getRestaurantInfo(i).getInfoPW() == checkPW)) {
			memberIndex = i;
			cout << "���� ���� : 1 / ��� ���� : 2" << endl;
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
	if (memberIndex == -1) { // ���̵�� ��й�ȣ�� ��ġ�ϴ� ���� ����
		cout << "ID �Ǵ� PW�� �߸��Ǿ����ϴ�." << '\n';
		cout << "ID�� PW�� �ٽ� ġ���� 1, ȸ�������� �Ϸ��� 2, ���α׷��� �����Ϸ��� 3�� ��������" << '\n';
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
	cout << "ȭ�������� �����ϰڽ��ϴ�." << '\n';
	cout << "����Ͻ� ID�� �Է����ּ���. >>";
	string newID;
	cin >> newID;
	cout << "����Ͻ� ��й�ȣ�� �Է����ּ���. >>";
	string newPW;
	cin >> newPW;
	cout << "������ �Է����ּ���. >>";
	string newName;
	cin >> newName;
	cout << "���̸� �Է����ּ���. >>";
	int newAge;
	cin >> newAge;
	cout << "������ ���� ���� ����ΰ���? >>";
	int newPeopleNum;
	cin >> newPeopleNum;
	data.addRestaurantInfo(newID, newPW, newName, newAge, newPeopleNum);
	cout << "ȭ�������� �Ϸ�Ǿ����ϴ�" << '\n';
	login(data, restaurant, walkIn);
	return 0;
}
void login(MemberData& data, FamilyData& familyData, Library& library);

void joinMember(MemberData& data, FamilyData& familyData, Library& library) {
	cout << "ȭ�������� �����ϰڽ��ϴ�." << '\n';
	cout << "����Ͻ� ID�� �Է����ּ���. >>";
	string newID;
	cin >> newID;
	cout << "����Ͻ� ��й�ȣ�� �Է����ּ���. >>";
	string newPW;
	cin >> newPW;
	cout << "������ �Է����ּ���. >>";
	string newName;
	cin >> newName;
	cout << "���̸� �Է����ּ���. >>";
	int newAge;
	cin >> newAge;
	cout << "������ �Է����ּ���. (���ڸ� ��, ���ڸ� ��)>>";
	string newSex;
	cin >> newSex;
	cout << "��ȣ�� �����Ͻó���? (���ڸ� ���ֽʽÿ�. ex) 403ȣ -> 403)>>";
	int newUnit;
	cin >> newUnit;
	int checkIfRegistered = 0;
	for (int i = 0; i < familyData.getRegisteredFamily(); ++i) {
		if (familyData.getFamilyData(i).getUnit() == newUnit) {
			data.addLibraryInfo(newID, newPW, newName, newAge, familyData.getFamilyData(i), familyData.getFamilyData(i).getUnit(), familyData.getFamilyData(i).getLID(), newSex);
			cout << "�̹� ���Ե� ���뱺��." << '\n';
			cout << "ȸ�������� �Ϸ��߽��ϴ�." << '\n';
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
		cout << "����� ������ ID�� " << familyData.getRegisteredFamily() - 1 << "�Դϴ�." << '\n';
		cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.";
		login(data, familyData, library);
	}
}

void login(MemberData& data, FamilyData& familyData, Library& library) {
	cout << "ID�� �Է����ּ���" << '\n';
	string checkID;
	cin >> checkID;
	cout << "PW�� �Է����ּ���" << '\n';
	string checkPW;
	cin >> checkPW;
	int memberIndex = -1;
	for (int i = 0; i < data.getLibraryInfoSize(); ++i) {
		if ((data.getLibraryInfo(i).getInfoID() == checkID) && (data.getLibraryInfo(i).getInfoPW() == checkPW)) {
			memberIndex = i;
			cout << "���� ���� : 1 / ��� ���� : 2" << endl;
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
	if (memberIndex == -1) { // ���̵�� ��й�ȣ�� ��ġ�ϴ� ���� ����
		cout << "ID �Ǵ� PW�� �߸��Ǿ����ϴ�." << '\n';
		cout << "ID�� PW�� �ٽ� ġ���� 1, ȸ�������� �Ϸ��� 2, ���α׷��� �����Ϸ��� 3�� ��������" << '\n';
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