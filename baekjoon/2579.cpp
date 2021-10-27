#include <iostream>
using namespace std;

int num_of_stairs;				// 계단의 개수
int point_of_stair[300];		// i번째 계단의 포인트
int max_point[300][2];			// i번째 계단을 j번째 연속으로 밟았을 때의 최대 포인트

void Solution2579() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받기
	cin >> num_of_stairs;
	for (int i = 0; i < num_of_stairs; i++)
	{
		cin >> point_of_stair[i];
	}

	// 계단 개수가 1일때와 2일때 출력
	if (num_of_stairs <= 2) {
		if (num_of_stairs == 1) {
			cout << point_of_stair[0];
		}
		else {
			cout << point_of_stair[0] + point_of_stair[1];
		}

		return;
	}

	// 초기값 입력
	max_point[0][0] = point_of_stair[0];
	max_point[0][1] = point_of_stair[0];
	max_point[1][0] = point_of_stair[1];
	max_point[1][1] = point_of_stair[0] + point_of_stair[1];

	// DP로 앞으로의 값 구하기
	for (int j = 2; j < num_of_stairs; j++)
	{
		max_point[j][0] = max(max_point[j - 2][0], max_point[j - 2][1]) + point_of_stair[j];
		max_point[j][1] = max_point[j - 1][0] + point_of_stair[j];
	}

	cout << max(max_point[num_of_stairs - 1][0], max_point[num_of_stairs - 1][1]);
}

int main(void) {
	Solution2579();
	return 0;
}