#include <iostream>
using namespace std;

int day_required[16];
int value[16];
int max_earnings;

void Solve(int cur_day, int dest_day, int earnings) {
	if (cur_day > dest_day) {
		// 조건에 맞지 않을 경우에는 리턴
		return;
	}

	if (cur_day == dest_day) {
		// 정해진 날짜가 되면, 지금까지 번 돈(earnings)이랑 최고 금액이랑 비교해봄
		if (max_earnings < earnings) {
			max_earnings = earnings;
		}
		return;
	}

	// 다음 경우 호출
	Solve(cur_day + 1, dest_day, earnings);			// 해당 날짜에 있는 상담을 하지 않고 넘어갈 경우
	Solve(cur_day + day_required[cur_day], dest_day, earnings + value[cur_day]);		// 해당 날짜에 상담을 하고 넘어갈 경우

	return;
}

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

	Solve(0, last_day, 0);
	cout << max_earnings << "\n";
}

int main(void) {
	Solution14501();
	return 0;
}