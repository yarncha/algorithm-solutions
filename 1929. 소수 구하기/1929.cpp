#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool is_removed[1000001] = { false };	// 제거되었는지 확인할 수 있는 배열
	int start, end;	// start~end 사이의 소수를 구할 것

	cin >> start >> end;

	for (int i = 2; i <= end; i++) {
		if (is_removed[i] == false) {
			if (i >= start)
			{
				cout << i << "\n";
			}
			for (int j = i * 2; j <= end; j += i) {
				is_removed[j] = true;
			}
		}
	}

	return 0;
}