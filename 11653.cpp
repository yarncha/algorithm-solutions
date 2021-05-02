#include <iostream>
#include <cmath>
using namespace std;

void Solution11653() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;	// 소인수분해할 수 (범위 1~10,000,000)
	cin >> input_number;
	int root_value = sqrt(input_number);

	bool breaked = false;
	while (input_number > 1)
	{
		for (int i = 2; i <= root_value; i++)
		{
			if (input_number % i == 0) {
				cout << i << "\n";
				input_number = input_number / i;
				breaked = true;
				break;
			}
			else {
				breaked = false;
			}
		}
		if (!breaked) {
			cout << input_number << "\n";
			break;
		}
	}

}

int main(void) {
	Solution11653();
	return 0;
}
