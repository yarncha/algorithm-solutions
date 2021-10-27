#include <iostream>
#include <vector>
using namespace std;

char board[201][201];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void PrintSolution(int R, int C) {
	// 출력을 위한 함수
	for (int x = 0; x < R; x++)
	{
		for (int y = 0; y < C; y++)
		{
			cout << board[x][y];
		}
		cout << "\n";
	}
}

void Solution16918() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int R, C, N;
	cin >> R >> C >> N;
	if (N % 2 == 0) {
		// N이 짝수일 때에는 모든 칸에 폭탄이 있는 것으로 출력
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				cin >> board[x][y];
				board[x][y] = 'O';
			}
		}
	}
	else if (N == 1) {
		// N이 1일 때에는 그대로 출력
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				cin >> board[x][y];
			}
		}
	}
	else if (N % 4 == 3) {
		// 나머지가 3일 경우에는 반대로 넣어준 뒤, '.'주변의 한칸을 '.'로 바꿔준 뒤 리턴한다.
		vector<pair<int, int>> bombs;
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				cin >> board[x][y];
				if (board[x][y] == '.') {
					board[x][y] = 'O';
				}
				else {
					board[x][y] = '.';
					bombs.push_back(make_pair(x, y));
				}
			}
		}

		for (int i = 0; i < bombs.size(); i++)
		{
			int cur_x = bombs[i].first;
			int cur_y = bombs[i].second;

			for (int j = 0; j < 4; j++)
			{
				int next_x = cur_x + dx[j];
				int next_y = cur_y + dy[j];

				if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && board[next_x][next_y] == 'O') {
					board[next_x][next_y] = '.';
				}
			}
		}
	}
	else if (N % 4 == 1) {
		// 나머지가 1일 경우에는 그대로 넣어준 뒤, 'O'주변의 한칸을 'O'로 바꿔준 뒤 리턴한다.
		vector<pair<int, int>> bombs;
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				cin >> board[x][y];
				if (board[x][y] == 'O') {
					bombs.push_back(make_pair(x, y));
				}
			}
		}

		while (!bombs.empty())
		{
			int cur_x = bombs.back().first;
			int cur_y = bombs.back().second;
			bombs.pop_back();

			for (int j = 0; j < 4; j++)
			{
				int next_x = cur_x + dx[j];
				int next_y = cur_y + dy[j];

				if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && board[next_x][next_y] == '.') {
					board[next_x][next_y] = 'O';
				}
			}
		}

		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				if (board[x][y] == '.') {
					bombs.push_back(make_pair(x, y));
				}
			}
		}

		while (!bombs.empty())
		{
			int cur_x = bombs.back().first;
			int cur_y = bombs.back().second;
			bombs.pop_back();

			for (int j = 0; j < 4; j++)
			{
				int next_x = cur_x + dx[j];
				int next_y = cur_y + dy[j];

				if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && board[next_x][next_y] == 'O') {
					board[next_x][next_y] = '.';
				}
			}
		}
	}

	PrintSolution(R, C);
	return;
}

int main(void) {
	Solution16918();
	return 0;
}