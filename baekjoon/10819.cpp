#include <iostream>
#include <algorithm>
using namespace std;

/*
num_of_input개의 정수(범위는 -100~100)로 이루어진 배열 input_arr가 주어지는데, 이 숫자들의 순서를 적절히 바꿔서 서로의 차이의 합을 최대로 하는 문제

한 배열이 있을 때, 이 차이를 구하는 연산은 O(N)
모든 배열에 대해서 이 연산을 수행하면 전체 순열을 구하는 것이므로 O(N*N!)

보면 범위가 8까지기 때문에 모든 순열에 대해서 다 구해봐도 됨

그러므로 먼저 정렬을 통해 첫 순열을 만들어본 뒤 차이를 구해본다.
*/

int input_arr[8];

int CalculateInterval(int num_of_inputs) {
	// 주어진 배열에 대해 서로의 차이를 구해주는 함수
	int sum_of_intervals = 0;

	for (int i = 0; i < num_of_inputs - 1; i++)
	{
		int interval = input_arr[i] - input_arr[i + 1];
		if (interval < 0) {
			sum_of_intervals -= interval;
		}
		else {
			sum_of_intervals += interval;
		}
	}

	return sum_of_intervals;
}

void Solution10819() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력받는 부분
	int num_of_inputs;		// 3~8
	cin >> num_of_inputs;

	for (int i = 0; i < num_of_inputs; i++)
	{
		cin >> input_arr[i];		// -100~100
	}

	// 첫 순열로 만들기 위해 정렬
	sort(input_arr, input_arr + num_of_inputs);

	// 모든 순열에 대해 차이를 구해봄
	int max_sum_of_intervals = 0;
	while (next_permutation(input_arr, input_arr + num_of_inputs))
	{
		int sum_of_intervals = CalculateInterval(num_of_inputs);
		if (max_sum_of_intervals < sum_of_intervals) {
			max_sum_of_intervals = sum_of_intervals;
		}
	}

	cout << max_sum_of_intervals << "\n";
}

int main(void) {
	Solution10819();
	return 0;
}