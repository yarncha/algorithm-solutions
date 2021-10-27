#include <iostream>
#include <string>
using namespace std;

void Solution3085() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 먼저 입력을 받아 줌
	char board[51][51];		// 보드에 사탕이 채워져 있는 상태를 저장할 배열

	int board_size;
	cin >> board_size;
	cin.ignore();

	string input_string;
	for (int i = 0; i < board_size; i++)
	{
		getline(cin, input_string);
		for (int j = 0; j < board_size; j++)
		{
			board[i][j] = input_string.at(j);
		}
	}

	// 2. 전체에서 가장 긴 연속된 같은 색깔의 사탕의 길이를 구함
	int max_length_of_continuous_colors = 0;
	int current_length_of_continuous_colors = 1;

	// 가로로 가장 긴 길이 측정
	for (int x = 0; x < board_size; x++)
	{
		for (int y = 1; y < board_size - 1; y++)
		{
			if (board[x][y] == board[x][y - 1]) {
				// 이전 사탕과 비교해서 색깔이 같은 사탕일 경우 연속되는 것이므로 current에 1을 더해주고
				current_length_of_continuous_colors++;
			}
			else {
				// 아닐 경우는 지금까지 했던 current가 max를 넘어가는지 비교 후
				// 1로 초기화시켜준다 (새로운 색깔의 사탕)
				if (max_length_of_continuous_colors < current_length_of_continuous_colors) {
					max_length_of_continuous_colors = current_length_of_continuous_colors;
				}
				current_length_of_continuous_colors = 1;
			}
		}

		if (board[x][board_size - 1] == board[x][board_size - 2]) {
			current_length_of_continuous_colors++;
		}
		if (max_length_of_continuous_colors < current_length_of_continuous_colors) {
			max_length_of_continuous_colors = current_length_of_continuous_colors;
		}
		current_length_of_continuous_colors = 1;
	}

	// 세로로 가장 긴 길이 측정
	for (int y = 0; y < board_size; y++)
	{
		for (int x = 1; x < board_size - 1; x++)
		{
			if (board[x][y] == board[x - 1][y]) {
				// 이전 사탕과 비교해서 색깔이 같은 사탕일 경우 연속되는 것이므로 current에 1을 더해주고
				current_length_of_continuous_colors++;
			}
			else {
				// 아닐 경우는 지금까지 했던 current가 max를 넘어가는지 비교 후
				// 1로 초기화시켜준다 (새로운 색깔의 사탕)
				if (max_length_of_continuous_colors < current_length_of_continuous_colors) {
					max_length_of_continuous_colors = current_length_of_continuous_colors;
				}
				current_length_of_continuous_colors = 1;
			}
		}

		if (board[board_size - 1][y] == board[board_size - 2][y]) {
			current_length_of_continuous_colors++;
		}
		if (max_length_of_continuous_colors < current_length_of_continuous_colors) {
			max_length_of_continuous_colors = current_length_of_continuous_colors;
		}
		current_length_of_continuous_colors = 1;
	}

	// 3. max를 가지고 있는 상태에서 사탕을 옆이나 아래와 교환했을 때 max가 달라지는지 구해서 max값 조정
	for (int x = 0; x < board_size; x++)
	{
		for (int y = 0; y < board_size - 1; y++)
		{
			swap(board[x][y], board[x][y + 1]);

			int counter = 1;
			for (int i = y - 1; i >= 0; i--)
			{
				if (board[x][y] == board[x][i]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			if (board[x][y] != board[x][y + 1]) {
				counter = 1;
			}
			else {
				counter++;
			}
			for (int i = y + 2; i < board_size; i++)
			{
				if (board[x][y + 1] == board[x][i]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			counter = 1;
			for (int i = x - 1; i >= 0; i--)
			{
				if (board[x][y] == board[i][y]) {
					counter++;
				}
				else {
					break;
				}
			}
			for (int i = x + 1; i < board_size; i++)
			{
				if (board[x][y] == board[i][y]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			counter = 1;
			for (int i = x - 1; i >= 0; i--)
			{
				if (board[x][y + 1] == board[i][y + 1]) {
					counter++;
				}
				else {
					break;
				}
			}
			for (int i = x + 1; i < board_size; i++)
			{
				if (board[x][y + 1] == board[i][y + 1]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			swap(board[x][y], board[x][y + 1]);
		}
	}

	for (int y = 0; y < board_size; y++)
	{
		for (int x = 0; x < board_size - 1; x++)
		{
			swap(board[x][y], board[x + 1][y]);

			int counter = 1;
			for (int i = x - 1; i >= 0; i--)
			{
				if (board[x][y] == board[i][y]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			if (board[x][y] != board[x + 1][y]) {
				counter = 1;
			}
			else {
				counter++;
			}
			for (int i = x + 2; i < board_size; i++)
			{
				if (board[x + 1][y] == board[i][y]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			counter = 1;
			for (int i = y - 1; i >= 0; i--)
			{
				if (board[x][y] == board[x][i]) {
					counter++;
				}
				else {
					break;
				}
			}
			for (int i = y + 1; i < board_size; i++)
			{
				if (board[x][y] == board[x][i]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			counter = 1;
			for (int i = y - 1; i >= 0; i--)
			{
				if (board[x + 1][y] == board[x + 1][i]) {
					counter++;
				}
				else {
					break;
				}
			}
			for (int i = y + 1; i < board_size; i++)
			{
				if (board[x + 1][y] == board[x + 1][i]) {
					counter++;
				}
				else {
					break;
				}
			}
			if (max_length_of_continuous_colors < counter) {
				max_length_of_continuous_colors = counter;
			}

			swap(board[x][y], board[x + 1][y]);
		}
	}

	cout << max_length_of_continuous_colors;
}

int main(void) {
	Solution3085();
	return 0;
}