#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Link
{
	int dest;
	int weight;
};

vector<Link> trees[100001];			// i번째 정점에서 다른 정점(dest)까지의 거리(value)를 저장할 배열
bool is_visited[100001];
int max_distance;
int max_distance_node;

void dfs(int root, int weight) {
	int current_weight_sum = weight;
	is_visited[root] = true;

	for (int i = 0; i < trees[root].size(); i++)
	{
		if (is_visited[trees[root][i].dest] == false) {
			dfs(trees[root][i].dest, current_weight_sum + trees[root][i].weight);
		}
	}

	if (current_weight_sum > max_distance) {
		max_distance = current_weight_sum;
		max_distance_node = root;
	}

	return;
}

void Solution1167() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_point;			// 트리의 정점의 개수 2~100000
	cin >> num_of_point;

	// 정점 번호에 대한 연결된 간선의 정보를 저장하기 위한 부분
	for (int i = 0; i < num_of_point; i++)
	{
		int node;						// 정점 번호
		cin >> node;

		int connected_node;				// 연결된 간선의 정점 번호
		cin >> connected_node;
		while (connected_node != -1)		// -1이 아닐 경우는 정점이 있는 것이므로 거리를 입력받음
		{
			int connected_weight;
			cin >> connected_weight;

			Link temp;
			temp.dest = connected_node;
			temp.weight = connected_weight;

			trees[node].push_back(temp);
			cin >> connected_node;
		}
	}

	// 첫 번째 탐색. 아무 정점이나 잡아서 제일 먼 길이를 측정함
	dfs(1, 0);

	// 두 번째 탐색. 제일 먼 길이를 측정했을 때 나온 정점에서 또 가장 먼 길이를 측정하는데 이게 답임
	max_distance = 0;
	for (int j = 1; j <= num_of_point; j++)
	{
		is_visited[j] = false;
	}
	dfs(max_distance_node, 0);
	int diameter = max_distance;

	cout << diameter;
}

int main(void) {
	Solution1167();
	return 0;
}