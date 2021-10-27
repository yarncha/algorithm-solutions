#include <iostream>
using namespace std;

/*
DP로 풀 수 있을 것 같아서 DP로 풀어 보았음
*/

int day_required[16];
int value[16];
int earned_values[16];

void Solution14501() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력받기
	int last_day;				// 퇴사를 하기 전 마지막 날(1~15)
	cin >> last_day;

	for (int i = 0; i < last_day; i++)
	{
		cin >> day_required[i];
		cin >> value[i];
	}

	// 끝에서부터 계산
	int max_value = 0;
	for (int j = last_day - 1; j >= 0; j--)
	{
		if (day_required[j] + j <= last_day) {
			earned_values[j] = earned_values[day_required[j] + j] + value[j];
		}
		if (earned_values[j + 1] > earned_values[j]) {
			earned_values[j] = earned_values[j + 1];
		}

		if (max_value < earned_values[j]) {
			max_value = earned_values[j];
		}
	}

	cout << max_value << "\n";
}

int main(void) {
	Solution14501();
	return 0;
}