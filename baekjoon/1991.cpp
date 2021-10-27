#include <iostream>
#include <vector>
using namespace std;

/*
트리를 입력받을 때, 순서대로 입력받지 않을 수도 있을 것 같아서 2차원 배열로 저장
*/

int trees[26][2];

void PrintPreOrder(int root) {
	char temp = 'A' + root;
	cout << temp;
	if (trees[root][0] != 0) {
		PrintPreOrder(trees[root][0]);
	}
	if (trees[root][1] != 0) {
		PrintPreOrder(trees[root][1]);
	}
	return;
}

void PrintInOrder(int root) {
	if (trees[root][0] != 0) {
		PrintInOrder(trees[root][0]);
	}
	char temp = 'A' + root;
	cout << temp;
	if (trees[root][1] != 0) {
		PrintInOrder(trees[root][1]);
	}
	return;
}

void PrintPostOrder(int root) {
	if (trees[root][0] != 0) {
		PrintPostOrder(trees[root][0]);
	}
	if (trees[root][1] != 0) {
		PrintPostOrder(trees[root][1]);
	}
	char temp = 'A' + root;
	cout << temp;
	return;
}

void Solution1991() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_nodes;		// 이진 트리의 노드의 개수 (1~26)
	cin >> num_of_nodes;

	for (int i = 0; i < num_of_nodes; i++)
	{
		char cur_char;
		cin >> cur_char;

		char left, right;
		cin >> left >> right;

		if (left != '.') {
			trees[cur_char - 65][0] = left - 65;
		}
		if (right != '.') {
			trees[cur_char - 65][1] = right - 65;
		}
	}

	PrintPreOrder(0);
	cout << "\n";

	PrintInOrder(0);
	cout << "\n";

	PrintPostOrder(0);
	cout << "\n";
}

int main(void) {
	Solution1991();
	return 0;
}