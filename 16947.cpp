#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
N개의 정점과 N개의 간선이 주어지고 안 이어진 점이 없다면, 사이클이 하나가 꼭 존재한다
이미 방문한 정점을 또 방문하면 스택에 사이클이 존재함.
이때 이 사이클을 저장해 주어야함 어떤 점들이 있는지
거리는 BFS이용
*/

vector<int> map[3001];
bool is_visited[3001];
int dist_from_cycle[3001];			// i번 역과 순환선 사이의 거리를 측정할 것
vector<int> cycle;			// 사이클을 여기에 넣어줄 것
int num_of_stops;			// 역의 개수

int dfs(int prev_point, int current_point) {
	is_visited[current_point] = true;

	for (int i = 0; i < map[current_point].size(); i++)
	{
		if (!is_visited[map[current_point][i]]) {
			// 방문하지 않았으면 dfs로 방문해주기
			int temp = dfs(current_point, map[current_point][i]);
			if (temp == current_point) {
				dist_from_cycle[current_point] = 1;
				cycle.push_back(current_point);
				break;
			}
			else if (temp > -1) {
				dist_from_cycle[current_point] = 1;
				cycle.push_back(current_point);
				return temp;
			}
		}
		else if (is_visited[map[current_point][i]] && map[current_point][i] != prev_point) {
			// 바로 전에 방문한 점이 아니면서 이전에 방문한 점에 들어왔다?
			// 이 점이 사이클의 시작임
			dist_from_cycle[current_point] = 1;
			cycle.push_back(current_point);
			return map[current_point][i];
		}

	}
	return -1;
}

void calculate_distance_bfs(int cycle_index) {
	int current_cycle = cycle[cycle_index];
	queue<int> q;

	q.push(current_cycle);

	while (!q.empty())
	{
		current_cycle = q.front();
		q.pop();

		for (int i = 0; i < map[current_cycle].size(); i++)
		{
			if (dist_from_cycle[map[current_cycle][i]] == 0) {
				dist_from_cycle[map[current_cycle][i]] = dist_from_cycle[current_cycle] + 1;
				q.push(map[current_cycle][i]);
			}
		}
	}
}

void Solution16947() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 값 입력받기
	cin >> num_of_stops;
	for (int i = 0; i < num_of_stops; i++)
	{
		int to, from;
		cin >> to >> from;

		map[to].push_back(from);
		map[from].push_back(to);
	}


	//사이클 탐색
	dfs(1, 1);


	// 구한 사이클 정점을 통해 역의 거리 탐색
	for (int k = 0; k < cycle.size(); k++)
	{
		calculate_distance_bfs(k);
	}

	// 출력
	for (int j = 1; j <= num_of_stops; j++)
	{
		cout << dist_from_cycle[j] - 1 << " ";
	}

}

int main(void) {
	Solution16947();
	return 0;
}
