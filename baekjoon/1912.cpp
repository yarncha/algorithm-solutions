#include <iostream>
using namespace std;

int number_array[100001];						// 입력받을 수열
int value_of_maximum_continuous_sum[100001];	// i까지 가장 큰 연속합을 저장할 배열

// i까지 가장 큰 연속합을 value_of_maximum_continuous_sum에 저장해 두고,
// 처음부터 시작해서 앞의 연속합 값과 비교해 나가며 연속합 값이 양수일 때만 때만 뒤에 값에 더해지게 한다

void Solution1912() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 먼저 수열 입력받음
	int length_of_num_array;					// 입력받을 수열의 길이 (1~100000)
	cin >> length_of_num_array;
	for (int i = 0; i < length_of_num_array; i++)
	{
		int temp;								// 수열을 이루고 있는 각 원소 (-1000~1000)
		cin >> temp;
		number_array[i] = temp;
	}

	value_of_maximum_continuous_sum[0] = number_array[0];
	for (int j = 1; j < length_of_num_array; j++)
	{
		if (value_of_maximum_continuous_sum[j - 1] > 0) {
			value_of_maximum_continuous_sum[j] = value_of_maximum_continuous_sum[j - 1] + number_array[j];
		}
		else {
			value_of_maximum_continuous_sum[j] = number_array[j];
		}
	}

	int result = value_of_maximum_continuous_sum[0];
	for (int m = 1; m < length_of_num_array; m++)
	{
		if (value_of_maximum_continuous_sum[m] > result) {
			result = value_of_maximum_continuous_sum[m];
		}
	}
	cout << result;
}

int main(void) {
	Solution1912();
	return 0;
}