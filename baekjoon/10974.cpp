#include <iostream>
#include <algorithm>
using namespace std;

void Solution10974() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_limit;			// 1~num_limit까지의 수로 이루어진 순열이 주어질 것 (1~8)
	cin >> num_limit;

	// 처음 수 만들기
	int num_arr[8];
	for (int i = 0; i < num_limit; i++)
	{
		num_arr[i] = i + 1;
	}

	for (int j = 0; j < num_limit; j++)
	{
		cout << num_arr[j] << " ";
	}
	cout << "\n";

	while (next_permutation(num_arr, num_arr + num_limit)) {
		for (int j = 0; j < num_limit; j++)
		{
			cout << num_arr[j] << " ";
		}
		cout << "\n";
	}
}

int main(void) {
	Solution10974();
	return 0;
}