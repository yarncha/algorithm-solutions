#include <iostream>
#include <algorithm>
using namespace std;

/*
1~N까지 번호가 매겨져 있는 도시들이 있음. 외판원이 어느 한 도시에서 출발해서 N개의 도시 모두를 거쳐 원래로 돌아오는 루트를 짜려고 할 때 가장 적은 비용을 들이는 여행 계획 구하기(한 번 갔던 도시로는 다시 갈수 없음)

범위를 보니 모든 경우에 대해서 다 구해봐도 됨 (첫순열 만들고 next_permutation하면서 다음 순열에 대해서도 계산해보기)

다시 돌아가기 때문에 1234 2341 3412 4123 모두 같은 경우임!! 따라서 시작점을 1로 고정해두면 시간복잡도를 줄일 수 있음 (n!방법)
*/

int cost[11][11];		// i에서 j로 가기 위한 비용 저장
int route[10];			// 여행 경로를 저장할 배열

int CalCulateCost(int num_of_cities) {
	int cost_sum = 0;

	for (int i = 0; i < num_of_cities - 1; i++)
	{
		int from = route[i];
		int to = route[i + 1];
		if (cost[from][to] == 0) {
			return 10000001;
		}
		else {
			cost_sum += cost[from][to];
		}
	}

	int from = route[num_of_cities - 1];
	int to = route[0];
	if (cost[from][to] == 0) {
		return 10000001;
	}
	else {
		cost_sum += cost[from][to];
	}

	return cost_sum;
}

void Solution10971() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력받기
	int num_of_cities;		//	도시의 개수 2~10
	cin >> num_of_cities;

	for (int i = 1; i <= num_of_cities; i++)
	{
		for (int j = 1; j <= num_of_cities; j++)
		{
			cin >> cost[i][j];
		}
	}

	// 첫 순열 만들기
	for (int j = 0; j < num_of_cities; j++)
	{
		route[j] = j + 1;
	}

	// 다음 순열을 하나씩 만들면서 가장 적은 비용을 들이는 여행 계획 
	int min_cost_sum = CalCulateCost(num_of_cities);
	while (next_permutation(route + 1, route + num_of_cities))
	{
		int cost_sum = CalCulateCost(num_of_cities);
		if (min_cost_sum > cost_sum) {
			min_cost_sum = cost_sum;
		}
	}

	cout << min_cost_sum << "\n";
}

int main(void) {
	Solution10971();
	return 0;
}