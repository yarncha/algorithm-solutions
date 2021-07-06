#include <iostream>
#include <deque>
using namespace std;

/*
덱을 사용해서 넣어보기
0초 걸리는 이동은 앞에 넣고, 1초 걸리는 이동을 뒤에 넣고 하면 0초 걸리는 것들 먼저 처리해주면서
답을구할 수 있음

*/

int steps[100001];			// i번째 점으로 이동했을 때의 최소 시간

void Solution13549() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int start, dest;
	cin >> start >> dest;

	deque<int> deq;
	deq.push_back(start);
	steps[start] = 1;

	while (!deq.empty())
	{
		int cur = deq.front();
		deq.pop_front();

		// 0초 후에 순간이동으로 2*cur위치로 이동하게 된다면 덱의 앞에 넣어주기
		if (cur * 2 <= 100000 && steps[cur * 2] == 0) {
			steps[cur * 2] = steps[cur];
			deq.push_front(cur * 2);
		}

		// 1초 후에 cur+1 또는 cur-1위치로 이동하게 된다면 덱의 뒤에 넣어주기
		if (cur + 1 <= 100000 && steps[cur + 1] == 0) {
			steps[cur + 1] = steps[cur] + 1;
			deq.push_back(cur + 1);
		}
		if (cur - 1 >= 0 && steps[cur - 1] == 0) {
			steps[cur - 1] = steps[cur] + 1;
			deq.push_back(cur - 1);
		}

		if (steps[dest] != 0) {
			break;
		}
	}

	cout << steps[dest] - 1 << "\n";
}

int main(void) {
	Solution13549();
	return 0;
}
