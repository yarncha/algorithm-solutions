#include <iostream>
#include <queue>
using namespace std;

int map[300][300];
int dr_x[] = { 1,2,1,2,-1,-2,-1,-2 };
int dr_y[] = { 2,1,-2,-1,2,1,-2,-1 };

void Solution7562() {
	int width;				// 체스판의 한 변 길이(4~300)
	int cur_x, cur_y;		// 현재 위치
	int des_x, des_y;		// 도착 위치
	cin >> width >> cur_x >> cur_y >> des_x >> des_y;

	// 초기화
	for (int for_x = 0; for_x < width; for_x++)
	{
		for (int for_y = 0; for_y < width; for_y++)
		{
			map[for_x][for_y] = 0;
		}
	}

	queue<pair<int, int>> q;

	q.push(make_pair(cur_x, cur_y));
	map[cur_x][cur_y] = 1;

	while (!q.empty())
	{
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int new_x = cur_x + dr_x[i];
			int new_y = cur_y + dr_y[i];

			if (new_x >= 0 && new_y >= 0 && new_x < width && new_y < width && map[new_x][new_y] == 0) {
				q.push(make_pair(new_x, new_y));
				map[new_x][new_y] = map[cur_x][cur_y] + 1;
			}
		}
	}

	cout << map[des_x][des_y] - 1 << "\n";
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_test_case;
	cin >> num_test_case;
	for (int i = 0; i < num_test_case; i++)
	{
		Solution7562();
	}

	return 0;
}
