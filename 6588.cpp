#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int prime[1000000];	// �����佺�׳׽��� ü�� �̿��� ���� �Ҽ��� ���� �迭
	int num_of_prime = 0;
	bool is_removed[1000001] = { false };	// ���ŵǾ����� Ȯ���� �� �ִ� �迭
	int start, end;	// start~end ������ �Ҽ��� ���� ��

	for (int i = 2; i <= end; i++) {
		if (is_removed[i] == false) {
			if (i >= start)
			{
				prime[num_of_prime++] = i;
			}
			for (int j = i * 2; j <= end; j += i) {
				is_removed[j] = true;
			}
		}
	}

	//�̸� �Ҽ����� �����佺�׳׽��� ü�� �̿��� ����� ����,
	//	N = a+b�� �Ѵٸ� �� �Ҽ����� ó������ ������ a�� �غ���
	//	�� a�� �Ǿ��� �� ������ b�� �Ҽ����� �ƴ����� �������鼭 �ϱ�

	int a, b;
	cin >> a >> b;
	cout << "qwer";
	return 0;
}