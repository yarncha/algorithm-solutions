#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

/*
연결 요소의 개수를 구할 때와 비슷, 2667번 문제의 변형
*/

int width_of_map;						// 지도의 가로 사이즈 (1~50)
int height_of_map;						// 지도의 세로 사이즈 (1~50)
int map[50][50];						// 지도에 땅/바다 여부 저장
bool is_visited[50][50];				// 해당 포인트를 방문했는지 여부
int total_num_of_divisions;				// 총 단지의 수를 저장할 변수

bool map_with_bfs(int x_point, int y_point) {
	// map을 bfs로 탐색하면서 연결되어 있는 섬들을 다 visit하는 함수
	queue<pair<int, int>> q;

	// 첫 입력으로 받은 점 x_point, y_point를 먼저 visit한 뒤 queue에 넣어줌
	q.push(make_pair(x_point, y_point));
	is_visited[x_point][y_point] = true;

	// 큐가 빌 때까지 탐색
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 상하좌우와 대각선 점까지 확인하면서 이 점이 유효한 점인지 && 땅인지(1) && 방문하지 않은 점인지를 파악해 queue에 넣음
		if (y + 1 < height_of_map && map[x][y + 1] == 1 && !is_visited[x][y + 1]) {
			q.push(make_pair(x, y + 1));
			is_visited[x][y + 1] = true;
		}
		if (y - 1 >= 0 && map[x][y - 1] == 1 && !is_visited[x][y - 1]) {
			q.push(make_pair(x, y - 1));
			is_visited[x][y - 1] = true;
		}
		if (x + 1 < width_of_map && map[x + 1][y] == 1 && !is_visited[x + 1][y]) {
			q.push(make_pair(x + 1, y));
			is_visited[x + 1][y] = true;
		}
		if (x - 1 >= 0 && map[x - 1][y] == 1 && !is_visited[x - 1][y]) {
			q.push(make_pair(x - 1, y));
			is_visited[x - 1][y] = true;
		}

		//추가된 대각선 조건
		if (x + 1 < width_of_map && y + 1 < height_of_map && map[x + 1][y + 1] == 1 && !is_visited[x + 1][y + 1]) {
			q.push(make_pair(x + 1, y + 1));
			is_visited[x + 1][y + 1] = true;
		}
		if (x + 1 < width_of_map && y - 1 >= 0 && map[x + 1][y - 1] == 1 && !is_visited[x + 1][y - 1]) {
			q.push(make_pair(x + 1, y - 1));
			is_visited[x + 1][y - 1] = true;
		}
		if (x - 1 >= 0 && y + 1 < height_of_map && map[x - 1][y + 1] == 1 && !is_visited[x - 1][y + 1]) {
			q.push(make_pair(x - 1, y + 1));
			is_visited[x - 1][y + 1] = true;
		}
		if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == 1 && !is_visited[x - 1][y - 1]) {
			q.push(make_pair(x - 1, y - 1));
			is_visited[x - 1][y - 1] = true;
		}
	}

	return true;
}

void Solution4963() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true)
	{
		// 지도의 가로세로 값을 받은 뒤 땅/바다 여부 입력받음
		cin >> height_of_map >> width_of_map;
		if (width_of_map == 0 && height_of_map == 0) {
			break;
		}

		// 초기화 과정 필요하면 초기화해주는 부분
		total_num_of_divisions = 0;
		for (int init_x = 0; init_x < width_of_map; init_x++)
		{
			for (int init_y = 0; init_y < height_of_map; init_y++)
			{
				is_visited[init_x][init_y] = false;
			}
		}

		for (int i = 0; i < width_of_map; i++)
		{
			for (int j = 0; j < height_of_map; j++)
			{
				cin >> map[i][j];
			}
		}

		// map의 점들을 하나씩 탐색하며 이어져 있는 연결 요소의 개수를 파악함
		for (int x = 0; x < width_of_map; x++)
		{
			for (int y = 0; y < height_of_map; y++)
			{
				if (map[x][y] == 1 && !is_visited[x][y]) {
					// map에 땅이 있으면서(1), 이 점을 방문하지 않았을 때
					map_with_bfs(x, y);				// BFS탐색 수행
					total_num_of_divisions++;		// 연결 요소 하나 찾은 것
				}
			}
		}

		// 해당 테스트 케이스의 연결 요소 출력
		cout << total_num_of_divisions << "\n";
	}

}

int main(void) {
	Solution4963();
	return 0;
}
