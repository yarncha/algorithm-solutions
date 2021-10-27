#include <iostream>
#include <algorithm>
using namespace std;

char input_alpabets[15];			// 입력으로 받은 알파벳의 배열
int is_selected[15];			// i번째 알파벳이 선택되었는지 여부를 저장할 배열

void PrintArray(int input_l) {
	// 입력받은 알파벳을 is_selected에 따라서 출력
	int num_of_vowels = 0;
	int num_of_consonants = 0;

	string output = "";
	for (int i = 0; i < input_l; i++)
	{
		// 한 글자씩 읽으면서 자음과 모음의 개수를 셈
		if (is_selected[i]) {
			if (input_alpabets[i] == 'a' || input_alpabets[i] == 'e' || input_alpabets[i] == 'i' || input_alpabets[i] == 'o' || input_alpabets[i] == 'u') {
				num_of_vowels++;
			}
			else {
				num_of_consonants++;
			}
			output.push_back(input_alpabets[i]);
		}
	}

	if (num_of_vowels >= 1 && num_of_consonants >= 2) {
		// 최소 한 개의 모음과 두 개의 자음으로 구성되어 있다는 조건이 있으므로, 이를 확인하고 조건에 맞을 경우에만 출력함
		cout << output << "\n";
	}

	return;
}

void Solution1759() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 입력받는 부분
	int input_l, input_c;		// 3<=input_l<=input_c<=15
	cin >> input_l >> input_c;

	for (int i = 0; i < input_c; i++)
	{
		cin >> input_alpabets[i];
	}

	// 2. 입력받은 input_alpabets을 정렬
	sort(input_alpabets, input_alpabets + input_c);

	// 3. is_selected 배열을 설정해 둔 뒤, prev_permutation을 통해 모든 경우를 구해봄
	for (int j = 0; j < input_l; j++)
	{
		is_selected[j] = 1;
	}
	for (int k = input_l; k < input_c; k++)
	{
		is_selected[k] = 0;
	}

	PrintArray(input_c);
	while (prev_permutation(is_selected, is_selected + input_c))
	{
		PrintArray(input_c);
	}
}

int main(void) {
	Solution1759();
	return 0;
}