#include <iostream>
#include <string>
using namespace std;

void Solution2089() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int decimal_number;		// 입력받은 10진수
	cin >> decimal_number;

	// 입력받은 수를 -2로 계속 나눠서 -2진수로 만들음
	string result = "";
	char temp;
	while (!(decimal_number == 0 || decimal_number == 1)) {
		if (decimal_number < 0) {
			temp = '0' + (decimal_number % 2 * (-1));
			result.push_back(temp);
			decimal_number = decimal_number / (-2);
			if (temp == '1') {
				decimal_number++;
			}
		}
		else {
			temp = '0' + (decimal_number % 2);
			result.push_back(temp);
			decimal_number = decimal_number / (-2);
		}
	}
	if (decimal_number == 1) {
		result.push_back('1');
	}
	else if (decimal_number == 0) {
		result.push_back('0');
	}

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result.at(i);
	}
}

int main(void) {
	Solution2089();
	return 0;
}