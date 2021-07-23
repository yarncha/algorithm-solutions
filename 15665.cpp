#include <iostream>
#include <algorithm>
using namespace std;

int numbers[7];			// 입력을 주어진 수를 저장할 배열
int result[7];			// 결과로 출력할 수를 저장할 배열
int using_num[8];		// 같은 숫자 재사용을 막기 위한 배열

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
	// result 배열에 알맞는 값을 집어넣는 함수

	if (cur_index == length_limit) {
		// 현재 길이가 원하는 길이(m)일 때, 출력해줌
		PrintResult(length_limit);
		return;
	}

	for (int i = 0; i < num_limit; i++)
	{
		int current_num = numbers[i];		// numbers에서 하나씩 가져오면서 판단

		if (using_num[cur_index] != current_num) {
			using_num[cur_index] = current_num;
			result[cur_index] = current_num;
			FillArray(cur_index + 1, num_limit, length_limit);
		}
	}
	using_num[cur_index] = 0;
}

void Solution15665() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받는 부분
	int n, m;		// 1~7, n개의 자연수 중 m개를 고른 수열
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	// 배열을 정렬해준 후
	sort(numbers, numbers + n);

	// 답을 구함
	FillArray(0, n, m);
}

int main(void) {
	Solution15665();
	return 0;
}