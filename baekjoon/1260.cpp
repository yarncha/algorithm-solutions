#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
여러 간선이 있을 수 있다는 조건과, dfs에서 정점의 숫자가 더 작은 것을 먼저 방문하라는 점에서
인접 행렬로 짜는 것이 좋을 것 같다는 생각이 들었음
*/

int graph[1001][1001];				// 간선을 나타낸 그래프
bool check[1001];					// i를 지나갔는지를 나타내는 배열

void dfs(int point) {
	check[point] = true;		// 내가 이 점을 지나갔다
	cout << point << " ";

	for (int i = 1; i < 1001; i++) {
		if (graph[point][i] == 1 && check[i] == false) {
			// 간선이 있고 && 방문한 적 없으면 방문
			dfs(i);
		}
	}
}

void bfs(int point) {
	queue<int> q;		// 큐 생성

	// point 방문
	check[point] = true;
	q.push(point);

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		// 다음 타겟을 큐에서 빼주고
		int target = q.front();
		q.pop();
		cout << target << " ";

		// target과 연결되어 있는 모든 정점들을 (방문하지 않은 점들만) 큐에 넣어줌
		for (int i = 1; i < 1001; i++) {
			if (graph[target][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

void Solution1260() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 입력받고 인접 행렬로 만들음
	int num_of_points, num_of_relations, start_point;		// 정점의 개수(1~1000), 간선의 개수(1~10000), 탐색을 시작할 정점의 번호
	cin >> num_of_points >> num_of_relations >> start_point;
	for (int i = 0; i < num_of_relations; i++)
	{
		int to, from;
		cin >> to >> from;
		graph[to][from] = 1;
		graph[from][to] = 1;
	}

	// 2. DFS 수행
	dfs(start_point);
	for (int j = 1; j < 1001; j++)
	{
		check[j] = 0;
	}
	cout << "\n";

	// 3. BFS 수행
	bfs(start_point);

	return;
}

int main(void) {
	Solution1260();
	return 0;
}