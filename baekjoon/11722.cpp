#include <iostream>
using namespace std;
int input_array[1001];					// 주어진 수열 A
int max_length_of_subarray[1001];		// 주어진 수열에서 i까지 중 가장 긴 길이를 가지는 부분수열의 합

void Solution11722() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int size_of_array;					// 주어진 수열의 크기 1~1000
	cin >> size_of_array;

	int value_of_element;				// 수열의 각 원소의 값
	for (int i = 0; i < size_of_array; i++)
	{
		// 주어진 수열 A를 입력받음
		cin >> value_of_element;
		input_array[i] = value_of_element;
	}

	max_length_of_subarray[0] = 1;
	int max_length = max_length_of_subarray[0];		// 가장 긴 감소하는 부분 수열의 길이
	for (int j = 1; j < size_of_array; j++)
	{
		int max_value_in_smaller_elements = 0;
		for (int k = 0; k < j; k++)
		{
			// 자신보다 값이 큰 수열의 원소를 찾고,
			// 이들 중 가장 max_length_of_subarray값이 큰 것
			// (즉, 이전까지 중 가장 긴 감소하는 수열의 길이)을 찾는다
			if (input_array[j] < input_array[k]) {
				if (max_value_in_smaller_elements < max_length_of_subarray[k]) {
					max_value_in_smaller_elements = max_length_of_subarray[k];
				}
			}
		}

		// 이전까지 중 가장 긴 길이를 찾았으면, 마지막으로 개수를 1개 더해준 후(자기 자신 추가) 배열에 넣는다
		max_length_of_subarray[j] = max_value_in_smaller_elements + 1;

		if (max_length < max_length_of_subarray[j]) {
			// 나중에 출력해줄 max_length(가장 긴 감소하는 부분 수열의 길이) 계산
			max_length = max_length_of_subarray[j];
		}
	}

	cout << max_length;
}

int main(void) {
	Solution11722();
	return 0;
}