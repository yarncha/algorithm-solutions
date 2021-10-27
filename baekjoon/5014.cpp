#include <iostream>
#include <queue>
using namespace std;

int num_of_floors, floor_current, floor_startlink, up_number, down_number;
int min_steps[1000001];		// i층으로 가기 위한 최소한의 버튼 클릭 수

int Calculate() {
	queue<int> q;

	q.push(floor_current);
	min_steps[floor_current] = 0;
	while (!q.empty())
	{
		int current = q.front();
		if (current == floor_startlink) {
			return min_steps[floor_startlink];
		}
		q.pop();

		int current_down = current - down_number;
		if (current_down >= 1 && current_down <= num_of_floors && min_steps[current_down] == -1) {
			min_steps[current_down] = min_steps[current] + 1;
			q.push(current_down);
		}
		int current_up = current + up_number;
		if (current_up <= num_of_floors && current_up >= 1 && min_steps[current_up] == -1) {
			min_steps[current_up] = min_steps[current] + 1;
			q.push(current_up);
		}
	}

	return -1;
}

void Solution5014() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받기
	cin >> num_of_floors >> floor_current >> floor_startlink >> up_number >> down_number;
	for (int i = 1; i <= num_of_floors; i++)
	{
		min_steps[i] = -1;
	}

	// 계산
	int result = Calculate();

	// 출력
	if (result == -1) {
		cout << "use the stairs";
	}
	else {
		cout << result;
	}
}

int main(void) {
	Solution5014();
	return 0;
}