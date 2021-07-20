#include <iostream>
using namespace std;

/*
n과 m(1) 문제에서 중복 선택 가능하다는 조건이 붙은 문제
*/

int result[8];
bool is_used[9];

void PrintResult(int length_of_result) {
	// 만들어진 result를 length_of_result에 맞추어 출력해주는 함수
	for (int i = 0; i < length_of_result; i++)
	{
		cout << result[i] << " ";
	}

	cout << "\n";

	return;
}

void FillArray(int cur_index, int num_limit, int length_limit) {
	if (cur_index == length_limit) {
		PrintResult(length_limit);
		return;
	}

	for (int i = 1; i <= num_limit; i++)
	{
		result[cur_index] = i;
		FillArray(cur_index + 1, num_limit, length_limit);
	}
}

void Solution15651() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;		// 1~8
	cin >> n >> m;

	FillArray(0, n, m);
}

int main(void) {
	Solution15651();
	return 0;
}