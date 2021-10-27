#include <iostream>
using namespace std;

// 수열 number_array가 주어지고, 이 수열에서 가장 긴 증가하는 수열의 길이를 출력하는 문제
// 구하려는 문제 length_of_ascending_array[i]를 "i번째 숫자를 마지막으로 하는 수열 중 가장 긴 수열의 길이"로 두고,
// 1번째 숫자부터 시작해서 이전 숫자들을 모두 비교해나가며 현재 숫자보다 큰 숫자 중 가장 길이가 길었던 길이에 +1하면서
// 각 숫자들에 따라 이 숫자로 끝나는 가장 긴 수열들을 구했다
// 다 구한 후, 전체에서 가장 긴 길이를 출력하면 끝

void Solution11053() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 먼저 수열을 입력받음
	int length_of_num_array;						// 입력받을 수열의 크기 (1~1000)
	cin >> length_of_num_array;
	int number_array[1001];							// 입력받을 수열
	for (int i = 0; i < length_of_num_array; i++)
	{
		int temp;									// 수열을 이루고 있는 각 원소 (1~1000)
		cin >> temp;
		number_array[i] = temp;
	}

	// i번째 숫자를 마지막으로 하는 수열 중 가장 긴 수열의 길이를 구한다
	int length_of_ascending_array[1001];			// i번째 숫자를 마지막으로 하는 수열중 가장 긴 길이를 저장할 배열
	length_of_ascending_array[0] = 1;
	for (int j = 1; j < length_of_num_array; j++)
	{
		int max_length = 0;
		for (int k = 0; k < j; k++)
		{
			if (number_array[j] > number_array[k] && length_of_ascending_array[k] > max_length) {
				max_length = length_of_ascending_array[k];
			}
		}
		length_of_ascending_array[j] = max_length + 1;
	}

	// 마지막으로 최대값을 찾아서 프린트
	int result = length_of_ascending_array[0];
	for (int m = 1; m < length_of_num_array; m++)
	{
		if (length_of_ascending_array[m] > result) {
			result = length_of_ascending_array[m];
		}
	}
	cout << result;
}

int main(void) {
	Solution11053();
	return 0;
}