#include <iostream>
#include <algorithm>
using namespace std;

/*
이번에는 수가 1~n까지 순서대로가 아니라 직접 주어짐
+ 중복 허용 + 비내림차순
*/

int numbers[8];			// 입력된 수 저장
int result[8];			// 결과로 출력할 배열 저장
bool is_used[9];		// numbers에서 i번째에 있는 수를 사용했는지 여부

void PrintResult(int length_of_result) {
	// 만들어진 result를 length_of_result에 맞추어 출력해주는 함수
	for (int i = 0; i < length_of_result; i++)
	{
		cout << result[i] << " ";
	}

	cout << "\n";

	return;
}

void FillArray(int cur_index, int num_limit, int length_limit, int start_index) {
	// result 배열에 알맞는 값을 집어넣는 함수
	if (cur_index == length_limit) {
		// 현재 길이가 원하는 길이(m)일 때, 출력해줌
		PrintResult(length_limit);
		return;
	}

	for (int i = start_index; i < num_limit; i++)
	{
		int current_num = numbers[i];		// numbers에서 하나씩 가져오면서 판단
		result[cur_index] = current_num;
		FillArray(cur_index + 1, num_limit, length_limit, i);
	}
}

void Solution15656() {
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
	FillArray(0, n, m, 0);
}

int main(void) {
	Solution15656();
	return 0;
}