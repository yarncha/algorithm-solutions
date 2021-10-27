#include <iostream>
using namespace std;
int num_of_cases_to_fill_rectangle[31] = { 0, };		// 2xi칸을 채울 때의 경우의 수

/*

2xi칸의 직사각형을 2x1,1x2 직사각형을 채우기 위한 경우의 수를 구하는 문제.
근데 i가 홀수일 때는 채울 수 없으므로 경우의 수가 0이다.

이 문제를 풀기 위해서 낮은 수부터 3x2, 3x4, 3x6.. 의 직사각형을 채우려는 경우의 수를 알아보았을 때,
3x2를 채우기 위한 경우의  수는 3개, 나머지는 2개로 경우의 수가 고정이 되어 있으므로
f(i) = 3*f(i-2) + 2*f(i-4) + ... + 2*f(2) + 2 와 같이 구하면 된다.

*/

void Solution2133() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input;
	cin >> input;

	if (input % 2 != 0) {
		// 홀수일 때는 채울 수 있는 경우의 수가 존재하지 않는다
		cout << 0;
		return;
	}

	num_of_cases_to_fill_rectangle[2] = 3;

	for (int i = 4; i <= input; i += 2)
	{
		num_of_cases_to_fill_rectangle[i] += 3 * num_of_cases_to_fill_rectangle[i - 2];
		for (int j = 4; j < i; j += 2)
		{
			num_of_cases_to_fill_rectangle[i] += 2 * num_of_cases_to_fill_rectangle[i - j];
		}
		num_of_cases_to_fill_rectangle[i] += 2;
	}

	cout << num_of_cases_to_fill_rectangle[input];
}

int main(void) {
	Solution2133();
	return 0;
}