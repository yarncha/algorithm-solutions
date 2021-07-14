#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
비슷한 문제인 1167. 트리의 지름에서는 DFS를 이용한 탐색을 2번 하는 것으로 풀었는데, 이번 문제에서는 포스트오더를 이용하여 풀어 보았음
*/

struct Link
{
	int dest;
	int weight;
};

vector<Link> trees[10001];			// i번째 정점에서 다른 정점(dest)까지의 거리(value)를 저장할 배열
int height[10001];					// i번째 정점에서 가장 긴 리프노드까지의 거리
int diameter[10001];				// i번째 정점에서 해당 점을 지나는 지름
int max_diameter;					// 해당 입력된 트리에서의 지름

void CalculateHeightDiameter(int root) {
	int height_first = 0;			// 자식 노드를 루트로 하는 트리에서 가장 긴 높이 + 가중치
	int height_second = 0;			// 자식 노드를 루트로 하는 트리에서 두 번째로 긴 높이 + 가중치

	// 먼저 모든 자식 노드들을 탐색하면서 height와 diameter를 알아낸다
	for (int i = 0; i < trees[root].size(); i++)
	{
		CalculateHeightDiameter(trees[root][i].dest);

		// 탐색하면서 가장 긴 높이와 두 번째로 긴 높이를 구해둠
		int child_height = height[trees[root][i].dest] + trees[root][i].weight;
		if (child_height > height_second) {
			if (child_height > height_first) {
				height_second = height_first;
				height_first = child_height;
			}
			else {
				height_second = child_height;
			}
		}
	}

	// 현재 root에서 height와 diameter를 구한다.
	height[root] = height_first;						// root의 height는 가장 긴 높이+가중치이고
	diameter[root] = height_first + height_second;		// root를 지나는 diameter는 가장 긴 높이(+가중치) + 다음으로 긴 높이(+가중치)이다.

	// 또한 diameter를 구할 때에는 어디서 가장 큰 값이 나올 지 모르므로, root의 diameter만 살피는 것이 아닌 자식 노드들에서 모두 diameter들을 비교하면서 가장 큰 값을 찾도록 하였다.
	if (diameter[root] > max_diameter) {
		max_diameter = diameter[root];
	}

	return;
}

void Solution1967() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_nodes;			// 트리의 노드의 개수 1~10000
	cin >> num_of_nodes;

	// 정점 번호에 대한 연결된 간선의 정보를 저장하기 위한 부분
	for (int i = 0; i < num_of_nodes - 1; i++)
	{
		// 간 간선에 대한 정보가 들어옴
		int node, connected_node, connected_weight;			// 정점 번호, 연결된 간선의 정점 번호와 간선 가중치
		cin >> node >> connected_node >> connected_weight;

		Link temp;
		temp.dest = connected_node;
		temp.weight = connected_weight;

		trees[node].push_back(temp);
	}


	// 트리에서 루트 노드가 주어져 있으므로 루트 노드부터 탐색을 진행하며 가장 큰 지름을 구함
	CalculateHeightDiameter(1);

	cout << max_diameter;
}

int main(void) {
	Solution1967();
	return 0;
}