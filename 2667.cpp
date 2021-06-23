#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

/*
연결 요소의 개수를 구할 때와 비슷,

문제 조건 중 정렬을 까먹고 안 해줘서 몇번 틀렸다... 아쉬움
꼼꼼히 문제 읽자
*/

int map[25][25];						// 정사각형 지도 저장
bool is_visited[25][25];				// 해당 포인트를 방문했는지 여부
int size_of_map;						// 지도의 사이즈 (5~25)
int total_num_of_divisions;			// 총 단지의 수를 저장할 변수
int num_of_houses_in_division[700];		// i번째 단지 안의 집의 개수

bool map_with_bfs(int x_point, int y_point) {
	// 초기화 진행
	queue<pair<int, int>> q;

	q.push(make_pair(x_point, y_point));
	is_visited[x_point][y_point] = true;
	num_of_houses_in_division[total_num_of_divisions]++;

	while (!q.empty())
	{
		pair<int, int> current_point = q.front();
		q.pop();

		if (current_point.second + 1 < size_of_map && map[current_point.first][current_point.second + 1] == 1 && !is_visited[current_point.first][current_point.second + 1]) {
			q.push(make_pair(current_point.first, current_point.second + 1));
			is_visited[current_point.first][current_point.second + 1] = true;
			num_of_houses_in_division[total_num_of_divisions]++;
		}
		if (current_point.second - 1 >= 0 && map[current_point.first][current_point.second - 1] == 1 && !is_visited[current_point.first][current_point.second - 1]) {
			q.push(make_pair(current_point.first, current_point.second - 1));
			is_visited[current_point.first][current_point.second - 1] = true;
			num_of_houses_in_division[total_num_of_divisions]++;
		}
		if (current_point.first + 1 < size_of_map && map[current_point.first + 1][current_point.second] == 1 && !is_visited[current_point.first + 1][current_point.second]) {
			q.push(make_pair(current_point.first + 1, current_point.second));
			is_visited[current_point.first + 1][current_point.second] = true;
			num_of_houses_in_division[total_num_of_divisions]++;
		}
		if (current_point.first - 1 >= 0 && map[current_point.first - 1][current_point.second] == 1 && !is_visited[current_point.first - 1][current_point.second]) {
			q.push(make_pair(current_point.first - 1, current_point.second));
			is_visited[current_point.first - 1][current_point.second] = true;
			num_of_houses_in_division[total_num_of_divisions]++;
		}
	}

	return true;
}

void Solution2667() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 값 입력받음
	cin >> size_of_map;
	cin.ignore();
	for (int i = 0; i < size_of_map; i++)
	{
		string input;
		getline(cin, input);
		for (int k = 0; k < input.size(); k++)
		{
			map[i][k] = input.at(k) - 48;
		}
	}

	for (int x = 0; x < size_of_map; x++)
	{
		for (int y = 0; y < size_of_map; y++)
		{
			if (map[x][y] == 1 && !is_visited[x][y]) {
				// map에 집이 있으면서(1), 이 점을 방문하지 않았을 때
				map_with_bfs(x, y);
				total_num_of_divisions++;
			}
		}
	}

	cout << total_num_of_divisions << "\n";
	sort(num_of_houses_in_division, num_of_houses_in_division + total_num_of_divisions);
	for (int z = 0; z < total_num_of_divisions; z++)
	{
		cout << num_of_houses_in_division[z] << "\n";
	}
}

int main(void) {
	Solution2667();
	return 0;
}
