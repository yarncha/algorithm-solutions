#include <iostream>
using namespace std;

// DP 문제
// 

void Solution11727() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;		// 범위 1~1000
	cin >> input_number;

	int num_of_ways_to_fill_rectangular[1001] = { 0, };
	// num_of_ways_to_fill_rectangular[i]는 2xi인 직사각형을 채우는 방법의 수

	num_of_ways_to_fill_rectangular[1] = 1;
	num_of_ways_to_fill_rectangular[2] = 3;
	for (int i = 3; i <= input_number; i++)
	{
		num_of_ways_to_fill_rectangular[i] = (num_of_ways_to_fill_rectangular[i - 2]*2 + num_of_ways_to_fill_rectangular[i - 1]) % 10007;
		// 2xi인 직사각형을 채우는 방법의 수는, 2x(i-2)직사각형을 채우는 방법의 수에 2를 곱한 것과 2x(i-1)직사각형을 채우는 방법의 수를 더한 것과 같다
		// 단, 수가 너무 크게 나올 수 있기 때문에 미리 %10007을 해 준다
		// 미리 해주나 마지막에 해 주나 해는 동일함
	}

	cout << num_of_ways_to_fill_rectangular[input_number];
}

int main(void) {
	Solution11727();
	return 0;
}
