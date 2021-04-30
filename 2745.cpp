#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int CalculateValue(char input) {	//pass by reference 고려해보기. 완성한다음 고치기
	if (input >= 'A') {
		return input - 'A' + 10;
	}
	else {
		return input - '0';
	}
}

void Solution2745() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string input_number;
	int base;	//base진법 수 input number가 주어짐. 각각(2~36,(10진법으로 바꾸면)100,000,000이하)

	getline(cin, input_number, ' ');
	cin >> base;

	int result_decimal = 0;
	int val_of_pows = 0;
	for (int i = input_number.size() - 1; i >= 0; i--)
	{
		int value_of_char = CalculateValue(input_number.at(i));
		result_decimal += pow(base, val_of_pows) * value_of_char;
		val_of_pows++;
	}

	cout << result_decimal;
}

int main(void) {
	Solution2745();
	return 0;
}
