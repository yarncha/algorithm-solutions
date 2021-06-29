#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[100][100];					// 처음에는 맵의 땅/바다를 1/0으로 구분하고, 그 후에는 땅 확장을 통해 거리를 저장할 배열
int group[100][100];				// 그룹 넘버를 저장할 배열
int dr_x[] = { 0,0,1,-1 };
int dr_y[] = { 1,-1,0,0 };
vector<pair<int, int>> lands;		// 처음에 있던 땅의 목록을 저장해둘 벡터
int width;							// 맵의 폭
int group_num;						// 그룹 넘버를 매기기 위한 변수

void coloring(int x, int y, int num) {
	// x, y로 처음 값이 주어지면 이어진 땅을 상하좌우로 탐색해서 num으로 그룹을 매겨줌
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	group[x][y] = num;

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = cur_x + dr_x[i];
			int ty = cur_y + dr_y[i];

			if (tx >= 0 && ty >= 0 && tx < width && ty < width && map[tx][ty] == 1 && group[tx][ty] == 0) {
				q.push(make_pair(tx, ty));
				group[tx][ty] = num;
			}
		}
	}
}

void Solution2146() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력받기
	cin >> width;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int temp;
			cin >> temp;

			map[i][j] = temp;
			if (temp == 1) {
				// 1인 것들 lands에 넣어두고 색칠할 때, 거리 탐색할 때 시간 절약해서 사용하기 위함
				lands.push_back(make_pair(i, j));
			}
		}
	}


	// 색칠하기
	group_num = 1;			// 초기 그룹넘버는 1
	for (int k = 0; k < lands.size(); k++)
	{
		int cur_x = lands[k].first;
		int cur_y = lands[k].second;
		if (group[cur_x][cur_y] == 0) {
			coloring(cur_x, cur_y, group_num);		// 해당 그룹 넘버로 색칠해주고
			group_num++;							// 다음 그룹으로 넘어감
		}
	}


	// 땅 넓혀가며 구분하기
	queue<pair<int, int>> expand_q;
	for (int m = 0; m < lands.size(); m++)
	{
		// lands 벡터를 이용해 땅들과 이어진 바다를 하나씩 메꿔줌
		int cur_x = lands[m].first;
		int cur_y = lands[m].second;

		for (int i = 0; i < 4; i++)
		{
			int tx = cur_x + dr_x[i];
			int ty = cur_y + dr_y[i];

			if (tx >= 0 && ty >= 0 && tx < width && ty < width && map[tx][ty] == 0) {
				group[tx][ty] = group[cur_x][cur_y];
				map[tx][ty] = 2;
				expand_q.push(make_pair(tx, ty));
			}
		}
	}

	// 한번씩 메운 후 다음 메울 때에는 큐에서 꺼내가며 메워감
	int min_distance = 200;
	while (!expand_q.empty())
	{
		int cur_x = expand_q.front().first;
		int cur_y = expand_q.front().second;
		expand_q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = cur_x + dr_x[i];
			int ty = cur_y + dr_y[i];

			if (tx >= 0 && ty >= 0 && tx < width && ty < width) {
				if (map[tx][ty] == 0) {
					// 땅 넓히기
					group[tx][ty] = group[cur_x][cur_y];
					map[tx][ty] = map[cur_x][cur_y] + 1;
					expand_q.push(make_pair(tx, ty));
				}
				else if (group[tx][ty] != group[cur_x][cur_y]) {
					// 서로 다른 그룹이 마주쳤을 때에는 이 거리값이 min거리값이 되는지 계산
					int distance = map[tx][ty] + map[cur_x][cur_y];
					if (min_distance > distance) {
						min_distance = distance;
					}
				}
			}
		}
	}

	// 여기서 2를 빼준 게 두 땅 사이의 최소 거리
	cout << min_distance - 2 << "\n";
	return;
}

int main(void) {
	Solution2146();
	return 0;
}
