#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> lists;		// 출발지, 편의점들, 도착지의 좌표를 저장할 배열
bool is_reachable[103][103];		// i번째 점에서 j번째 점을 갈 수 있는지를 저장할 배열

void FloydWarshall() {
	// 플로이드 워셜 알고리즘을 이용해서 도착 가능성을 업데이트한다
	int lists_size = lists.size();
	for (int point = 0; point < lists_size; point++) {
		for (int i = 0; i < lists_size; i++) {
			for (int j = 0; j < lists_size; j++) {
				if (is_reachable[i][j] == false && is_reachable[i][point] == true && is_reachable[point][j] == true) {
					is_reachable[i][j] = true;
				}
			}
		}
	}
}

void Solution9205() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_testcase;
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++)
	{
		// 먼저 입력 받기
		int num_of_convenience_store;		// 편의점 개수
		cin >> num_of_convenience_store;
		for (int j = 0; j < num_of_convenience_store + 2; j++)
		{
			int x, y;
			cin >> x >> y;
			lists.push_back(make_pair(x, y));
		}

		// 출발지에서 도착지를 갈 수 있는지 계산해보기 위해 플로이드 워셜 알고리즘을 사용했다.
		// 1. 처음 칸을 채워 넣는다. 각 장소에 대해서 거리를 계산해 보며 1000m이내에 존재할 경우에는 T를 넣고 아닐 경우에는 F이다.
		for (int x = 0; x < num_of_convenience_store + 2; x++)
		{
			for (int y = 0; y < num_of_convenience_store + 2; y++)
			{
				if (x == y) {
					is_reachable[x][y] = true;
				}
				else {
					int value_x_difference = lists[x].first - lists[y].first;
					if (value_x_difference < 0) {
						value_x_difference *= -1;
					}

					int value_y_difference = lists[x].second - lists[y].second;
					if (value_y_difference < 0) {
						value_y_difference *= -1;
					}

					if (value_x_difference + value_y_difference <= 1000) {
						is_reachable[x][y] = true;
					}
					else {
						is_reachable[x][y] = false;
					}
				}
			}
		}

		// 2. 모든 점들을 거치는 경우를 계산해 본다
		FloydWarshall();

		// 3. is_reachable[0][num_of_convenience_store+1]값에 따라 결과가 결정된다./
		if (is_reachable[0][num_of_convenience_store + 1] == true) {
			cout << "happy";
		}
		else {
			cout << "sad";
		}
		cout << "\n";

		// 초기화
		lists.clear();

	}
}

int main(void) {
	Solution9205();
	return 0;
}

//void FloydWarshall() {
//
//}
//
//int main(void) {
//	FloydWarshall();
//	return 0;
//}