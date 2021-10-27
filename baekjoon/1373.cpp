#include <iostream>
#include <string>
using namespace std;

// 목표 : 2진수 binary_number를 입력받고(수의 길이 최대 1,000,000), 이를 8진수로 바꾼다
// 2진수에서 매 3자리마다 8진수 1자리로 바꿀 수 있다. 이를 이용해 2진수를 3개씩 읽으며 계산

void BinaryToOctalChanger(int index, string& input_string) {
	// 재귀적으로 string의 뒤에서부터 3자리씩 연산하는 함수

	int calculated = 0;		// 8진수로 계산한 값을 저장할 변수

	if (index < 2) {
		if (input_string.at(index) == '1') {
			calculated += 1;
		}
		if (index >= 1 && input_string.at(index - 1) == '1') {
			calculated += 2;
		}
		cout << calculated;
	}
	else {
		if (index >= 3) {
			BinaryToOctalChanger(index - 3, input_string);
		}

		if (input_string.at(index) == '1') {
			calculated += 1;
		}
		if (input_string.at(index - 1) == '1') {
			calculated += 2;
		}
		if (input_string.at(index - 2) == '1') {
			calculated += 4;
		}
		cout << calculated;
	}
}

void Solution1373() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string binary_number;
	getline(cin, binary_number);

	// 입력받은 2진수를 뒤에서부터 3자리씩 읽으며 8진수로 바꿔 출력한다
	BinaryToOctalChanger(binary_number.size() - 1, binary_number);
}

int main(void) {
	Solution1373();
	return 0;
}