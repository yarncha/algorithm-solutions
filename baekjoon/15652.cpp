#include <iostream>
using namespace std;

/*
n과 m 문제와 같은데 이번에는중복 선택 가능, 비내림차순(같은 수를 반복할 수 있는 오름차순)
i+1로 했던 범위에서 1로 할 수 있음

두번째 방법을 선택하는 경우를 i로 세분하는 과정 필요함
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

void FillArray(int cur_index, int num_limit, int length_limit, int start_num) {
	if (cur_index == length_limit) {
		PrintResult(length_limit);
		return;
	}

	for (int i = start_num; i <= num_limit; i++)
	{
		result[cur_index] = i;
		FillArray(cur_index + 1, num_limit, length_limit, i);
	}
}

void Solution15652() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;		// 1~8
	cin >> n >> m;

	FillArray(0, n, m, 1);
}

int main(void) {
	Solution15652();
	return 0;
}