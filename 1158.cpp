#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	queue<int> q;
	//큐에 숫자 넣기
	for (int i = 1; i <= a; i++)
	{
		q.push(i);
	}

	cout << "<";

	//b번째 사람 선택
	int to_remove;
	while (q.size() > 1)
	{
		for (int j = 0; j < b - 1; j++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front();
	q.pop();


	cout << ">";
	return 0;
}