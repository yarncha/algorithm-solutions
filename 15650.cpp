#include <iostream>
using namespace std;

/*
15649문제와 비슷하지만, 이번엔 앞에서 사용한 수보다 하나 큰 수부터 사용할 수 있음

방법 1 : 15649문제의 답을 살짝 바꿔서, 이전거에 따라 값을 결정함
시간복잡도 O(N!)의 방법

방법 2 : 해당 범위에서 몇 개의 수를 선택만 하면 만들 수 있는 수의 조합이 정해져있다는 것에서 착안하여 이를 선택하는 알고리즘
시간복잡도 O(2^N)의 방법, 이를 이용해 구현해봄
*/

bool is_used[9];

void PrintResult(int length_of_number_limits) {
	// 만들어진 result를 length_of_result에 맞추어 출력해주는 함수
	for (int i = 1; i <= length_of_number_limits; i++)
	{
		if (is_used[i]) {
			cout << i << " ";
		}
	}

	cout << "\n";

	return;
}

void PickNum(int cur_length, int dest_length, int cur_num, int num_limit) {
	if (cur_length == dest_length) {
		PrintResult(num_limit);
		return;
	}

	if (cur_num > num_limit) {
		return;
	}

	is_used[cur_num] = true;
	PickNum(cur_length + 1, dest_length, cur_num + 1, num_limit);

	is_used[cur_num] = false;
	PickNum(cur_length, dest_length, cur_num + 1, num_limit);
}

void Solution15650() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;		// 1~8
	cin >> n >> m;

	PickNum(0, m, 1, n);
}

int main(void) {
	Solution15650();
	return 0;
}