#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;
	cin >> input_number;

	int number_of_zeros = 0;

	// 인수로 5가 들어가는 것들의 개수를 구하기 위해서는 5로 나눠주면 된다.
	// 100!의 경우 100/5는 20이므로 20개가 있는데, 이들 중 25와 같이 5*5, 5가 두 개 이상 들어가 있는 경우도 있으므로
	// 이를 다시 5로 나누어주면 25로 나눈 것들을 구할 수 있으므로 한번씩 더 세어주면 된다.
	while (input_number >= 5)
	{
		number_of_zeros += input_number / 5;
		input_number = input_number / 5;
	}

	cout << number_of_zeros;
	return 0;
}