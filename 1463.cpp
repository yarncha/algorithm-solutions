#include <iostream>
using namespace std;

// 구하려는 것 : input_number를 1로 만들기 위해 연산을 하는 횟수의 최솟값

int RecursiveCalculator(int input_number, int* value_array) {
	// 배열에 값이 있을 경우는 이를 바로 리턴해준다
	if (input_number < 2) {
		return 0;
	}
	else if (value_array[input_number] > 0) {
		return value_array[input_number];
	}

	// 배열에 값이 없을 경우는 x/3, x/2 x-1중 가장 작은 것에 +1한 것을 배열에 넣고 리턴해준다
	int smallest_value = RecursiveCalculator(input_number - 1, value_array);
	int temp;
	if (input_number % 3 == 0) {
		temp = RecursiveCalculator(input_number / 3, value_array);
		if (smallest_value > temp) {
			smallest_value = temp;
		}
	}
	if (input_number % 2 == 0) {
		temp = RecursiveCalculator(input_number / 2, value_array);
		if (smallest_value > temp) {
			smallest_value = temp;
		}
	}

	value_array[input_number] = smallest_value + 1;
	return smallest_value + 1;
}

void Solution1463() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;	// 범위 1~1000,000
	cin >> input_number;

	int min_number_of_calculation[1000001] = { 0, };
	// min_number_of_calculation[x]는 x를 1로 만들기 위해 연산을 하는 횟수의 최솟값

	cout << RecursiveCalculator(input_number, min_number_of_calculation);
}

int main(void) {
	Solution1463();
	return 0;
}