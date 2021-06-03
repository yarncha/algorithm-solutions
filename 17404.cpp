#include <iostream>
using namespace std;

/*

1149 문제와 비슷하지만 조건이 하나 더 추가됨.
마지막과 첫번째 색깔이 달라야 한다는 것인데, 이렇게 되면 원형으로 집이 연결되어 있을 때와 같음

문제를 풀기 위해 그냥 첫 번째 색깔을 고정했음
예를 들어 R로 칠했다고 고정을 해 둔후, 마지막이 G나 B로 끝나는 것들만 경우의 수로 셈
이런 식으로 각 색깔에 대한 최소 비용을 셈

*/

const int kMaxNumber = 1001;
int min_cost_of_house_end_with_color[1001][3];	// i번째 집까지 색칠을 했고, 마지막 집의 색깔이 j였을 때 최소 금액
int value_of_colors[1001][3];	// i번째 집을 r(0) g(1) b(2)로 칠했을때의 비용

void Solutio17404() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_houses;		// 색을 칠하려는 집의 개수 (2~1000)
	cin >> num_of_houses;

	// 1. 배열에 미리 각 집을 rgb로 칠하는 비용을 저장해 둠
	int cost_of_R, cost_of_G, cost_of_B;			// 각 집을 빨 초 파로 칠하는 비용
	for (int i = 1; i <= num_of_houses; i++)
	{
		cin >> cost_of_R >> cost_of_G >> cost_of_B;
		value_of_colors[i][0] = cost_of_R;
		value_of_colors[i][1] = cost_of_G;
		value_of_colors[i][2] = cost_of_B;
	}

	// 2. 처음 색을 R(0) G(1) B(2)로 고정한 뒤 최소비용 구함
	int result;		// 결과로 나올 최소비용
	for (int j = 0; j < 3; j++)
	{
		// 먼저 처음 색 지정
		for (int k = 0; k < 3; k++)
		{
			// 처음 색을 지정한 색일 때만 원래 색의 비용으로 해 주고
			// 아닐 경우는 최대비용을 넘도록 설정해 주어서 나중에 무조건 저 색을 선택하는 일이 없도록 한다
			if (k == j) {
				min_cost_of_house_end_with_color[1][k] = value_of_colors[1][k];
			}
			else {
				min_cost_of_house_end_with_color[1][k] = kMaxNumber;
			}
		}

		// 두번째 색부터는 원래처럼
		for (int m = 2; m <= num_of_houses; m++)
		{
			// i까지 집을 칠할 때 마지막 집을 0(Red)로 칠했을 경우, 최소 비용은
			// i-1에서 집을 칠할 때 1(Green)또는 2(Blue)로 칠했을 때의 최소비용과 같다
			min_cost_of_house_end_with_color[m][0] = min(min_cost_of_house_end_with_color[m - 1][1], min_cost_of_house_end_with_color[m - 1][2]) + value_of_colors[m][0];
			min_cost_of_house_end_with_color[m][1] = min(min_cost_of_house_end_with_color[m - 1][0], min_cost_of_house_end_with_color[m - 1][2]) + value_of_colors[m][1];
			min_cost_of_house_end_with_color[m][2] = min(min_cost_of_house_end_with_color[m - 1][1], min_cost_of_house_end_with_color[m - 1][0]) + value_of_colors[m][2];
		}

		if (j == 0) {
			result = min(min_cost_of_house_end_with_color[num_of_houses][1], min_cost_of_house_end_with_color[num_of_houses][2]);
		}
		if (j == 1) {
			result = min(result, min(min_cost_of_house_end_with_color[num_of_houses][0], min_cost_of_house_end_with_color[num_of_houses][2]));
		}
		if (j == 2) {
			result = min(result, min(min_cost_of_house_end_with_color[num_of_houses][0], min_cost_of_house_end_with_color[num_of_houses][1]));
		}
	}

	cout << result;
}

int main(void) {
	Solutio17404();
	return 0;
}
