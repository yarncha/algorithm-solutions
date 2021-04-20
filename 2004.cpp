#include <iostream>
#include <algorithm>
using namespace std;

int count_two(int input_number) {
	int number_of_zeros = 0;
	while (input_number >= 2)
	{
		number_of_zeros += input_number / 2;
		input_number = input_number / 2;
	}
	return number_of_zeros;
}

int count_five(int input_number) {
	int number_of_zeros = 0;
	while (input_number >= 5)
	{
		number_of_zeros += input_number / 5;
		input_number = input_number / 5;
	}
	return number_of_zeros;
}

void solution_2004() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);

	//조합에서 각각의 분모 분자마다 2와 5의 개수를 센 후 빼준다.
	int num_of_two = 0;
	int num_of_five = 0;
	int n, r;

	cin >> n >> r;
	if (r == 0 && r == n) {
		cout << "0";
		return;
	}

	num_of_two = count_two(n) - count_two(n - r) - count_two(r);
	num_of_five = count_five(n) - count_five(n - r) - count_five(r);

	cout << min(num_of_five, num_of_two);
}

int main(void) {
	solution_2004();
	return 0;
}
