#include <iostream>
#include <string>
using namespace std;

// 어떤 수 number가 소수인지를 판단하기 위한 함수
bool is_prime(int number) {
	// 2보다 작을 때에는 소수가 아님
	if (number < 2)
	{
		return false;
	}

	// 루트 number보다 작은 수들 중에서 number를 나누어 떨어지게 하는 수가 있는지 판단
	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_input, current;
	cin >> num_of_input;

	int num_of_prime = 0;
	for (int i = 0; i < num_of_input; i++)
	{
		cin >> current;
		if (is_prime(current)) {
			num_of_prime++;
		}
	}

	cout << num_of_prime;

	return 0;
}