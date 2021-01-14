#include <iostream>
#include <string>
using namespace std;

// 소수 계산
bool is_prime(int number) {
	if (number < 2)
	{
		return false;
	}

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
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);


	int a, b;
	cin >> a >> b;
	cout << "qwer";
	return 0;
}