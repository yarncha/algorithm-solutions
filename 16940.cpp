#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
알고리즘은 맞게 짰는데, 1로 반드시 시작해야한다는 조건이 있어서 틀렸음..
문제를 읽어서는 1로 시작해야 하는 이유를 모르겠긴한데... 아무튼 넣으니 통과
*/

vector<int> graph[100001];		// 그래프 정보 저장
int order[100000];				// 방문 순서를 저장할 그래프
int parent[100001];				// 이전 정점의 번호를 저장할 그래프

void Solution16940() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_points;		// 정점의 수 2~100000
	cin >> num_of_points;
	for (int i = 0; i < num_of_points - 1; i++)
	{
		int to, from;
		cin >> to >> from;

		graph[to].push_back(from);
		graph[from].push_back(to);
	}

	for (int j = 0; j < num_of_points; j++)
	{
		cin >> order[j];
	}

	// 계산
	queue<int> q;
	int order_index = 0;
	int result = 1;

	if (order[order_index] != 1) {
		cout << "0\n";
		return;
	}
	q.push(order[order_index]);
	parent[order[order_index]] = -1;
	order_index++;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int num_of_connected_points = 0;
		for (int k = 0; k < graph[cur].size(); k++)
		{
			int connect_point = graph[cur][k];
			if (parent[connect_point] == 0) {
				parent[connect_point] = cur;
				num_of_connected_points++;
			}
		}

		for (int m = 0; m < num_of_connected_points; m++)
		{
			if (parent[order[order_index]] != cur) {
				result = 0;
				break;
			}
			else {
				q.push(order[order_index]);
			}
			order_index++;
		}

		if (result == 0) {
			cout << "0\n";
			return;
		}
	}

	if (order_index != num_of_points) {
		cout << "0\n";
	}
	else {
		cout << "1\n";
	}
	return;
}

int main(void) {
	Solution16940();
	return 0;
}
