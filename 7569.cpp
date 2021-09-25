#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int tomatoes[101][101][101];			// 토마토의 상태를 저장할 배열
int size_of_x, size_of_y, size_of_z;	// 박스의 xyz 크기
int dx[] = { -1,0,1,0,0,0 };			// 한 토마토가 익었을 때, 그 주변에 익힐 토마토들의 좌표를 저장해둠
int dy[] = { 0,0,0,1,0,-1 };
int dz[] = { 0,-1,0,0,1,0 };
int num_of_unriped_tomatoes = 0;			// 익지 않은 토마토의 개수를 셀 변수
vector<tuple<int, int, int>> riped_tomatoes;	// 익은 토마토의 좌표를 저장할 배열
int max_date = 1;							// 토마토가 다 익는데 걸리는 날짜

void explore_with_bfs(int x, int y, int z) {
	queue<tuple<int, int, int>> q;

	q.push(make_tuple(x,y,z));
	while (!q.empty())
	{
		tuple<int, int, int> current_tomato = q.front();
		int cur_x = get<0>(current_tomato);
		int cur_y = get<1>(current_tomato);
		int cur_z = get<2>(current_tomato);
		q.pop();

		for (int j = 0; j < 6; j++)
		{
			int next_x = cur_x + dx[j];
			int next_y = cur_y + dy[j];
			int next_z = cur_z + dz[j];

			if (tomatoes[next_x][next_y][next_z]==0) {
				// 익지 않은 토마토를 익힐 때
				tomatoes[next_x][next_y][next_z] = tomatoes[cur_x][cur_x][cur_x] + 1;
				num_of_unriped_tomatoes--;
			}
			else if () {

			}
		}

	}
}

void Solution7569() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 토마토 정보를 입력 받음
	cin >> size_of_x >> size_of_y >> size_of_z;
	for (int z = 0; z < size_of_z; z++)
	{
		for (int y = 0; y < size_of_y; y++)
		{
			for (int x = 0; x < size_of_x; x++)
			{
				cin >> tomatoes[x][y][z];
				if (tomatoes[x][y][z] == 1) {
					// 익은 토마토일 경우에는 riped_tomatoes에 튜플로 좌표를 저장해둠
					riped_tomatoes.push_back(make_tuple(x, y, z));
				}
				else if (tomatoes[x][y][z] == 0) {
					num_of_unriped_tomatoes++;
				}
			}
		}
	}

	// 2. riped_tomatoes에 있는 토마토들을 하나씩 탐색하며 bfs로 익지 않은 토마토를 익혀감
	for (int i = 0; i < riped_tomatoes.size(); i++)
	{
		explore_with_bfs(get<0>(riped_tomatoes[i]), get<1>(riped_tomatoes[i]), get<2>(riped_tomatoes[i]));
	}

	// 3. num_of_unriped_tomatoes(익지 않은 토마토의 개수)를 보고, 0이 아닐 경우에는 익지 못하는 것도 있기 때문에 -1을 출력하고, 아닐 경우에는 다 익히는 데 걸리는 날짜를 적는다
	if (num_of_unriped_tomatoes > 0) {
		cout << "-1";
	}
	else {
		cout << max_date - 1;
	}
}

int main(void) {
	Solution7569();
	return 0;
}