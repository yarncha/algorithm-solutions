#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
DFS BFS모두로 풀 수 있음
BFS로 풀어봄
*/

vector<int> nodes[100001];
int parent[100001];

void GetParent(int root) {
	queue<int> q;
	q.push(root);
	parent[root] = -1;

	while (!q.empty())
	{
		int cur_node = q.front();
		q.pop();

		for (int k = 0; k < nodes[cur_node].size(); k++)
		{
			if (parent[nodes[cur_node][k]] == 0) {
				q.push(nodes[cur_node][k]);
				parent[nodes[cur_node][k]] = cur_node;
			}
		}
	}
}

void Solution11725() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_nodes;			// 노드의 개수(2~100000)
	cin >> num_of_nodes;

	for (int i = 0; i < num_of_nodes - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	// 벡터를 통해 노드를 저장했으면, 루트가 1이라고 주어져 있으니 루트를 기준으로 부모 노드 구하기
	GetParent(1);

	for (int j = 2; j <= num_of_nodes; j++)
	{
		cout << parent[j] << "\n";
	}
}

int main(void) {
	Solution11725();
	return 0;
}