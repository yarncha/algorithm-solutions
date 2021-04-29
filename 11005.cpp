#include <iostream>
#include <string>
using namespace std;

// 목표 : 10진법 수 decimal_num이 주어지면 이를 to_change진법으로 변경하는 프로그램 작성

char ModWithAlphabet(int input_decimal, int to_change) {
	// 10진법 수와 바꿀 진법의 수를 넣으면 mod값을 구해줌. 10 이상일 경우 A,B,C...로 출력
	int result_of_mod = input_decimal % to_change;

	if (result_of_mod < 10) {
		return '0' + result_of_mod;
	}
	else {
		return 'A' + result_of_mod - 10;
	}
}

void Solution11005() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int decimal_num;	// 입력받은 10진법 수(0~100,000,000)
	int to_change;		// 바꿀 진법의 수 (2~36)
	cin >> decimal_num >> to_change;

	// 입력받은 10진법 수가 0일 경우 처리
	if (decimal_num == 0) {
		cout << "0";
		return;
	}

	string changed_number = "";
	while (decimal_num > 1) {
		char temp = ModWithAlphabet(decimal_num, to_change);
		changed_number.push_back(temp);

		decimal_num = decimal_num / to_change;
	}
	if (decimal_num == 1) {
		changed_number.push_back('1');
	}

	for (int i = changed_number.size() - 1; i >= 0; i--)
	{
		cout << changed_number.at(i);
	}
}

int main(void) {
	Solution11005();
	return 0;
}
