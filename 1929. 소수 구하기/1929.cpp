#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool is_removed[1000001] = { false };	// ���ŵǾ����� Ȯ���� �� �ִ� �迭
	int start, end;	// start~end ������ �Ҽ��� ���� ��

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