#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
인접 리스트로 그래프를 구현하고, 지나다니면서 구분

*/

vector<int> graph[20001];			// 그래프의 간선의 정보를 저장할 배열
int group[20001];					// 그래프의 그룹을 저장할 배열 (0-안 지나감, 1-그룹1, 2-그룹2)

bool is_bipartite_graph_with_bfs(int start_point) {
	queue<int> q;		// 큐 생성
	q = queue<int>();

	// start_point는 그룹 1로 지정해주고 큐에 넣는다
	group[start_point] = 1;
	q.push(start_point);

	// 큐가 빌 때까지 해당 작업을 반복함
	while (!q.empty()) {
		// 큐에서 하나를 빼고 x_group에 해당 뺀 것의 그룹 넘버를 기록해줌
		int x = q.front();
		q.pop();
		int x_group = group[x];

		// 그와 연결되어 있는 모든 정점들을 살펴봄
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];

			if (group[y] == x_group) {
				// 만약 자신의 그룹 넘버와 같은 것이 있으면 이 그래프는 이분 그래프가 아닌거임.. false 리턴
				return false;
			}
			else if (group[y] == 0) {
				// 0일 경우에는 아직 방문하지 않은 그래프이니까 큐에 넣어주고, 그 정점의 그룹을 현재 그룹과 반대로 지정해줌
				if (x_group == 1) {
					group[y] = 2;
				}
				else {
					group[y] = 1;
				}
				q.push(y);
			}
			// 그룹 넘버가 서로 다를 경우에는 그냥 넘어감
		}
	}

	return true;
}

void Solution1707() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_test_cases;			// 테스트 케이스의 개수 (2~5)
	cin >> num_of_test_cases;

	int num_of_points;				// 정점의 개수 (1~20000)
	int num_of_relationship;		// 간선의 개수 (1~200000)
	for (int j = 0; j < num_of_test_cases; j++)
	{
		cin >> num_of_points >> num_of_relationship;

		// 그래프 초기화
		for (int i = 0; i <= 20000; i++)
		{
			group[i] = 0;
			graph[i].clear();
		}

		// 그래프 입력받기
		for (int i = 0; i < num_of_relationship; i++)
		{
			int to, from;
			cin >> to >> from;
			graph[to].push_back(from);
			graph[from].push_back(to);
		}

		// 정점 한개씩 찾아가며 연결되어있는 그래프인지 판별
		int status = 1;
		for (int m = 1; m <= num_of_points; m++)
		{
			if (group[m] == 0) {
				if (!is_bipartite_graph_with_bfs(m)) {
					status = 0;
					break;
				}
			}
		}

		if (status == 1) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}

int main(void) {
	Solution1707();
	return 0;
}
