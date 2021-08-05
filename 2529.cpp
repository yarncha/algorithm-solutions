#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
각 자리에 0~9 사이 숫자를 하나씩 넣을 수 있음 이것도 그냥 재귀로 짜면 되는데 중간에 부등호 기호가 맞지 않을 경우는 제외할 수 있으므로 이를 제외하는 방식으로 짬
*/

char input_inequality_sign[9];	// 입력으로 들어온 부등호
bool is_used[10];				// i숫자가 사용되었는지 여부를 저장할 배열
vector<string> answers;

void GetAnswer(string value, int cur_position, int k) {
	// 재귀적으로 cur_position자리에 들어올 값을 구하는 함수
	// value = 만들고있는 string 값
	// cur_position = 이번에 구할(채워 넣어야 할) result_arr의 인덱스
	// k = 부등호 기호의 개수

	//답을 구할 수 없는 경우는 아래 진행해야 하는 조건에서 제거했음

	// 1. 답을 구하는 경우
	if (cur_position > k) {
		// answers벡터에 가능한 경우들을 다 넣기
		answers.push_back(value);
		return;
	}

	// 2. 아직 result_arr배열이 다 채워지지 못해서 계속 진행해야 하는 경우
	int prev_num = value[cur_position - 1] - 48;
	if (input_inequality_sign[cur_position - 1] == '>') {
		for (int i = 0; i < prev_num; i++)
		{
			if (!is_used[i]) {
				value[cur_position] = i + 48;
				is_used[i] = true;
				GetAnswer(value, cur_position + 1, k);
				is_used[i] = false;
			}
		}
	}
	else {
		for (int i = prev_num + 1; i < 10; i++)
		{
			if (!is_used[i]) {
				value[cur_position] = i + 48;
				is_used[i] = true;
				GetAnswer(value, cur_position + 1, k);
				is_used[i] = false;
			}
		}
	}
}

void Solution2529() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받기
	int k;
	cin >> k;
	string value = "";
	for (int i = 0; i < k; i++)
	{
		cin >> input_inequality_sign[i];
		value += "0";
	}
	value += "0";

	// 첫 번째 자리를 채워주고 재귀함수를 이용해 다른 자리도 채워주기
	for (int j = 0; j < 10; j++)
	{
		value[0] = j + 48;
		is_used[j] = true;
		GetAnswer(value, 1, k);
		is_used[j] = false;
	}

	// answer배열에서 최대값 최소값 찾기
	string min_result = answers[0];
	string max_result = answers[0];
	for (int m = 1; m < answers.size(); m++)
	{
		if (answers[m] < min_result) {
			min_result = answers[m];
		}
		else if (answers[m] > max_result) {
			max_result = answers[m];
		}
	}

	cout << max_result << "\n";
	cout << min_result << "\n";
}

int main(void) {
	Solution2529();
	return 0;
}