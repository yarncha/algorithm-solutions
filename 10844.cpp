#include <iostream>
using namespace std;

// 수의 길이가 input_number인 계단 수가 몇 개 있는지 구하는 문제

void Solution10844() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;	// 해당 길이의 계단수의 수를 구하면 된다, 1~100 범위의 자연수
	cin >> input_number;
	long long num_of_stair_number_starts[101][10];
	// num_of_stair_number_starts[a][b]는 a 길이의 계단수 중 b로 끝나는 수의 개수

	// n길이를 가진 계단수를 구하는 방법은
	// n-1길이의 계단수의 끝나는 수에 맞춰서 -1한 수나 +1한 수를 각 자리에 맞게 넣어주면 된다
	// 우선, 한자리수를 먼저 채워 준다
	num_of_stair_number_starts[1][0] = 0;
	num_of_stair_number_starts[1][1] = 1;
	num_of_stair_number_starts[1][2] = 1;
	num_of_stair_number_starts[1][3] = 1;
	num_of_stair_number_starts[1][4] = 1;
	num_of_stair_number_starts[1][5] = 1;
	num_of_stair_number_starts[1][6] = 1;
	num_of_stair_number_starts[1][7] = 1;
	num_of_stair_number_starts[1][8] = 1;
	num_of_stair_number_starts[1][9] = 1;

	for (int i = 2; i <= input_number; i++)
	{
		num_of_stair_number_starts[i][0] = num_of_stair_number_starts[i - 1][1];
		num_of_stair_number_starts[i][1] = (num_of_stair_number_starts[i - 1][0] + num_of_stair_number_starts[i - 1][2]) % 1000000000;
		num_of_stair_number_starts[i][2] = (num_of_stair_number_starts[i - 1][1] + num_of_stair_number_starts[i - 1][3]) % 1000000000;
		num_of_stair_number_starts[i][3] = (num_of_stair_number_starts[i - 1][2] + num_of_stair_number_starts[i - 1][4]) % 1000000000;
		num_of_stair_number_starts[i][4] = (num_of_stair_number_starts[i - 1][3] + num_of_stair_number_starts[i - 1][5]) % 1000000000;
		num_of_stair_number_starts[i][5] = (num_of_stair_number_starts[i - 1][4] + num_of_stair_number_starts[i - 1][6]) % 1000000000;
		num_of_stair_number_starts[i][6] = (num_of_stair_number_starts[i - 1][5] + num_of_stair_number_starts[i - 1][7]) % 1000000000;
		num_of_stair_number_starts[i][7] = (num_of_stair_number_starts[i - 1][6] + num_of_stair_number_starts[i - 1][8]) % 1000000000;
		num_of_stair_number_starts[i][8] = (num_of_stair_number_starts[i - 1][7] + num_of_stair_number_starts[i - 1][9]) % 1000000000;
		num_of_stair_number_starts[i][9] = num_of_stair_number_starts[i - 1][8];
	}

	cout << (num_of_stair_number_starts[input_number][0] + num_of_stair_number_starts[input_number][1] + num_of_stair_number_starts[input_number][2] + num_of_stair_number_starts[input_number][3] + num_of_stair_number_starts[input_number][4] + num_of_stair_number_starts[input_number][5] + num_of_stair_number_starts[input_number][6] + num_of_stair_number_starts[input_number][7] + num_of_stair_number_starts[input_number][8] + num_of_stair_number_starts[input_number][9]) % 1000000000;
}

int main(void) {
	Solution10844();
	return 0;
}
