#include <iostream>
#include <algorithm>
using namespace std;

int numbers[8];			// 입력을 주어진 수를 저장할 배열
int result[8];			// 결과로 출력할 수를 저장할 배열
bool is_used[9];		// numbers에서 i번째에 있는 수를 사용했는지 여부
int using_num[9];		// 같은 숫자 재사용을 막기 위한 배열

void PrintResult(int length_of_result) {
	// 만들어진 result를 length_of_result에 맞추어 출력해주는 함수

	for (int i = 0; i < length_of_result; i++)
	{
		cout << result[i] << " ";
	}
	cout << "\n";

	return;
}

void FillArray(int cur_index, int start_index, int num_limit, int length_limit) {
	// result 배열에 알맞는 값을 집어넣는 함수

	if (cur_index == length_limit) {
		// 현재 길이가 원하는 길이(m)일 때, 출력해줌
		PrintResult(length_limit);
		return;
	}

	for (int i = start_index; i < num_limit; i++)
	{
		int current_num = numbers[i];		// numbers에서 하나씩 가져오면서 판단

		if (!is_used[i]) {
			if (using_num[cur_index] != current_num) {
				using_num[cur_index] = current_num;
				result[cur_index] = current_num;
				is_used[i] = true;
				FillArray(cur_index + 1, i, num_limit, length_limit);
				is_used[i] = false;
			}
		}
	}
	using_num[cur_index] = 0;
}

void Solution15664() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받는 부분
	int n, m;		// 1~8, n개의 자연수 중 m개를 고른 수열
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	// 배열을 정렬해준 후
	sort(numbers, numbers + n);

	// 답을 구함
	FillArray(0, 0, n, m);
}

int main(void) {
	Solution15664();
	return 0;
}