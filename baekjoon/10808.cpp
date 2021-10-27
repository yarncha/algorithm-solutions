#include <iostream>
#include <string>
using namespace std;

void solution_10808() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_alphabets[26] = { 0, };	//0으로 초기화
	string input;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		num_of_alphabets[input.at(i) - 'a'] = num_of_alphabets[input.at(i) - 'a'] + 1;
	}

	for (int j = 0; j < 25; j++)
	{
		cout << num_of_alphabets[j] << " ";
	}
	cout << num_of_alphabets[25];
}

int main(void) {
	solution_10808();
	return 0;
}