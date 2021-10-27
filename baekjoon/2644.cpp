#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

*/

int result;							// 답으로 출력할, 두 사람의 촌수
int num_of_people;					// 주어진 사람의 수
vector<int> connections[101];		// 부모 자식 관계를 연결해줄 배열
int is_visited[101];				// 방문했을 때의 depth 저장

int Bfs(int start_number, int end_number) {
	queue<int> q;

	q.push(start_number);
	is_visited[start_number] = 0;
	while (!q.empty())
	{
		int current_number = q.front();
		q.pop();

		for (int j = 0; j < connections[current_number].size(); j++)
		{
			if (!is_visited[connections[current_number][j]]) {
				if (connections[current_number][j] == end_number) {
					return is_visited[current_number] + 1;
				}
				q.push(connections[current_number][j]);
				is_visited[connections[current_number][j]] = is_visited[current_number] + 1;
			}
		}
	}

	return -1;
}

void Solution2644() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 부모 자식 관계를 입력받기
	cin >> num_of_people;
	int num_of_connections, start_num, end_num;
	cin >> start_num >> end_num >> num_of_connections;
	for (int i = 0; i < num_of_connections; i++)
	{
		int parent, child;
		cin >> parent >> child;

		connections[parent].push_back(child);
		connections[child].push_back(parent);
	}

	// 2. 둘 중 입력받은 한 사람으로부터 시작해서 촌수 구해보기
	// 초기값은 -1이고, 만약 두 사람의 관계에 친척 관계가 없다면 그대로 -1을 출력한다
	result = Bfs(start_num, end_num);

	cout << result;
}

int main(void) {
	Solution2644();
	return 0;
}