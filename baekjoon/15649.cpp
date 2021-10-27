#include <iostream>
using namespace std;

/*
중복 없이 M개를 구함, 순서와 관련된 문제임
왜냐면 각각의 자리에 어떤 수가 들어가는 지 알아야 다음 수에 뭐가 들어갈지를 알 수 있기 때문
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
		if (!is_used[i]) {
			result[cur_index] = i;
			is_used[i] = true;
			FillArray(cur_index + 1, num_limit, length_limit);
			is_used[i] = false;
		}
	}
}

void Solution15649() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;		// 1~8
	cin >> n >> m;

	FillArray(0, n, m);
}

int main(void) {
	Solution15649();
	return 0;
}