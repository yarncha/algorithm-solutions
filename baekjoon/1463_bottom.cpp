#include <iostream>
using namespace std;

// 구하려는 것 : input_number를 1로 만들기 위해 연산을 하는 횟수의 최솟값

void Solution1463BottomUp() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;	// 범위 1~1000,000
	cin >> input_number;

	int min_number_of_calculation[1000000] = { 0, };
	// min_number_of_calculation[x]는 x를 1로 만들기 위해 연산을 하는 횟수의 최솟값

	int value = 0;
	for (int i = 2; i <= input_number; i++)
	{
		value = min_number_of_calculation[i - 1];
		if (i % 3 == 0) {
			if (value > min_number_of_calculation[i / 3]) {
				value = min_number_of_calculation[i / 3];
			}
		}
		if (i % 2 == 0) {
			if (value > min_number_of_calculation[i / 2]) {
				value = min_number_of_calculation[i / 2];
			}
		}
		min_number_of_calculation[i] = value + 1;
	}

	cout << min_number_of_calculation[input_number];
}

int main(void) {
	Solution1463BottomUp();
	return 0;
}