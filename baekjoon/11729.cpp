#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> logs;

void Hanoi(int block_num, int move_from, int move_to) {
	// 1부터 block_num개의 블럭을 move_from에서 move_to로 옮겨주는 함수

	if (block_num == 1) {
		logs.push_back(to_string(move_from) + " " + to_string(move_to));
		return;
	}

	// 1. 1~block_num-1개의 블럭을 재귀를 이용해서 다른 한 칸으로 옮기기
	Hanoi(block_num - 1, move_from, 6 - move_from - move_to);

	// 2. 맨 아래 블럭 옮기기
	logs.push_back(to_string(move_from) + " " + to_string(move_to));

	// 3. 다른 한 칸에 옮겨뒀던 블럭 move_to로 옮기기
	Hanoi(block_num - 1, 6 - move_from - move_to, move_to);
	return;
}

void Solution11729() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_blocks;		// 1~20
	cin >> num_of_blocks;

	// 재귀 사용해서 구해볼 것
	Hanoi(num_of_blocks, 1, 3);

	// 출력
	cout << logs.size() << "\n";
	for (int i = 0; i < logs.size(); i++)
	{
		cout << logs[i] << "\n";
	}
}

int main(void) {
	Solution11729();
	return 0;
}