#include <iostream>
using namespace std;

/*
음수 피보나치 수열은 양수 피보나치 수열과 절댓값은 같다.
출력해야 하는 값이 절댓값이므로 그냥 양수 피보나치 값만 DP로 구한 뒤 값 출력하는 방식으로 했다

** 한 다섯번은 틀렸는데 그 이유가 "첫째 줄에 F(n)이 양수이면 1, 0이면 0, 음수이면 -1을 출력한다" 이 부분을 제대로 못 읽어서ㅜ f(n)이 아니라 n인 줄 알았다.
*/

int fibonacciValue[1000001];				// 피보나치 값을 저장할 배열

void GetFibonacciValue(int destination) {
	// 피보나치 값을 구할 함수
	for (int i = 2; i <= destination; i++)
	{
		long long value = (fibonacciValue[i - 1] + fibonacciValue[i - 2]) % 1000000000;
		fibonacciValue[i] = value;
	}
	return;
}

void Solution1788() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input;			// 입력받은 n
	cin >> input;

	if (input == 0) {
		cout << "0\n0";
		return;
	}
	else if (input > 0) {
		// 양수
		cout << "1\n";
	}
	else {
		// 음수
		if (input % 2 == 0) {
			cout << "-1\n";
		}
		else {
			cout << "1\n";
		}
		input *= -1;
	}

	fibonacciValue[1] = 1;
	if (input > 1) {
		GetFibonacciValue(input);
	}
	cout << fibonacciValue[input];
}

int main(void) {
	Solution1788();
	return 0;
}