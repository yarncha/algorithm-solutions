#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;
	int output_number = 1;
	cin >> input_number;

	for (int i = 2; i < input_number + 1; i++)
	{
		output_number = output_number * i;
	}
	cout << output_number;
	return 0;
}