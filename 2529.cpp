#include <iostream>
using namespace std;

/*
각 자리에서 0~9 사이 하나씩 넣을 수 있음
하지만 중간에 부등호 기호가 맞지 않을 경우는 짜를 수 있음
이를 처리하는 ㅋ코드 추가
*/

char input_inequality_sign[9];	// 입력으로 들어온 부등호
int result_arr[10];				// 각 자리에 따라 숫자를 배치한 배열
bool is_used[10];				// i숫자가 사용되었는지 여부를 저장할 배열
long long max_value = 0;
long long min_value = 9999999999;

void GetAnswer(int cur_position, int k) {
	// 재귀적으로 cur_position자리에 들어올 값을 구하는 함수
	// cur_position = 이번에 구할 result_arr의 인덱스
	// k = 부등호 기호의 개수

	//답을 구할 수 없는 경우


	// 답을 구하는 경우
	if (cur_position > k) {
		// 모든 배열을 다 채웠을 때 result_arr의 0~k인덱스까지 숫자로 답을 구해 보고, min/max구하기
		long long result = 0;
		for (int j = 0; j < k; j++)
		{
			int cur_val = result_arr[k - 1 - j];
			result += cur_val * pow(10, j);
		}

		// max_value과 min_value채우기
		if (max_value < result) {
			max_value = result;
		}
		if (min_value > result) {
			min_value = result;
		}
	}

	// 아직 result_arr배열이 다 채워지지 못해서 계속 진행해야 하는 경우
	int prev_num = result_arr[cur_position - 1];
	if (input_inequality_sign[cur_position - 1] == '>') {
		for (int i = 0; i < prev_num; i++)
		{
			if (!is_used[i]) {
				result_arr[cur_position] = i;
				is_used[i] = true;
				GetAnswer(cur_position + 1, k);
			}
		}
	}
	else {
		for (int i = prev_num + 1; i < 10; i++)
		{
			if (!is_used[i]) {
				result_arr[cur_position] = i;
				is_used[i] = true;
				GetAnswer(cur_position + 1, k);
			}
		}
	}
}

void Solution2529() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받기
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> input_inequality_sign[i];
	}

	// 첫 번째 자리를 채워주고 재귀함수를 이용해 다른 자리도 채워주기
	for (int j = 0; j < 10; j++)
	{
		result_arr[0] = j;
		is_used[j] = true;
		GetAnswer(j, k);
	}

	// 출력하는 부분. 자릿수에 맞게 0도 넣어주기
	cout << max_value << "\n" << min_value;
}

int main(void) {
	Solution2529();
	return 0;
}