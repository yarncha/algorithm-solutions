#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
그래프를 이용하는 다양한 방법인 인접 행렬, 인접 리스트, 간선 리스트 모두를 활용해 해당 친구관계가 존재하는지 구함

A-B-C-D-E 관계가 있는지 구할 때
A-B, C-D는 간선리스트에서 해당 정점이 연결되어 있는지를 구하고
이 중간에 끼어 있는 B-C의 관계는 인접 행렬을 통해 연결이 되어 있는지 확인하고
D-E는 인접 리스트를 통해 구해볼 것
*/

bool adjacency_matrix[2000][2000];          // 인접 행렬
vector<int> adjacency_list[2000];           // 인접 리스트 (크기가 2000인 int형 벡터 배열)
vector<pair<int, int>> edge_list;           // 간선 리스트

void Solution13023() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	// 1. 사람과 그 관계 입력 받기
	int num_of_people, num_of_relations;        // 사람의 수(5~20000)와 친구 관계의 수(1~2000)
	cin >> num_of_people >> num_of_relations;

	for (int i = 0; i < num_of_relations; i++) {
		int from, to;							// 사람 from부터 사람 to까지 연결되어 있다는 뜻
		cin >> from >> to;

		// 인접 행렬 연결
		adjacency_matrix[from][to] = true;
		adjacency_matrix[to][from] = true;

		// 인접 리스트 연결
		// from에 to를 넣어주고, to와 관계가 있다고 from을 넣어주는 방식
		adjacency_list[from].push_back(to);
		adjacency_list[to].push_back(from);

		// 간선 리스트 연결
		edge_list.push_back({ from, to });
		edge_list.push_back({ to, from });
	}


	// 2. 알맞은 관계 찾기
	num_of_relations *= 2;				// 친구 관계의 수가 양방향 그래프의 관계로 주어졌으니, 이를 일방향으로 바꾸기 위해 2를 곱해줌
	for (int i = 0; i < num_of_relations; i++) {
		for (int j = 0; j < num_of_relations; j++) {
			// A -> B, C -> D를 간선 리스트에서 찾기
			int A = edge_list[i].first;		// 0번째 페어에서
			int B = edge_list[i].second;
			int C = edge_list[j].first;		// 1번째 페어에서
			int D = edge_list[j].second;
			if (A == B || A == C || A == D || B == C || B == D || C == D) {
				// ABCD중 같은 게 있으면 건너뜀 (케이스 아님)
				continue;
			}

			// B -> C는 인접 행렬에서, 해당 행렬의 값이 true인지를 확인
			if (!adjacency_matrix[B][C]) {
				// true가 아닐 경우는 건너뜀 (케이스 아님)
				continue;
			}

			// D -> E는 인접 리스트에서
			for (int i = 0; i < adjacency_list[D].size(); i++) {
				int E = adjacency_list[D][i];
				if (A == E || B == E || C == E || D == E) {
					// E가 ABCD랑 같을 경우는 다음 E를 찾아나섬
					continue;
				}

				// 이 경우까지 확인되면 A-B-C-D-E 관계가 하나는 있는 것, 그러므로 1 출력하고 계산 끝냄
				cout << 1;
				return;
			}
		}
	}

	// 모든 경우를 살펴 봐도, A-B-C-D-E 조건을 만족하는 쌍이 없었을 경우는 그냥 0 출력
	cout << 0;
}

int main(void) {
	Solution13023();
	return 0;
}
