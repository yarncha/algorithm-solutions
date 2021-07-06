#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*
1,1 에서 n,m으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 문제
빈 방을 이용하는 것을 가중치 0이라고 하고, 벽을 가중치 1로 하기

따라서 상하좌우로 이동하면서 빈 방으로 이동했을 때에는 가중치가 0이므로 덱의 앞에 넣고
벽이 있는 방으로 이동했을 때에는 가중치가 1이므로 덱의 뒤에 넣는다
*/

int spots[101][101];			// 미로에서 빈 방과 벽이 있는 방의 좌표를 저장할 배열
int walls[101][101];			// 미로에서 벽을 부수는 횟수를 저장할 배열
int dir_x[] = { 0,0,1,-1 };
int dir_y[] = { 1,-1,0,0 };

void Solution1261() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 이동하고자 하는 좌표의 크기를 입력받음
	int width, height;
	cin >> height >> width;
	cin.ignore();

	// spots 배열에 벽의 유무를 저장함
	for (int i = 1; i <= width; i++)
	{
		string input;
		getline(cin, input);
		for (int j = 1; j <= input.size(); j++)
		{
			spots[i][j] = input.at(j - 1) - 48;
		}
	}

	// 덱을 만들어 BFS로 탐색함
	deque<pair<int, int>> deq;
	walls[1][1] = 1;
	deq.push_back(make_pair(1, 1));

	while (!deq.empty())
	{
		int cur_x = deq.front().first;
		int cur_y = deq.front().second;
		deq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int x = cur_x + dir_x[i];
			int y = cur_y + dir_y[i];

			if (x >= 1 && y >= 1 && x <= width && y <= height && walls[x][y] == 0) {
				if (spots[x][y] == 0) {
					// 벽이 없는 방으로 이동할 때에는 가중치가 이전 것과 같음, 덱의 앞에 넣어줌
					walls[x][y] = walls[cur_x][cur_y];
					deq.push_front(make_pair(x, y));
				}
				else {
					// 벽이 있는 방으로 이동할 때에는 가중치가 이전 것+1이고, 덱의 뒤에 넣어줌
					walls[x][y] = walls[cur_x][cur_y] + 1;
					deq.push_back(make_pair(x, y));
				}
			}
		}

		if (walls[width][height] != 0) {
			break;
		}
	}

	cout << walls[width][height] - 1 << "\n";
}

int main(void) {
	Solution1261();
	return 0;
}
