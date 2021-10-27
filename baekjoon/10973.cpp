#include <iostream>
#include <algorithm>
using namespace std;

void Solution10973() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_limit;			// 1~num_limit까지의 수로 이루어진 순열이 주어질 것
	cin >> num_limit;

	int num_arr[10000];
	for (int i = 0; i < num_limit; i++)
	{
		cin >> num_arr[i];
	}

	if (!prev_permutation(num_arr, num_arr + num_limit)) {
		cout << "-1\n";
	}
	else {
		for (int j = 0; j < num_limit; j++)
		{
			cout << num_arr[j] << " ";
		}
	}
}

int main(void) {
	Solution10973();
	return 0;
}