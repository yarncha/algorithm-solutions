#include <iostream>
using namespace std;
int input_array[1001];					// 주어진 수열 A
int max_length_of_ascending_subarray[1001];		// 주어진 수열에서 (0~i)까지 중 가장 긴 길이를 가지는 증가하는 부분수열의 길이
int max_length_of_descending_subarray[1001];		// 주어진 수열에서 (i~맨 끝)까지 중 가장 긴 길이를 가지는 감소하는 부분수열의 길이

void Solution11054() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int size_of_array;					// 주어진 수열 A의 크기 1~1000
	cin >> size_of_array;


	// 1. 주어진 수열 A를 입력받음
	int value_of_element;				// 수열의 각 원소의 값
	for (int i = 0; i < size_of_array; i++)
	{
		cin >> value_of_element;
		input_array[i] = value_of_element;
	}


	// 2. 주어진 수열에서 0~i범위마다 가장 긴 길이를 가지는 증가하는 부분수열의 길이들을 구함, 이를 배열에 저장
	max_length_of_ascending_subarray[0] = 1;
	for (int j = 1; j < size_of_array; j++)
	{
		int max_value_in_smaller_elements = 0;
		for (int k = 0; k < j; k++)
		{
			// 자신보다 값이 작은 수열의 원소를 찾고,
			// 이들 중 가장 max_length_of_ascending_subarray값이 큰 것
			// (즉, 이전까지 중 가장 긴 증가하는 수열의 길이)을 찾는다
			if (input_array[j] > input_array[k]) {
				if (max_value_in_smaller_elements < max_length_of_ascending_subarray[k]) {
					max_value_in_smaller_elements = max_length_of_ascending_subarray[k];
				}
			}
		}

		// 이전까지 중 가장 긴 길이를 찾았으면, 마지막으로 개수를 1개 더해준 후(자기 자신 추가) 배열에 넣는다
		max_length_of_ascending_subarray[j] = max_value_in_smaller_elements + 1;
	}


	// 3. 주어진 수열에서 각각의 원소마다 가장 긴 길이를 가지는 감소하는 부분수열의 길이를 구함
	max_length_of_descending_subarray[size_of_array - 1] = 1;
	for (int j = size_of_array - 2; j >= 0; j--)
	{
		int max_value_in_bigger_elements = 0;
		for (int k = size_of_array - 1; k > j; k--)
		{
			// 자신보다 값이 작은 수열의 원소를 찾고,
			// 이들 중 가장 max_length_of_descending_subarray값이 큰 것
			// (즉, 이전까지 중 가장 긴 감소하는 수열의 길이)을 찾는다
			if (input_array[j] > input_array[k]) {
				if (max_value_in_bigger_elements < max_length_of_descending_subarray[k]) {
					max_value_in_bigger_elements = max_length_of_descending_subarray[k];
				}
			}
		}

		// 이전까지 중 가장 긴 길이를 찾았으면, 마지막으로 개수를 1개 더해준 후(자기 자신 추가) 배열에 넣는다
		max_length_of_descending_subarray[j] = max_value_in_bigger_elements + 1;
	}


	// 4. i번째 원소를 기준으로 양쪽으로, 증가하는 부분수열의 길이와 감소하는 부분수열의 길이가 최대인 것을 찾고 출력
	int max_length = max_length_of_ascending_subarray[0] + max_length_of_descending_subarray[0] - 1;		// 가장 긴 바이토닉 부분 수열의 길이
	for (int m = 1; m < size_of_array; m++)
	{
		int sum_of_length = max_length_of_ascending_subarray[m] + max_length_of_descending_subarray[m] - 1;
		if (sum_of_length > max_length) {
			max_length = sum_of_length;
		}
	}
	cout << max_length;
}

int main(void) {
	Solution11054();
	return 0;
}
