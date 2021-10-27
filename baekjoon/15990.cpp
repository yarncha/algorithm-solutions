#include <iostream>
using namespace std;

// 1, 2, 3의 합으로 나타내는데, 같은 수를 두 번 이상 중복하면 안 된다는 조건이 붙음
// 알고리즘은 완벽하게 짰는데 범위... 범위 유의하자.

void Solution15990() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long num_of_ways_sum[100001][4];		// n을 1,2,3의 합으로 나타낼 수 있는 가짓수, 마지막에 사용한 수도 나타냄
	num_of_ways_sum[1][1] = 1;
	num_of_ways_sum[1][2] = 0;
	num_of_ways_sum[1][3] = 0;
	num_of_ways_sum[2][1] = 0;
	num_of_ways_sum[2][2] = 1;
	num_of_ways_sum[2][3] = 0;
	num_of_ways_sum[3][1] = 1;
	num_of_ways_sum[3][2] = 1;
	num_of_ways_sum[3][3] = 1;
	for (int j = 4; j <= 100000; j++)
	{
		// j를 123의 합으로 나타낼 수 있는 가짓수를 구하기 위해서는
		// num_of_ways_sum[j-1][2], num_of_ways_sum[j-1][3]에 1을 더한 경우,
		// num_of_ways_sum[j-2][1], num_of_ways_sum[j-2][3]에 2을 더한 경우,
		// num_of_ways_sum[j-3][2], num_of_ways_sum[j-3][1]에 3을 더한 경우,
		// 이렇게 세 경우이므로, 이 경우 가짓수들을 구해 모두 각각의 배열 자리에 넣어주면 된다.
		num_of_ways_sum[j][1] = (num_of_ways_sum[j - 1][2] + num_of_ways_sum[j - 1][3]) % 1000000009;
		num_of_ways_sum[j][2] = (num_of_ways_sum[j - 2][1] + num_of_ways_sum[j - 2][3]) % 1000000009;
		num_of_ways_sum[j][3] = (num_of_ways_sum[j - 3][2] + num_of_ways_sum[j - 3][1]) % 1000000009;
	}

	int num_of_test_cases;		// 테스트케이스의 개수
	cin >> num_of_test_cases;

	int input_number;			// 1 2 3의 합으로 나타낼 수 있는 가짓수를 구할 수 (1~1000000)
	for (int i = 0; i < num_of_test_cases; i++)
	{
		cin >> input_number;
		long long result = num_of_ways_sum[input_number][1] + num_of_ways_sum[input_number][2] + num_of_ways_sum[input_number][3];
		cout << (result) % 1000000009 << "\n";
	}
}

int main(void) {
	Solution15990();
	return 0;
}