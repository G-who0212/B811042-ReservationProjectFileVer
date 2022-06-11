#include <iostream>
#include <string>
#include "MemberData.h"
#include "Airplane.h"
#include "Restaurant.h"
#include "Library.h"
#include "FamilyData.h"
#include "JoinMemberLogin.h"
#include <fstream>
using namespace std;

int main() {
	MemberData data;
	Airplane airplane;
	Restaurant restaurant;
	Library library;
	RestaurantWalkInSeat walkIn;
	FamilyData familyData;

	int restoreData;
	cout << "���α׷� ���� �� �ԷµǾ��� ������� ������ ���ΰ���? (�����ϸ� 1, �ƴϸ� 0) >>" << endl;
	cin >> restoreData;
	const char* file = "reservationData.txt";
	if (restoreData == 1) {
		ifstream fin(file);
		if (!fin) {
			cout << file << " ���� ����" << endl;
			return 0;
		}
		int count = 0;
		int c;
		while ((c = fin.get()) != EOF) {
			cout << (char)c;;
			count++;
		}
		if (count == 0) cout << "reservationData.txt ���Ͽ� �ƹ� ������ �����ϴ�." << endl;
	}

	while (1) {
		cout << "� ���񽺸� �̿��Ͻ� ���ΰ���?" << '\n';
		cout << "����� ���� : 1, �Ĵ� ���� : 2, ������ ���� : 3 >>";
		int service;
		cin >> service;
		switch (service) {
		case 1:
			cout << "ȸ�������� �Ǿ��ֳ���? (�ȵǾ������� 0, �Ǿ������� 1�� �Է����ּ���) >> ";
			int memberCheck;
			cin >> memberCheck;
			if (memberCheck == 0) {
				joinMember(data, airplane);
				break;
			}
			else if (memberCheck == 1) {
				login(data, airplane); // �α��� �����ÿ� ���༭�񽺱��� ���ư�
				break;
			}
		case 2:
			cout << "ȸ�������� �Ǿ��ֳ���? (�ȵǾ������� 0, �Ǿ������� 1�� �Է����ּ���) >> ";
			int memberCheck2;
			cin >> memberCheck2;
			if (memberCheck2 == 0) {
				joinMember(data, restaurant, walkIn);
				break;
			}
			else if (memberCheck2 == 1) {
				login(data, restaurant, walkIn); // �α��� ������ ���༭�񽺱��� ���ư�
				break;
			}
			else break;
		case 3:
			cout << "ȸ�������� �Ǿ��ֳ���? (�ȵǾ������� 0, �Ǿ������� 1�� �Է����ּ���) >> ";
			int memberCheck3;
			cin >> memberCheck3;
			if (memberCheck3 == 0) {
				joinMember(data, familyData, library);
				break;
			}
			else if (memberCheck3 == 1) {
				login(data, familyData, library); // �α��� �����ÿ� ���༭�񽺱��� ���ư�
				break;
			}
		}
	}
}