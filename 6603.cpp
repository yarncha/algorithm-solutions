#include <iostream>
#include <algorithm>
using namespace std;

/*
순열을 이용해서 풀 수도 있고
재귀함수를 이용해서 풀 수도 잇음
*/

int selected_num[12];			// 집합 S의 수. 여기서 6개의 수를 골라서 출력할 것
int is_selected[12];			// i번째 수가 선택되었는지 여부를 저장할 배열

void PrintArray(int k) {
	// 수를 고른 배열에 따라 출력하는 함수
	for (int i = 0; i < k - 1; i++)
	{
		if (is_selected[i]) {
			cout << selected_num[i] << " ";
		}
	}

	if (is_selected[k - 1]) {
		cout << selected_num[k - 1];
	}
	cout << "\n";
}

void Solution6603() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int k;
	cin >> k;

	while (k != 0)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> selected_num[j];
		}

		for (int m = 0; m < 6; m++)
		{
			is_selected[m] = 1;
		}
		for (int p = 6; p < k; p++)
		{
			is_selected[p] = 0;
		}

		PrintArray(k);
		while (prev_permutation(is_selected, is_selected + k))
		{
			PrintArray(k);
		}

		cout << "\n";

		cin >> k;
	}

}

int main(void) {
	Solution6603();
	return 0;
}