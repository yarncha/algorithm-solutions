#include <iostream>
using namespace std;

/*
문제가 길긴 한데 사실 "지금까지 배운 것을 종합해서, "부터 읽으면 됨..ㅋㅋ

input_signs가 주어지는데, 이는 result_array[i]부터 result_array[j]까지 더했을 때 값이 양수냐 음수냐 0이냐를 준 것
이 조건에 맞는 result_array를 구하면 된다

역시나 중간에 조건 안 맞는 경우는 잘라낼 수 있다
*/

char input_signs[10][10];		// 입력받은 기호들을 저장할 배열
int sums[10][10];				// i번째 수부터 j번째 수까지의 합을 계산한 값들을 저장할 배열

bool IsValidSign(int cur_index) {
	// 검증할 값을 cur_index에 넣고 합을 구해보았을 때 input_sign[0][cur_index], input_sign[1][cur_index] ... input_sign[cur_index-1][cur_index] 기호가 맞는지 확인하는 함수
	for (int i = 0; i < cur_index; i++)
	{
		int sum = sums[i][cur_index - 1] + sums[cur_index][cur_index];

		if (sum < 0 && input_signs[i][cur_index] != '-') {
			return false;
		}
		else if (sum > 0 && input_signs[i][cur_index] != '+') {
			return false;
		}
		else if (sum == 0 && input_signs[i][cur_index] != '0') {
			return false;
		}

		sums[i][cur_index] = sum;
	}
	return true;
}

bool Solve(int cur_index, int num_of_inputs) {
	// 재귀적으로 문제를 해결하는 함수
	// cur_index = 현재 채워넣을 array

	if (cur_index == num_of_inputs) {
		// 배열을 채워서 답이 나왔을 경우임
		return true;
	}

	// input_signs[cur_index][cur_index] 기호가 어떤 기호이냐에 따라서 sums[cur_index][cur_index]에 들어갈 숫자 범위를 정함
	if (input_signs[cur_index][cur_index] == '-') {
		for (int i = -1; i > -11; i--)
		{
			sums[cur_index][cur_index] = i;
			if (IsValidSign(cur_index)) {
				if (Solve(cur_index + 1, num_of_inputs)) {
					return true;
				}
			}
		}
	}
	else if (input_signs[cur_index][cur_index] == '+') {
		for (int i = 1; i < 11; i++)
		{
			sums[cur_index][cur_index] = i;
			if (IsValidSign(cur_index)) {
				if (Solve(cur_index + 1, num_of_inputs)) {
					return true;
				}
			}
		}
	}
	else {
		sums[cur_index][cur_index] = 0;
		if (IsValidSign(cur_index)) {
			if (Solve(cur_index + 1, num_of_inputs)) {
				return true;
			}
		}
	}

	return false;
}

void Solution1248() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력받는 부분
	int num_of_inputs;			// 입력받을 수열의 크기 (1~10)
	cin >> num_of_inputs;

	for (int i = 0; i < num_of_inputs; i++)
	{
		for (int j = i; j < num_of_inputs; j++)
		{
			cin >> input_signs[i][j];
		}
	}

	// 계산하는 부분
	Solve(0, num_of_inputs);

	// 출력하는 부분
	for (int k = 0; k < num_of_inputs; k++)
	{
		cout << sums[k][k] << " ";
	}
}

int main(void) {
	Solution1248();
	return 0;
}