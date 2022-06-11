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
	cout << "프로그램 종료 전 입력되었던 내용들을 열람할 것인가요? (열람하면 1, 아니면 0) >>" << endl;
	cin >> restoreData;
	const char* file = "reservationData.txt";
	if (restoreData == 1) {
		ifstream fin(file);
		if (!fin) {
			cout << file << " 열기 오류" << endl;
			return 0;
		}
		int count = 0;
		int c;
		while ((c = fin.get()) != EOF) {
			cout << (char)c;;
			count++;
		}
		if (count == 0) cout << "reservationData.txt 파일에 아무 내용이 없습니다." << endl;
	}

	while (1) {
		cout << "어떤 서비스를 이용하실 것인가요?" << '\n';
		cout << "비행기 서비스 : 1, 식당 서비스 : 2, 독서실 서비스 : 3 >>";
		int service;
		cin >> service;
		switch (service) {
		case 1:
			cout << "회원가입이 되어있나요? (안되어있으면 0, 되어있으면 1을 입력해주세요) >> ";
			int memberCheck;
			cin >> memberCheck;
			if (memberCheck == 0) {
				joinMember(data, airplane);
				break;
			}
			else if (memberCheck == 1) {
				login(data, airplane); // 로그인 성공시에 예약서비스까지 돌아감
				break;
			}
		case 2:
			cout << "회원가입이 되어있나요? (안되어있으면 0, 되어있으면 1을 입력해주세요) >> ";
			int memberCheck2;
			cin >> memberCheck2;
			if (memberCheck2 == 0) {
				joinMember(data, restaurant, walkIn);
				break;
			}
			else if (memberCheck2 == 1) {
				login(data, restaurant, walkIn); // 로그인 성공시 예약서비스까지 돌아감
				break;
			}
			else break;
		case 3:
			cout << "회원가입이 되어있나요? (안되어있으면 0, 되어있으면 1을 입력해주세요) >> ";
			int memberCheck3;
			cin >> memberCheck3;
			if (memberCheck3 == 0) {
				joinMember(data, familyData, library);
				break;
			}
			else if (memberCheck3 == 1) {
				login(data, familyData, library); // 로그인 성공시에 예약서비스까지 돌아감
				break;
			}
		}
	}
}