#include <iostream>
#include <queue>
using namespace std;

int width_size;						// 정사각형 면적의 가로 세로 사이즈
int height_of_area[101][101];		// 각 지역의 높이 정보를 저장할 배열
int height_of_area[101][101];		//
int max_height_of_area;				// 주어진 지역 중 최대 높이
int max_num_of_result;				// 만들어지는 지역의 최대 갯수

void Bfs() {
	// 특정 지역이 주어지면 면적 구하기
	queue<int> q;

}

void Solution2468() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 값 입력 받기
	cin >> width_size;
	for (int y = 0; y < width_size; y++)
	{
		for (int x = 0; x < width_size; x++)
		{
			cin >> 
		}
	}

	// 2. 1부터 최대 높이까지 각 경우에 대해서 만들어지는 지역의 갯수를 구하기
	int num_of_result;
	for (int i = 0; i < max_height_of_area; i++)
	{
		// 여기서 
	}
}

int main(void) {
	Solution2468();
	return 0;
}