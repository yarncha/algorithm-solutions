#include <iostream>
#include <string>
using namespace std;

// 목표 : 8진수 octal_number를 입력받고(수의 길이 최대 333,334), 이를 2진수로 바꾼다
// 8진수를 뒤에서부터 한 글자씩 읽으며 2진수로 변경할 수 있음

void OctalToBinaryChanger(int index, string& input_string) {
	// 재귀적으로 string의 뒤에서부터 1자리씩 2진수로 바꿔주는 함수

	if (index == 0) {
		int calculated = 0;		// 2진수로 계산한 값을 저장할 변수 (진짜 2진수 자체의 값은 아님)
		int current_number = input_string.at(index) - '0';
		if (current_number >= 4) {
			calculated += 100;
			current_number -= 4;
		}
		if (current_number >= 2) {
			calculated += 10;
			current_number -= 2;
		}
		if (current_number >= 1) {
			calculated += 1;
		}
		cout << calculated;
		return;
	}
	else if (index > 0) {
		OctalToBinaryChanger(index - 1, input_string);
	}

	int current_number = input_string.at(index) - '0';
	if (current_number >= 4) {
		cout << "1";
		current_number -= 4;
	}
	else {
		cout << "0";
	}

	if (current_number >= 2) {
		cout << "1";
		current_number -= 2;
	}
	else {
		cout << "0";
	}

	if (current_number >= 1) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}

void Solution1212() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string octal_number;	// 입력받은 8진수
	getline(cin, octal_number);

	// 입력받은 8진수를 뒤에서부터 1자리씩 읽으며 그에 맞는 2진수로 바꿔 출력한다
	OctalToBinaryChanger(octal_number.size() - 1, octal_number);
}

int main(void) {
	Solution1212();
	return 0;
}