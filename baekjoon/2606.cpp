#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

*/

int result;							// 구할 답인, 웜 바이러스에 걸린 컴퓨터의 수
int num_of_computers;				// 컴퓨터의 개수
int num_of_connections;				// 연결된 쌍의 개수
vector<int> connections[101];		// i번째 컴퓨터와 연결되어있는 컴퓨터를 저장할 배열
bool is_visited[101];				// i번째 컴퓨터를 방문했는지 여부를 저장할 배열

void Bfs(int computer_number) {
	queue<int> q;

	q.push(computer_number);
	is_visited[computer_number] = true;
	while (!q.empty())
	{
		int current_number = q.front();
		q.pop();

		for (int j = 0; j < connections[current_number].size(); j++)
		{
			if (!is_visited[connections[current_number][j]]) {
				is_visited[connections[current_number][j]] = true;
				q.push(connections[current_number][j]);
				result++;
			}
		}
	}
}

void Solution2606() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 연결을 입력 받기
	cin >> num_of_computers >> num_of_connections;
	for (int i = 0; i < num_of_connections; i++)
	{
		int first_computer, second_computer;
		cin >> first_computer >> second_computer;

		connections[first_computer].push_back(second_computer);
		connections[second_computer].push_back(first_computer);
	}

	// 2. BFS를 통해 탐색하며 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 웜 바이러스에 걸리게 될 최종 컴퓨터 대수 구하기
	result = 0;
	Bfs(1);

	cout << result;
}

int main(void) {
	Solution2606();
	return 0;
}