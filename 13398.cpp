#include <iostream>
using namespace std;
int number_array[100001];									// 입력받을 수열
int max_sum_of_continuous_numbers_end_with[100001];			// i번째 원소를 끝으로 하는 최대 연속합
int max_sum_of_continuous_numbers_start_with[100001];		// i번째 원소를 시작으로 하는 최대 연속합

void Solution13398() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 먼저 수열 입력받음
	int length_of_num_array;					// 입력받을 수열의 길이 (1~100000)
	cin >> length_of_num_array;
	for (int i = 0; i < length_of_num_array; i++)
	{
		int temp;								// 수열을 이루고 있는 각 원소 (-1000~1000)
		cin >> temp;
		number_array[i] = temp;
	}

	// 2. 각 i들에 대해 i번째 원소를 끝/시작으로 하는 최대 연속합 각각 계산
	max_sum_of_continuous_numbers_end_with[0] = number_array[0];
	max_sum_of_continuous_numbers_start_with[length_of_num_array - 1] = number_array[length_of_num_array - 1];
	for (int j = 1; j < length_of_num_array; j++)
	{
		// 끝으로 하는 연속합 계산하는 부분
		if (max_sum_of_continuous_numbers_end_with[j - 1] > 0) {
			max_sum_of_continuous_numbers_end_with[j] = max_sum_of_continuous_numbers_end_with[j - 1] + number_array[j];
		}
		else {
			max_sum_of_continuous_numbers_end_with[j] = number_array[j];
		}

		// 시작으로 하는 연속합 계산하는 부분
		if (max_sum_of_continuous_numbers_start_with[length_of_num_array - j] > 0) {
			max_sum_of_continuous_numbers_start_with[length_of_num_array - 1 - j] = max_sum_of_continuous_numbers_start_with[length_of_num_array - j] + number_array[length_of_num_array - 1 - j];
		}
		else {
			max_sum_of_continuous_numbers_start_with[length_of_num_array - 1 - j] = number_array[length_of_num_array - 1 - j];
		}
	}

	// 3. 마지막으로, 가장 큰 연속합을 구하기 위한 부분
	int result = max_sum_of_continuous_numbers_end_with[0];
	for (int m = 1; m < length_of_num_array; m++)
	{
		if (max_sum_of_continuous_numbers_end_with[m] > result) {
			result = max_sum_of_continuous_numbers_end_with[m];
		}
	}

	for (int n = 1; n < length_of_num_array - 1; n++)
	{
		int sum_of_both_side = max_sum_of_continuous_numbers_end_with[n - 1] + max_sum_of_continuous_numbers_start_with[n + 1];
		if (sum_of_both_side > result) {
			result = sum_of_both_side;
		}
	}
	cout << result;
}

int main(void) {
	Solution13398();
	return 0;
}