#include <iostream>
using namespace std;

void Solutio1149() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_houses;		// 색을 칠하려는 집의 개수 (2~1000)
	cin >> num_of_houses;

	int min_cost_of_house_end_with_color[1001][3];	// i번째 집까지 색칠을 했고, 마지막 집의 색깔이 j였을 때 최소 금액
	int cost_of_R, cost_of_G, cost_of_B;			// 각 집을 빨 초 파로 칠하는 비용
	cin >> cost_of_R >> cost_of_G >> cost_of_B;
	min_cost_of_house_end_with_color[1][0] = cost_of_R;
	min_cost_of_house_end_with_color[1][1] = cost_of_G;
	min_cost_of_house_end_with_color[1][2] = cost_of_B;
	for (int i = 2; i <= num_of_houses; i++)
	{
		cin >> cost_of_R >> cost_of_G >> cost_of_B;
		// i까지 집을 칠할 때 마지막 집을 0(Red)로 칠했을 경우, 최소 비용은
		// i-1에서 집을 칠할 때 1(Green)또는 2(Blue)로 칠했을 때의 최소비용과 같다
		min_cost_of_house_end_with_color[i][0] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_R;
		min_cost_of_house_end_with_color[i][1] = min(min_cost_of_house_end_with_color[i - 1][0], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_G;
		min_cost_of_house_end_with_color[i][2] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][0]) + cost_of_B;
	}

	cout << min(min_cost_of_house_end_with_color[num_of_houses][0], min(min_cost_of_house_end_with_color[num_of_houses][1], min_cost_of_house_end_with_color[num_of_houses][2]));
}

int main(void) {
	Solutio1149();
	return 0;
}
