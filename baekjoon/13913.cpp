#include <iostream>
#include <queue>
using namespace std;

/*
1697 숨바꼭질 문제와 같지만, 지나간 경로를 구해야 함
이런 문제를 역추적 문제라 함
*/

int time_to_get[100001];		// 특정 점부터 시작해서 i로 가는데 걸리는 최소 시간
int from[100001];				// i점 이전의 점을 저장할 배열

void PrintPassway(int point, int destination) {
	if (point != destination) {
		PrintPassway(from[point], destination);
	}

	cout << point << " ";
	return;
}

void Solution13913() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int start, dest;
	cin >> start >> dest;

	queue<int> q;
	q.push(start);
	time_to_get[start] = 1;
	from[start] = -1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur - 1 >= 0 && time_to_get[cur - 1] == 0) {
			time_to_get[cur - 1] = time_to_get[cur] + 1;
			from[cur - 1] = cur;
			q.push(cur - 1);
		}
		if (cur + 1 <= 100000 && time_to_get[cur + 1] == 0) {
			time_to_get[cur + 1] = time_to_get[cur] + 1;
			from[cur + 1] = cur;
			q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && time_to_get[cur * 2] == 0) {
			time_to_get[cur * 2] = time_to_get[cur] + 1;
			from[cur * 2] = cur;
			q.push(cur * 2);
		}

		if (time_to_get[dest] != 0) {
			break;
		}
	}

	cout << time_to_get[dest] - 1 << "\n";
	PrintPassway(dest, start);
}

int main(void) {
	Solution13913();
	return 0;
}