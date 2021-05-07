#include <iostream>
using namespace std;

int number_array[1001];							// 입력받을 수열
int length_of_ascending_array[1001][2];			// i번째 숫자를 마지막으로 하는 수열중 가장 긴 길이와 이전 숫자의 인덱스를 저장할 배열

void PrintArray(int start_index) {
	if (length_of_ascending_array[start_index][1] == -1) {
		cout << number_array[start_index];
	}
	else {
		PrintArray(length_of_ascending_array[start_index][1]);
		cout << " " << number_array[start_index];
	}
	return;
}

void Solution14002() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 먼저 수열을 입력받음
	int length_of_num_array;						// 입력받을 수열의 크기 (1~1000)
	cin >> length_of_num_array;
	for (int i = 0; i < length_of_num_array; i++)
	{
		int temp;									// 수열을 이루고 있는 각 원소 (1~1000)
		cin >> temp;
		number_array[i] = temp;
	}

	// i번째 숫자를 마지막으로 하는 수열 중 가장 긴 수열의 길이를 구한다
	length_of_ascending_array[0][0] = 1;
	length_of_ascending_array[0][1] = -1;
	for (int j = 1; j < length_of_num_array; j++)
	{
		int max_length = 0;
		length_of_ascending_array[j][1] = -1;
		for (int k = 0; k < j; k++)
		{
			if (number_array[j] > number_array[k] && length_of_ascending_array[k][0] > max_length) {
				max_length = length_of_ascending_array[k][0];
				length_of_ascending_array[j][1] = k;
			}
		}
		length_of_ascending_array[j][0] = max_length + 1;
	}

	// 마지막으로 최대값을 찾고, [][1] 배열에 저장된 인덱스를 따라가며 배열을 출력한다
	int result_index = 0;
	for (int m = 1; m < length_of_num_array; m++)
	{
		if (length_of_ascending_array[m][0] > length_of_ascending_array[result_index][0]) {
			result_index = m;
		}
	}
	cout << length_of_ascending_array[result_index][0] << "\n";
	PrintArray(result_index);
}

int main(void) {
	Solution14002();
	return 0;
}
