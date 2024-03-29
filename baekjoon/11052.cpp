#include <iostream>
using namespace std;

void Solution11052() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_card;					// 구매하고자 하는 카드의 개수 (1~1000)
	int costs_of_card_pack[10001];		// 카드가 n개 들어있는 카드팩의 가격, 하나의 가격 범위는 1~10000
	cin >> num_of_card;
	for (int i = 1; i <= num_of_card; i++)
	{
		int cost;
		cin >> cost;
		costs_of_card_pack[i] = cost;
	}

	// 1개를 갖기 위해 지불해야 하는 가격부터 최대값을 구해가며 계산함
	int max_cost_of_cards[1001] = { 0, };	// n개의 카드를 살 때의 최대값을 저장할 함수
	max_cost_of_cards[1] = costs_of_card_pack[1];	// 1개를 살 때는 1개 카드팩이 최대가격
	int max_cost, to_compare;
	for (int j = 2; j <= num_of_card; j++)
	{
		// 2개부터 연산하기 위해서는 각 값들의 최대값을 더해서 비교해봐야 함
		max_cost = costs_of_card_pack[j];		// 먼저 j개짜리 카드팩 하나로 샀을 경우의 가격을 max_cost로 두고,

		for (int k = 1; k <= j / 2; k++) {
			// 반복문을 이용해 카드팩
			to_compare = max_cost_of_cards[k] + max_cost_of_cards[j - k];
			if (to_compare > max_cost) {
				max_cost = to_compare;
			}
		}

		max_cost_of_cards[j] = max_cost;
	}

	cout << max_cost_of_cards[num_of_card];
}

int main(void) {
	Solution11052();
	return 0;
}