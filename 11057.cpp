#include <iostream>
using namespace std;

long long num_of_ascending_numbers[1001][10] = { 0, };		// 길이가 i이며, j로 끝나는 오르막 수의 개수

void Solution11057() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int length_of_number;
	cin >> length_of_number;

	num_of_ascending_numbers[1][0] = 1;
	num_of_ascending_numbers[1][1] = 1;
	num_of_ascending_numbers[1][2] = 1;
	num_of_ascending_numbers[1][3] = 1;
	num_of_ascending_numbers[1][4] = 1;
	num_of_ascending_numbers[1][5] = 1;
	num_of_ascending_numbers[1][6] = 1;
	num_of_ascending_numbers[1][7] = 1;
	num_of_ascending_numbers[1][8] = 1;
	num_of_ascending_numbers[1][9] = 1;
	for (int i = 2; i <= length_of_number; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				num_of_ascending_numbers[i][j] += num_of_ascending_numbers[i - 1][k];
			}
			num_of_ascending_numbers[i][j] %= 10007;
		}
	}

	long long sum = 0;
	for (int m = 0; m < 10; m++)
	{
		sum += num_of_ascending_numbers[length_of_number][m];
	}
	cout << sum % 10007;
}

int main(void) {
	Solution11057();
	return 0;
}
