#include <iostream>
#include <algorithm>
using namespace std;

/*
이전 순열을 구하는 알고리즘을 익히기 위해 직접 짜본 코드
*/

bool my_next_permutation(int* input_array, int array_size) {
	// input_array를 이전 순열로 바꿔 주고, 그렇게 하지 못할 경우에는 false를 출력해주는 함수

	// 1. input_array의 뒤에서부터 살펴보면서, 뒤에서부터 가장 길게 오름차순인 부분을 찾는다. 148"2356" 이런 array가 주어진다고 하면, 2356부분은 가장 긴, 끝에서부터 연결된 오름차순이니까 148으로 시작하는 첫 순열임을 알 수가 있다.
	// 만약 여기서 모든 수열이 234567와 같이 오름차순이면, 이전 순열은 없으므로 false
	int end = 0;
	for (int i = array_size - 2; i >= 0; i--)
	{
		if (input_array[i] > input_array[i + 1]) {
			end = i + 1;
			break;
		}
	}

	if (array_size == 1 || end == 0) {
		return false;
	}

	// 2. 주어진 순열의 이전 순열은 14?로 시작하는 마지막 순열, 이 ?자리는 뒤에 있는 오름차순 부분에서 8보다 작은 수 중 가장 큰 수가 들어가야 하므로 탐색하면서 구한 뒤 8과 위치를 바꿔준다.
	int index = end;
	while (index < array_size && input_array[index]<input_array[end - 1])
	{
		index++;
	}
	int temp = input_array[index - 1];
	input_array[index - 1] = input_array[end - 1];
	input_array[end - 1] = temp;

	// 3. 이제 오름차순이었던 순열을 뒤집음
	int front_index = end;
	int back_index = array_size - 1;
	while (front_index < back_index)
	{
		int temp2 = input_array[back_index];
		input_array[back_index] = input_array[front_index];
		input_array[front_index] = temp2;

		front_index++;
		back_index--;
	}

	return true;
}

void Solution10973Ver2() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_limit;			// 1~num_limit까지의 수로 이루어진 순열이 주어질 것
	cin >> num_limit;

	int num_arr[10000];
	for (int i = 0; i < num_limit; i++)
	{
		cin >> num_arr[i];
	}

	if (!my_next_permutation(num_arr, num_limit)) {
		cout << "-1\n";
	}
	else {
		for (int j = 0; j < num_limit; j++)
		{
			cout << num_arr[j] << " ";
		}
	}
}

int main(void) {
	Solution10973Ver2();
	return 0;
}