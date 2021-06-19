#include <iostream>
using namespace std;

/*
같은 간선은 한 번만 주어지므로 인접 리스트로 풀어도 되는데
인접 행렬 연습하려고 인접 행렬, dfs방법으로 풀었음
*/

int graph[1001][1001];				// 간선을 나타낸 그래프
bool check[1001];					// i를 지나갔는지를 나타내는 배열

void dfs(int point) {
	check[point] = true;		// 내가 이 점을 지나갔다

	for (int i = 1; i < 1001; i++) {
		if (graph[point][i] == 1 && check[i] == false) {
			// 간선이 있고 && 방문한 적 없으면 방문
			dfs(i);
		}
	}
}
void Solution11724() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_connected_element = 0;		// 연결 요소의 개수

	// 1. 입력받고 인접 행렬로 만들음
	int num_of_points, num_of_relations, start_point;		// 정점의 개수(1~1000), 간선의 개수(0~500000), 탐색을 시작할 정점의 번호
	cin >> num_of_points >> num_of_relations;
	for (int i = 0; i < num_of_relations; i++)
	{
		int to, from;
		cin >> to >> from;
		graph[to][from] = 1;
		graph[from][to] = 1;
	}

	for (int j = 1; j <= num_of_points; j++)
	{
		if (check[j] == false) {
			// 아직 해당 정점을 체크하지 않은 경우, 이 정점을 체크하고 dfs검사를 하면
			// 해당 정점에 대한 연결 요소는 전부 체크한 것
			dfs(j);
			num_of_connected_element++;
		}
	}

	cout << num_of_connected_element << "\n";
}

int main(void) {
	Solution11724();
	return 0;
}
