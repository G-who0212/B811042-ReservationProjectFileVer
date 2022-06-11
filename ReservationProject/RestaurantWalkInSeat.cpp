#include "RestaurantWalkInSeat.h"

int RestaurantWalkInSeat::addWaiter(RestaurantInfo rMember) {
	if (rMember.getInfoPeopleNum() <= 2) { // 인원수가 1명 or 2명
		if ((wc2.empty())) {
			cout << rMember.getInfoName() << "님 들어오세요." << '\n';
			wc2.push_back(WalkInCustomer(rMember.getInfoName(), wc2.size()));
			return 0;
		}
		else if ((wc4.empty())) {
			cout << rMember.getInfoName() << "님 들어오세요." << '\n';
			wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
			return 0;
		}
		else if ((wc6.empty())) {
			cout << rMember.getInfoName() << "님 들어오세요." << '\n';
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			return 0;
		}
		else {
			cout << "2자리 테이블 : 1, 4자리 테이블 : 2, 6자리 테이블 : 6 >>";
			int table;
			cin >> table;
			switch (table) {
			case 1:
				wc2.push_back(WalkInCustomer(rMember.getInfoName(), wc2.size()));
				cout << "대기 순번은 " << wc2.size() << "입니다.";
			case 2:
				wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
				cout << "대기 순번은 " << wc4.size() << "입니다.";
			case 3:
				wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
				cout << "대기 순번은 " << wc6.size() << "입니다.";
			}
			return 1;
		}
	}
	else if (rMember.getInfoPeopleNum() <= 4) { // 인원수가 3명 or 4명
		if ((wc4.empty())) {
			cout << rMember.getInfoName() << "님 들어오세요." << '\n';
			wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
			return 0;
		}
		else if ((wc6.empty())) {
			cout << rMember.getInfoName() << "님 들어오세요." << '\n';
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			return 0;
		}
		else {
			cout << "4자리 테이블 : 1, 6자리 테이블 : 2 >>";
			int table;
			cin >> table;
			switch (table) {
			case 1:
				wc4.push_back(WalkInCustomer(rMember.getInfoName(), wc4.size()));
				cout << "대기 순번은 " << wc4.size() << "입니다.";
			case 2:
				wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
				cout << "대기 순번은 " << wc6.size() << "입니다.";
			}
			return 1;
		}
	}
	else if (rMember.getInfoPeopleNum() <= 6) { //인원수가 5명 or 6명
		if ((wc6.empty())) {
			cout << rMember.getInfoName() << "님 들어오세요." << '\n';
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			return 0;
		}
		else {
			wc6.push_back(WalkInCustomer(rMember.getInfoName(), wc6.size()));
			cout << "대기 순번은 " << wc6.size() << "입니다.";
			return 1;
		}
	}
	else { //인원수가 0보다 작거나 7보다 크거나 같음
		cout << "인원이 맞지 않아서 예약이 불가능합니다.";
		return 0;
	}
}

void RestaurantWalkInSeat::callWaiter(int whatTable) { // 어느 테이블 식사(테이블2, 테이블4, 테이블6)가 끝났는지 확인 후 다음 손님 호출
	switch (whatTable) {
	case 1:
		if (!wc2.empty()) {
			cout << wc2[point].getName() << "님 들어오세요" << '\n';
			int wc2Size = wc2.size();
			for (int i = 0; i < wc2Size; ++i) {
				wc2[i].setWaitNum(wc2[i].getWaitNum() - 1);
				++point;
			}
		}
		else cout << "대기손님이 없습니다." << '\n';

	case 2:
		if (!wc4.empty()) {
			cout << wc4[point].getName() << "님 들어오세요" << '\n';
			int wc4Size = wc4.size();
			for (int i = 0; i < wc4Size; ++i) {
				wc4[i].setWaitNum(wc4[i].getWaitNum() - 1);
				++point;
			}
		}
		else cout << "대기손님이 없습니다." << '\n';

	case 3:
		if (!wc6.empty()) {
			cout << wc6[point].getName() << "님 들어오세요" << '\n';
			int wc6Size = wc6.size();
			for (int i = 0; i < wc6Size; ++i) {
				wc6[i].setWaitNum(wc6[i].getWaitNum() - 1);
				++point;
			}
		}
		else cout << "대기손님이 없습니다." << '\n';
	}
}
