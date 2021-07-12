#include <iostream>
#include <queue>
using namespace std;

/*
각 트리의 노드에서 행이 의미하는 것은 해당 노트의 깊이(레벨)이고, 열이 의미하는 것은 해당 노드의 인오더 방문 순서임
*/

struct Node {
	int left, right;
	int x_value, depth_value;
};

Node nodes[10001];
bool has_parent[10001];
int order_count = 1;
int left_val[10001];
int right_val[10001];

void InOrder(int root, int depth) {
	// 트리를 inorder 방식으로 순회하는 함수
	if (root == -1) {
		return;
	}

	InOrder(nodes[root].left, depth + 1);
	nodes[root].depth_value = depth;
	nodes[root].x_value = order_count++;
	InOrder(nodes[root].right, depth + 1);
}

void Solution2250() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 트리를 배열에 넣고, 부모가 없는 것을 탐색해서 root라고 해주기
	int num_node;			// 노드의 개수 (1~10000)
	cin >> num_node;

	for (int i = 0; i < num_node; i++) {
		// nodes 배열에 노드 정보를 넣기
		int root_value, left_value, right_value;
		cin >> root_value >> left_value >> right_value;

		nodes[root_value].left = left_value;
		nodes[root_value].right = right_value;
		if (left_value != -1) {
			// 노드가 없는 경우(-1)가 아닐 때에는 left원소에게 부모가 있다는 것
			has_parent[left_value] = true;
		}
		if (right_value != -1) {
			// 노드가 없는 경우(-1)가 아닐 때에는 right원소에게 부모가 있다는 것
			has_parent[right_value] = true;
		}
	}

	int root_node = 0;
	for (int i = 1; i <= num_node; i++) {
		if (has_parent[i] == false) {
			root_node = i;
			break;
		}
	}


	// 2. 트리의 행(depth_value,level)과 열(x_value)을 알기 위해 인오더로 탐색하기
	InOrder(root_node, 1);


	// 3. 탐색하면서 가장 너비가 큰 곳을 찾음
	int max_x_distance_depth = 1;
	int max_x_distance = 1;

	queue<int> q;
	if (nodes[root_node].left != -1) {
		q.push(nodes[root_node].left);
	}
	if (nodes[root_node].right != -1) {
		q.push(nodes[root_node].right);
	}

	while (!q.empty())
	{
		// 큐에 원소를 넣고 해당 depth에서 가장 처음 원소 마지막 원소를 구해서 너비를 구함
		int start_x = nodes[q.front()].x_value;
		int start_depth = nodes[q.front()].depth_value;
		if (nodes[q.front()].left != -1) {
			q.push(nodes[q.front()].left);
		}
		if (nodes[q.front()].right != -1) {
			q.push(nodes[q.front()].right);
		}
		q.pop();

		int end_x = start_x;
		while (!q.empty() && nodes[q.front()].depth_value == start_depth)
		{
			end_x = nodes[q.front()].x_value;
			if (nodes[q.front()].left != -1) {
				q.push(nodes[q.front()].left);
			}
			if (nodes[q.front()].right != -1) {
				q.push(nodes[q.front()].right);
			}
			q.pop();
		}

		int cal_distance = end_x - start_x + 1;
		if (cal_distance > max_x_distance) {
			max_x_distance = cal_distance;
			max_x_distance_depth = start_depth;
		}
	}

	cout << max_x_distance_depth << " " << max_x_distance << "\n";
}

int main(void) {
	Solution2250();
	return 0;
}