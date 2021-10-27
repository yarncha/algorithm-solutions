#include <iostream>
using namespace std;

// input_number자리의 이친수의 개수를 구하는 문제
// 이친수 : 0으로 시작하지 않으며, 1이 두 번 연속 이어져 있지 않은 이진수

void Solution2193() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;		// 1~90
	cin >> input_number;

	long long num_of_pinary_number[91][2];	// 각 자리수에 대한 이친수의 개수를 구할 배열
										// 두 번째 인자는 끝난 숫자(0인지 1인지)
	num_of_pinary_number[1][0] = 0;
	num_of_pinary_number[1][1] = 1;
	for (int i = 2; i <= input_number; i++)
	{
		num_of_pinary_number[i][0] = num_of_pinary_number[i - 1][1] + num_of_pinary_number[i - 1][0];
		num_of_pinary_number[i][1] = num_of_pinary_number[i - 1][0];
	}

	cout << num_of_pinary_number[input_number][0] + num_of_pinary_number[input_number][1];
}

int main(void) {
	Solution2193();
	return 0;
}