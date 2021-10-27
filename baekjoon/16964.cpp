#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[100001];		// 그래프 정보 저장
int order[100000];				// 방문 순서를 저장할 그래프

void Solution16964() {
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
	stack<int> s;
	int order_index = 0;
	int result = 1;

	if (order[order_index] != 1) {
		cout << "0\n";
		return;
	}
	s.push(order[order_index]);
	order_index++;

	while (!s.empty() && order_index < num_of_points) {
		int cur = s.top();

		bool find = false;
		for (int k = 0; k < graph[cur].size(); k++)
		{
			if (order[order_index] == graph[cur][k]) {
				s.push(graph[cur][k]);
				order_index++;
				find = true;
				break;
			}
		}

		if (!find) {
			s.pop();
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
	Solution16964();
	return 0;
}