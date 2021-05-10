#include <iostream>
using namespace std;

// 정수 input_number가 들어오면 이를 1 2 3의 합으로 나타내는 가짓수를 구하는 문제
// 구하려는 f(n) = n을 1 2 3 의 합으로 나타낼 수 있는 가짓수
// n을 1, 2, 3의 합으로  나타내는 방법의 수

void Solution15988() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_test_cases;		// 테스트 케이스의 개수
	cin >> num_of_test_cases;

	int num_of_ways[1000001] = { 0, };
	// 정수 input_number를 1, 2, 3의 합으로 나타내는 방법

	num_of_ways[1] = 1;
	num_of_ways[2] = 2;
	num_of_ways[3] = 4;

	for (int i = 4; i <= 1000000; i++)
	{
		long long sum = (num_of_ways[i - 3] + num_of_ways[i - 2] + num_of_ways[i - 1]) % 1000000009;
		num_of_ways[i] = sum;
		// -3한 것에 +3을 해주는 방법, -2한 것에 -2을 해주는 방법, -1한 것에 +1해주는 방법을 모두 더하면
		// i의 합 나타내는 가짓수를 알 수 있다
	}

	// 위에서 미리 합의 가짓수를 구한 뒤 값을 출력
	int input_number;			// 합의 가짓수를 구하려는 대상 수, 1~1000000의 범위
	for (int i = 0; i < num_of_test_cases; i++)
	{
		cin >> input_number;
		cout << num_of_ways[input_number] << "\n";
	}
}

int main(void) {
	Solution15988();
	return 0;
}