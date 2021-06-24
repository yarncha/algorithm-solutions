#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
내가 생각한 일반적인 bfs로 하니까 시간 초과 발생
기존 생각한 방법 -> 그냥 1인거 하나하나 찾아가면서 그 주변 다 물들이기
					이렇게 하면 문제가, 이미 탐색한것들도 고쳐줘야 하는 상황 발생 (이미 탐색했는데 또 탐색)
변경한 방법 -> 1인것들을 queue에 넣어주고 동시에 탐색하기
				기존 생각한 방법에서 이미 탐색한 것들을 고쳐줘야 하는 상황 발생x(이미 지나간 것들은 안 보니까)
*/

int tomatos[1000][1000];					// 박스에서 토마토가 있는 칸을 나타낼 배열
int day_to_ripe[1000][1000];					// 박스에서 토마토의 익은 칸을 나타낼 배열
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Solution7576() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	queue<pair<int, int>> q;
	bool not_all_ripen;
	int width, height;		// 박스의 가로 세로 길이 (2~1000)
	int answer;				// 모든 열매가 익기위한 날짜

	// 입력 값 받기
	cin >> height >> width;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int current_passway = tomatos[x][y];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int width_x = x + dx[i];
			int height_y = y + dy[i];
			if (0 <= width_x && width_x < width && 0 <= height_y && height_y < height) {
				if (tomatos[width_x][height_y] == 0) {
					not_all_ripen = true;
					q.push(make_pair(width_x, height_y));
					tomatos[width_x][height_y] = current_passway + 1;
				}
			}
		}
	}

	// 익힐 게 없었으면 0 출력
	if (!not_all_ripen) {
		cout << "0\n";
		return;
	}

	// BFS 탐색이 완료된 뒤에도 안 익은 토마토가 있으면 모두 익지는 못하는 상황이므로 -1출력
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int ripen_day = tomatos[i][j];

			if (ripen_day == 0) {
				cout << "-1\n";
				return;
			}

			// 익은 토마토의 최대 날짜를 구함
			if (ripen_day > answer) {
				answer = ripen_day;
			}
		}
	}

	cout << answer - 1 << "\n";
}

int main(void) {
	Solution7576();
	return 0;
}
