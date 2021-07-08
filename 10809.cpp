#include <iostream>
#include <string>
using namespace std;

void solution_10809() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_alphabets[26];
	//-1로 초기화
	for (int k = 0; k < 26; k++)
	{
		num_of_alphabets[k] = -1;
	}
	string input;
	getline(cin, input);

	// 단어를 읽으며 처음 등장하는 위치 저장
	for (int i = 0; i < input.size(); i++)
	{
		// 처음 등장했을 때에만 값을 넣어줌
		if (num_of_alphabets[input.at(i) - 'a'] == -1) {
			num_of_alphabets[input.at(i) - 'a'] = i;
		}
	}

	// 출력
	for (int j = 0; j < 25; j++)
	{
		cout << num_of_alphabets[j] << " ";
	}
	cout << num_of_alphabets[25];
}

int main(void) {
	solution_10809();
	return 0;
}