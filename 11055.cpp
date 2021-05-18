#include <iostream>
using namespace std;
int input_array[1001];					// 주어진 수열 A
int max_sum_of_subarray[1001];			// 주어진 수열에서 i까지 중 가장 큰 합을 가지는 부분수열의 합

void Solution11055() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int maximum = 0;

	int size_of_array;					// 주어진 수열의 크기 1~1000
	cin >> size_of_array;

	int value_of_element;				// 수열의 각 원소의 값
	for (int i = 0; i < size_of_array; i++)
	{
		// 주어진 수열 A를 입력받음
		cin >> value_of_element;
		input_array[i] = value_of_element;
	}

	max_sum_of_subarray[0] = input_array[0];
	maximum = max_sum_of_subarray[0];
	for (int j = 1; j < size_of_array; j++)
	{
		int max_value_in_smaller_elements = 0;
		for (int k = 0; k < j; k++)
		{
			// 자신보다 값이 작은 수열의 원소를 찾고,
			// 이들 중 가장 max_sum_of_subarray값이 큰 것을 찾는다
			if (input_array[j] > input_array[k]) {
				if (max_value_in_smaller_elements < max_sum_of_subarray[k]) {
					max_value_in_smaller_elements = max_sum_of_subarray[k];
				}
			}
		}

		// 가장 큰 값을 찾았으면, 마지막으로 자신의 값을 더해준 후 배열에 넣는다
		max_sum_of_subarray[j] = max_value_in_smaller_elements + input_array[j];
		if (maximum < max_sum_of_subarray[j]) {
			// 나중에 출력할 maximum 계산
			maximum = max_sum_of_subarray[j];
		}
	}

	cout << maximum;
}

int main(void) {
	Solution11055();
	return 0;
}
