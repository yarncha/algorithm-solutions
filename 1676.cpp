#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;
	cin >> input_number;

	int number_of_zeros = 0;

	while (input_number >= 5)
	{
		number_of_zeros += input_number / 5;
		input_number = input_number / 5;
	}

	cout << number_of_zeros;
	return 0;
}