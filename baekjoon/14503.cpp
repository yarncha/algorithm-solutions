#include <iostream>
using namespace std;

int num_of_cleaned_area = 0;
int width, height;
int area[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void Cleaning(int current_x, int current_y, int current_direction) {
	if (area[current_x][current_y] == 0) {
		// 현재 칸이 비어 있는 칸일 경우 현재 칸을 청소한다(-1)
		area[current_x][current_y] = -1;
		num_of_cleaned_area++;
	}

	for (int i = 1; i <= 4; i++)
	{
		// 왼쪽부터 반시계 방향으로 탐색하며 빈 공간이 있으면 진입 후 청소한다
		int next_direction = ((current_direction + 4) - i) % 4;
		int next_x = current_x + dx[next_direction];
		int next_y = current_y + dy[next_direction];

		if (area[next_x][next_y] == 0) {
			Cleaning(next_x, next_y, next_direction);

			return;
		}
	}

	// 한바퀴 돌았지만 갈 곳이 없을 경우에는 뒤가 벽인지 보고 후진할지 말지 결정한다.
	int back_direction = ((current_direction + 4) - 2) % 4;
	int next_x = current_x + dx[back_direction];
	int next_y = current_y + dy[back_direction];
	if (area[next_x][next_y] == 1) {
		// 뒤에가 벽일 경우 종료
		return;
	}
	else {
		Cleaning(next_x, next_y, current_direction);
	}
}

void Solution14503() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> height >> width;
	int current_x, current_y, current_direction;
	cin >> current_x >> current_y >> current_direction;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> area[i][j];
		}
	}

	Cleaning(current_x, current_y, current_direction);
	cout << num_of_cleaned_area << "\n";

	return;
}

int main(void) {
	Solution14503();
	return 0;
}