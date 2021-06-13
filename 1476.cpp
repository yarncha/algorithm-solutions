#include <iostream>
using namespace std;

void Solution1476() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int e, s, m;
	cin >> e >> s >> m;

	for (int i = 0;; i++)
	{
		if (i % 15 == e -1) {
			if (i % 28 == s - 1) {
				if (i % 19 == m - 1) {
					cout << i+1;
					return;
				}
			}
		}
	}
}

int main(void) {
	Solution1476();
	return 0;
}
