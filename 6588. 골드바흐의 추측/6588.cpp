#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int prime[1000000];	// 에라토스테네스의 체를 이용해 구한 소수를 담을 배열
	int num_of_prime = 0;
	bool is_removed[1000001] = { false };	// 제거되었는지 확인할 수 있는 배열
	int start, end;	// start~end 사이의 소수를 구할 것

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

	//미리 소수들을 에라토스테네스의 체를 이용해 만들어 놓고,
	//	N = a+b라 한다면 이 소수들을 처음부터 끝까지 a로 해보고
	//	이 a가 되었을 때 나오는 b가 소수인지 아닌지를 따져가면서 하기

	int a, b;
	cin >> a >> b;
	cout << "qwer";
	return 0;
}