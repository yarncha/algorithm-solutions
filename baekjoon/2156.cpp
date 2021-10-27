#include <iostream>
using namespace std;
int max_amount_of_wine[10001][2] = { 0, };		// i번째 잔을 마셨을 때 포도주의 양의 최대값
												// j==0일 경우는 해당 잔을 마시지 않을 경우
												// j==1일 경우는 현재 마시는 i번째 잔이 연속 첫 번째 잔일 경우
												// j==2일 경우는 연속 두번째인 경우

void Solution2156() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_wine_glasses;		// 포도주 잔의 개수 1~10000
	cin >> num_of_wine_glasses;

	int amount_of_wine;				// 한 잔의 포도주의 양
	cin >> amount_of_wine;			// 1번째 잔
	max_amount_of_wine[1][0] = 0;
	max_amount_of_wine[1][1] = amount_of_wine;
	max_amount_of_wine[1][2] = 0;

	cin >> amount_of_wine;			// 2번째 잔
	max_amount_of_wine[2][0] = max_amount_of_wine[1][1];
	max_amount_of_wine[2][1] = amount_of_wine;
	max_amount_of_wine[2][2] = max_amount_of_wine[1][1] + amount_of_wine;

	for (int i = 3; i <= num_of_wine_glasses; i++)
	{
		cin >> amount_of_wine;
		max_amount_of_wine[i][0] = max(max_amount_of_wine[i - 1][0], max(max_amount_of_wine[i - 1][1], max_amount_of_wine[i - 1][2]));
		max_amount_of_wine[i][1] = max_amount_of_wine[i - 1][0] + amount_of_wine;
		max_amount_of_wine[i][2] = max_amount_of_wine[i - 1][1] + amount_of_wine;
	}

	cout << max(max_amount_of_wine[num_of_wine_glasses][0], max(max_amount_of_wine[num_of_wine_glasses][1], max_amount_of_wine[num_of_wine_glasses][2]));
}

int main(void) {
	Solution2156();
	return 0;
}