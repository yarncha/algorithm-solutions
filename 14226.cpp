#include <iostream>
#include <queue>

using namespace std;

int min_time[1001][1001];

void Solution14226() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int dest;
	cin >> dest;

	queue<pair<int, int>> q;
	min_time[1][0] = 1;
	q.push(make_pair(1, 0));

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		if (cur_x >= dest) {
			break;
		}
		q.pop();

		if (min_time[cur_x][cur_x] == 0) {
			min_time[cur_x][cur_x] = min_time[cur_x][cur_y] + 1;
			q.push(make_pair(cur_x, cur_x));
		}

		if (cur_x + cur_y <= dest && min_time[cur_x + cur_y][cur_y] == 0) {
			min_time[cur_x + cur_y][cur_y] = min_time[cur_x][cur_y] + 1;
			q.push(make_pair(cur_x + cur_y, cur_y));
		}

		if (cur_x - 1 >= 0 && min_time[cur_x - 1][cur_y] == 0) {
			min_time[cur_x - 1][cur_y] = min_time[cur_x][cur_y] + 1;
			q.push(make_pair(cur_x - 1, cur_y));
		}
	}

	int result = 1000;
	for (int i = 0; i < 1001; i++)
	{
		if (min_time[dest][i] > 0 && result > min_time[dest][i]) {
			result = min_time[dest][i];
		}
	}

	cout << result - 1 << "\n";
}

int main(void) {
	Solution14226();
	return 0;
}
