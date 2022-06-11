#include "RestaurantWalkInSeat.h"

int RestaurantWalkInSeat::addWaiter(RestaurantInfo rMember) {
	if (rMember.getInfoPeopleNum() <= 2) { // �ο����� 1�� or 2��
		if ((wc2.empty())) {
			cout << rMember.getInfoName() << "�� ��������." << '\n';
			wc2.push_back(WalkInCustomer(rMember.getInfoName(), wc2.size()));
			return 0;
		}
		else if ((wc4.empty())) {
			cout << rMember.getInfoName() << "�� ��������." << '\n';
			wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
			return 0;
		}
		else if ((wc6.empty())) {
			cout << rMember.getInfoName() << "�� ��������." << '\n';
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			return 0;
		}
		else {
			cout << "2�ڸ� ���̺� : 1, 4�ڸ� ���̺� : 2, 6�ڸ� ���̺� : 6 >>";
			int table;
			cin >> table;
			switch (table) {
			case 1:
				wc2.push_back(WalkInCustomer(rMember.getInfoName(), wc2.size()));
				cout << "��� ������ " << wc2.size() << "�Դϴ�.";
			case 2:
				wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
				cout << "��� ������ " << wc4.size() << "�Դϴ�.";
			case 3:
				wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
				cout << "��� ������ " << wc6.size() << "�Դϴ�.";
			}
			return 1;
		}
	}
	else if (rMember.getInfoPeopleNum() <= 4) { // �ο����� 3�� or 4��
		if ((wc4.empty())) {
			cout << rMember.getInfoName() << "�� ��������." << '\n';
			wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
			return 0;
		}
		else if ((wc6.empty())) {
			cout << rMember.getInfoName() << "�� ��������." << '\n';
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			return 0;
		}
		else {
			cout << "4�ڸ� ���̺� : 1, 6�ڸ� ���̺� : 2 >>";
			int table;
			cin >> table;
			switch (table) {
			case 1:
				wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
				cout << "��� ������ " << wc4.size() << "�Դϴ�.";
			case 2:
				wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
				cout << "��� ������ " << wc6.size() << "�Դϴ�.";
			}
			return 1;
		}
	}
	else if (rMember.getInfoPeopleNum() <= 6) { //�ο����� 5�� or 6��
		if ((wc6.empty())) {
			cout << rMember.getInfoName() << "�� ��������." << '\n';
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			return 0;
		}
		else {
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			cout << "��� ������ " << wc6.size() << "�Դϴ�.";
			return 1;
		}
	}
	else { //�ο����� 0���� �۰ų� 7���� ũ�ų� ����
		cout << "�ο��� ���� �ʾƼ� ������ �Ұ����մϴ�.";
		return 0;
	}
}

void RestaurantWalkInSeat::callWaiter(int whatTable) { // ��� ���̺� �Ļ�(���̺�2, ���̺�4, ���̺�6)�� �������� Ȯ�� �� ���� �մ� ȣ��
	switch (whatTable) {
	case 1:
		if (!wc2.empty()) {
			cout << wc2[point].getName() << "�� ��������" << '\n';
			int wc2Size = wc2.size();
			for (int i = 0; i < wc2Size; ++i) {
				wc2[i].setWaitNum(wc2[i].getWaitNum() - 1);
				++point;
			}
		}
		else cout << "���մ��� �����ϴ�." << '\n';

	case 2:
		if (!wc4.empty()) {
			cout << wc4[point].getName() << "�� ��������" << '\n';
			int wc4Size = wc4.size();
			for (int i = 0; i < wc4Size; ++i) {
				wc4[i].setWaitNum(wc4[i].getWaitNum() - 1);
				++point;
			}
		}
		else cout << "���մ��� �����ϴ�." << '\n';

	case 3:
		if (!wc6.empty()) {
			cout << wc6[point].getName() << "�� ��������" << '\n';
			int wc6Size = wc6.size();
			for (int i = 0; i < wc6Size; ++i) {
				wc6[i].setWaitNum(wc6[i].getWaitNum() - 1);
				++point;
			}
		}
		else cout << "���մ��� �����ϴ�." << '\n';
	}
}
