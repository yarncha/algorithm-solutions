#include <iostream>
#include <vector>
using namespace std;

int max_point[100000][3] = { 0, };		// 2xi크기의 스티커에서 j번째 스티커를 뗐을 때의 최대 점수
										// 이때 j==0은 위쪽 스티커를 뗀 것, 1은 아랫쪽 스티커를 뗀 것, 2는 아무 스티커도 떼지 않은 것

void Solution9465() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_test_cases;
	cin >> num_of_test_cases;

	int width_of_sticker;		// 2xwidth_of_sticker가 스티커의 크기가 됨
	vector<int> sticker_line_0;
	vector<int> sticker_line_1;
	for (int i = 0; i < num_of_test_cases; i++)
	{
		cin >> width_of_sticker;

		// 주어진 스티커 값 채워넣기
		for (int i = 0; i < width_of_sticker; i++)
		{
			int element_0;
			cin >> element_0;
			sticker_line_0.push_back(element_0);
		}
		for (int j = 0; j < width_of_sticker; j++)
		{
			int element_1;
			cin >> element_1;
			sticker_line_1.push_back(element_1);
		}

		max_point[1][0] = sticker_line_0[0];
		max_point[1][1] = sticker_line_1[0];
		max_point[1][2] = 0;

		for (int k = 2; k <= width_of_sticker; k++)
		{
			// 2xi에서 위쪽 스티커를 뗐을 때 최대값은
			// 2xi-1에서 아래쪽 또는 아무 스티커도 떼지 않았을 때 중 최대값 + 위쪽 스티커의 포인트이다
			max_point[k][0] = max(max_point[k - 1][1], max_point[k - 1][2]) + sticker_line_0[k - 1];
			max_point[k][1] = max(max_point[k - 1][0], max_point[k - 1][2]) + sticker_line_1[k - 1];
			max_point[k][2] = max(max_point[k - 1][1], max_point[k - 1][0]);
		}

		cout << max(max_point[width_of_sticker][0], max(max_point[width_of_sticker][1], max_point[width_of_sticker][2])) << "\n";
		sticker_line_0.clear();
		sticker_line_1.clear();
	}
}

int main(void) {
	Solution9465();
	return 0;
}