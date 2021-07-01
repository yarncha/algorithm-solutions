#include <iostream>
#include <queue>
using namespace std;

int time_to_get[100000];		// 특정 점부터 시작해서 i로 가는데 걸리는 최소 시간

void Solution1697() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int start, dest;
	cin >> start >> dest;

	queue<int> q;
	q.push(start);
	time_to_get[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur - 1 >= 0 && time_to_get[cur - 1] == 0) {
			time_to_get[cur - 1] = time_to_get[cur] + 1;
			q.push(cur - 1);
		}
		if (cur + 1 <= 100000 && time_to_get[cur + 1] == 0) {
			time_to_get[cur + 1] = time_to_get[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && time_to_get[cur * 2] == 0) {
			time_to_get[cur * 2] = time_to_get[cur] + 1;
			q.push(cur * 2);
		}

		if (time_to_get[dest] != 0) {
			break;
		}
	}

	cout << time_to_get[dest] -1<< "\n";
}

int main(void) {
	Solution1697();
	return 0;
}
