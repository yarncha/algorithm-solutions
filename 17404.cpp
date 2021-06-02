#include <iostream>
using namespace std;

/*

1149 문제와 비슷하지만 조건이 하나 더 추가됨.
마지막과 첫번째 색깔이 달라야 한다는 것인데, 나는 그냥 첫 번째 색깔을 고정해서 예를 들어 R로 칠했다고 하면, 마지막이 G나 B로 끝나는 것들만 경우의 수로 센 뒤
어차피 첫 번째 집의 색깔이 G일 때나 B일 때

*/

void Solutio17404() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_houses;		// 색을 칠하려는 집의 개수 (2~1000)
	cin >> num_of_houses;

	int min_cost_of_house_end_with_color[1001][3][3];	// i번째 집까지 색칠을 했고, 마지막 집의 색깔이 j였으면서 처음 시작한 색깔은 k였을 때 최소 금액
	int cost_of_R, cost_of_G, cost_of_B;			// 각 집을 빨 초 파로 칠하는 비용
	cin >> cost_of_R >> cost_of_G >> cost_of_B;
	min_cost_of_house_end_with_color[1][0][0] = cost_of_R;		// R로 시작했을 때
	min_cost_of_house_end_with_color[1][1][1] = cost_of_G;		// G로 시작했을 때
	min_cost_of_house_end_with_color[1][2][2] = cost_of_B;		// B로 시작했을 때

	cin >> cost_of_R >> cost_of_G >> cost_of_B;
	min_cost_of_house_end_with_color[2][1][0] = min_cost_of_house_end_with_color[1][0][0] +cost_of_G;
	min_cost_of_house_end_with_color[2][2][0] = min_cost_of_house_end_with_color[1][0][0]+ cost_of_B;

	min_cost_of_house_end_with_color[2][0][1] = min_cost_of_house_end_with_color[1][1][1] + cost_of_R;
	min_cost_of_house_end_with_color[2][2][1] = min_cost_of_house_end_with_color[1][1][1] + cost_of_B;

	min_cost_of_house_end_with_color[2][0][2] = min_cost_of_house_end_with_color[1][2][2] + cost_of_R;
	min_cost_of_house_end_with_color[2][1][2] = min_cost_of_house_end_with_color[1][2][2] + cost_of_G;

	cin >> cost_of_R >> cost_of_G >> cost_of_B;
	min_cost_of_house_end_with_color[3][0][0] = min(min_cost_of_house_end_with_color[2][1][0], min_cost_of_house_end_with_color[2][2][0]) + cost_of_R;
	min_cost_of_house_end_with_color[3][1][0] = min_cost_of_house_end_with_color[2][2][0] + cost_of_G;
	min_cost_of_house_end_with_color[3][2][0] = min_cost_of_house_end_with_color[2][1][0] + cost_of_B;

	min_cost_of_house_end_with_color[3][0][1] = min_cost_of_house_end_with_color[2][2][1] + cost_of_R;
	min_cost_of_house_end_with_color[3][1][1] = min(min_cost_of_house_end_with_color[2][1][1], min_cost_of_house_end_with_color[2][2][1]) + cost_of_G;
	min_cost_of_house_end_with_color[3][2][1] = min_cost_of_house_end_with_color[2][0][1] + cost_of_B;

	min_cost_of_house_end_with_color[3][0][2] = min_cost_of_house_end_with_color[2][1][2] + cost_of_R;
	min_cost_of_house_end_with_color[3][1][2] = min_cost_of_house_end_with_color[2][0][2] + cost_of_G;
	min_cost_of_house_end_with_color[3][2][2] = min(min_cost_of_house_end_with_color[2][1][2], min_cost_of_house_end_with_color[2][0][2]) + cost_of_B;


	for (int i = 4; i <= num_of_houses; i++)
	{
		cin >> cost_of_R >> cost_of_G >> cost_of_B;
		// i까지 집을 칠할 때 마지막 집을 0(Red)로 칠했을 경우, 최소 비용은
		// i-1에서 집을 칠할 때 1(Green)또는 2(Blue)로 칠했을 때 최소비용 + i에 Red를 칠한 비용과 같다
		min_cost_of_house_end_with_color[i][0] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_R;
		min_cost_of_house_end_with_color[i][1] = min(min_cost_of_house_end_with_color[i - 1][0], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_G;
		min_cost_of_house_end_with_color[i][2] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][0]) + cost_of_B;

		min_cost_of_house_end_with_color[i][0] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_R;
		min_cost_of_house_end_with_color[i][1] = min(min_cost_of_house_end_with_color[i - 1][0], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_G;
		min_cost_of_house_end_with_color[i][2] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][0]) + cost_of_B;

		min_cost_of_house_end_with_color[i][0] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_R;
		min_cost_of_house_end_with_color[i][1] = min(min_cost_of_house_end_with_color[i - 1][0], min_cost_of_house_end_with_color[i - 1][2]) + cost_of_G;
		min_cost_of_house_end_with_color[i][2] = min(min_cost_of_house_end_with_color[i - 1][1], min_cost_of_house_end_with_color[i - 1][0]) + cost_of_B;
	}

	cout << min(min_cost_of_house_end_with_color[num_of_houses][0], min(min_cost_of_house_end_with_color[num_of_houses][1], min_cost_of_house_end_with_color[num_of_houses][2]));
}

int main(void) {
	Solutio17404();
	return 0;
}
