#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
크기가 4 이상인 사이클이 존재하는지 존재하지 않는지

0,0 점부터 시작해서 아직 지나가지 않은 점들에 대해서 dfs수행
dfs를 수행하면, 지금 시작한 점에 인접해 있으면서 아직 지나가지 않았고 같은 색인 점들은 지나가고 값 넣어 줌
이미 지나갔던 점인데 같은 색일 경우에는 서로 값을 빼 보고, 3이상인 경우에 사이클 발견한거니까 바로 리턴하고 종료
근데 모든 요소 탐색해도 return하지 못하면 없는것이므로 없다고 하기

재귀함수를 이용한 DFS로 구현함.
 -> 다르게 구현할 수도 있을까 고민해보기
*/

char color[50][50];
int step[50][50];
int dr_x[] = { 0,0,1,-1 };
int dr_y[] = { 1,-1,0,0 };
int width, height;

bool dfs(int x, int y, int step_count) {
	step[x][y] = step_count;

	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dr_x[i];
		int new_y = y + dr_y[i];

		if (new_x >= 0 && new_y >= 0 && new_x < width && new_y < height && color[new_x][new_y] == color[x][y]) {
			if (step[new_x][new_y] == 0) {
				// 안 지나간 같은 색의 점일 경우, 해당 점 지나가기
				if (dfs(new_x, new_y, ++step_count)) {
					return true;
				}
			}
			else if (step[new_x][new_y] - step[x][y] >= 3 || step[new_x][new_y] - step[x][y] <= -3) {
				// 같은 색의 점이긴 한데 지나간 점이었을 경우, 그 차이가 3 이상이면 사이클이 생긴 것이므로 return
				return true;
			}
		}
	}

	return false;
}

void Solution16929() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력 받기
	cin >> width >> height;
	cin.ignore();

	for (int x = 0; x < width; x++)
	{
		string temp;
		getline(cin, temp);
		for (int y = 0; y < temp.size(); y++)
		{
			color[x][y] = temp.at(y);
		}
	}

	// dfs로 탐색
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (step[x][y] == 0) {
				if (dfs(x, y, 1)) {
					cout << "Yes\n";
					return;
				}
			}
		}
	}

	// 중간에 빠져나가지 않고 처리가 끝나면, 사이클이 없는 것
	cout << "No\n";
	return;
}

int main(void) {
	Solution16929();
	return 0;
}