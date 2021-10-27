#include <iostream>
#include <queue>
#include <string>
using namespace std;

int maze[100][100];						// 미로의 칸을 나타낼 배열
int is_visited[100][100];				// 미로에서 지난 칸 수를 저장해둘 배열
int width_of_maze, height_of_maze;		// 미로의 가로 세로 길이 (2~100)
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool explore_with_bfs(int x, int y) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	is_visited[x][y] = 1;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		int current_passway = is_visited[x][y];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int width_x = x + dx[i];
			int width_y = y + dy[i];
			if (0 <= width_x && width_x < width_of_maze && 0 <= width_y && width_y < height_of_maze) {
				if (maze[width_x][width_y] == 1 && is_visited[width_x][width_y] == 0) {
					q.push(make_pair(width_x, width_y));
					is_visited[width_x][width_y] = current_passway + 1;
				}
			}
		}
	}
	return true;
}

void Solution2178() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 값 받기
	cin >> width_of_maze >> height_of_maze;
	cin.ignore();

	for (int i = 0; i < width_of_maze; i++)
	{
		string input;
		getline(cin, input);

		for (int j = 0; j < input.size(); j++)
		{
			maze[i][j] = input.at(j) - 48;
		}
	}

	// bfs탐색을 하면서 이어진 칸들을 탐색하고, 목적지까지 최소의 칸수를 출력한다
	explore_with_bfs(0, 0);
	cout << is_visited[width_of_maze - 1][height_of_maze - 1] << "\n";
}

int main(void) {
	Solution2178();
	return 0;
}