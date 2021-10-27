#include <iostream>
#include <queue>
using namespace std;

int width_size;						// 정사각형 면적의 가로 세로 사이즈
int height_of_area[101][101];		// 각 지역의 높이 정보를 저장할 배열
bool is_checked[101][101];			// BFS를 하면서 각 지역을 지나갔는지 체크하기 위한 배열
int max_height_of_area = 1;				// 주어진 지역 중 최대 높이
int max_num_of_result = 1;				// 만들어지는 지역의 최대 갯수
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Bfs(int input_x, int input_y, int amount_of_rain) {
	// 특정 지역이 주어지면 면적 구하기
	queue<pair<int, int>> q;

	q.push(make_pair(input_x, input_y));
	is_checked[input_x][input_y] = true;
	while (!q.empty())
	{
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];
			if (next_x >= 0 && next_x < width_size && next_y >= 0 && next_y < width_size && (height_of_area[next_x][next_y] > amount_of_rain) && (is_checked[next_x][next_y] == false)) {
				q.push(make_pair(next_x, next_y));
				is_checked[next_x][next_y] = true;
			}
		}
	}
}

void Solution2468() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 값 입력 받기
	cin >> width_size;
	for (int x = 0; x < width_size; x++)
	{
		for (int y = 0; y < width_size; y++)
		{
			cin >> height_of_area[x][y];
			if (max_height_of_area < height_of_area[x][y]) {
				max_height_of_area = height_of_area[x][y];
			}
		}
	}

	// 2. 1부터 최대 높이까지 각 경우에 대해서 만들어지는 지역의 갯수를 구하기
	int num_of_result;
	for (int amount_of_rain = 1; amount_of_rain < max_height_of_area; amount_of_rain++)
	{
		// 1부터 max_height_of_area-1까지의 경우만 구하는 이유는 어차피 다 잠길 땐 안전 영역 개수가 0이고, 다 안잠길때는 1이라서 굳이 구할 필요가 없기 때문

		// 2-1. is_checked false로 초기화
		num_of_result = 0;
		for (int x = 0; x < width_size; x++)
		{
			for (int y = 0; y < width_size; y++)
			{
				is_checked[x][y] = false;
			}
		}

		// 2-2. 내린 비의 양보다 높고, 아직 탐색하지 않은 점들을 탐색하면서 연결된 요소의 개수를 구함
		for (int x = 0; x < width_size; x++)
		{
			for (int y = 0; y < width_size; y++)
			{
				if ((height_of_area[x][y] > amount_of_rain) && (is_checked[x][y] == false)) {
					Bfs(x, y, amount_of_rain);
					num_of_result++;
				}
			}
		}

		// 2-3. 비의 양이 amount_of_rain일 때, 구한 안전 영역의 개수가 최대인지 확인
		if (max_num_of_result < num_of_result) {
			max_num_of_result = num_of_result;
		}
	}

	cout << max_num_of_result;
}

int main(void) {
	Solution2468();
	return 0;
}