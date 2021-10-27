#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 104 ms, faster than 44.81% of C++ online submissions for All Possible Full Binary Trees.
Memory Usage: 35.2 MB, less than 45.81% of C++ online submissions for All Possible Full Binary Trees.
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<TreeNode*> generateFBTs(int n) {
		if (n == 1) {
			// 재귀적으로 탐색하며 n이 1일 때에는 리프노드를 리턴해주기
			return { new TreeNode(0) };
		}

		vector<TreeNode*> answer;			// 답을 저장할 vector
		vector<TreeNode*> left_trees, right_trees;		// 왼쪽과 오른쪽에 생길 트리에 대해 가능성들을 저장할 벡터

		n--;								// 현재 노드는 만들어졌다고 하고, 이제 left와 right에 생길 가능성들을 따져봄
		for (int i = 1; i < n; i += 2) {
			// 현재 노드를 제외하고 남은 노드를 1부터 2씩 증가해 가면서 재귀적으로 구함
			left_trees = generateFBTs(i);
			right_trees = generateFBTs(n - i);

			for (auto x : left_trees) {
				for (auto y : right_trees) {
					// left_trees벡터의 원소와 right_trees의 원소를 하나씩 매칭하며 새로운 treenode를 만들고 answer에 넣음
					TreeNode* root = new TreeNode(0);
					root->left = x;
					root->right = y;
					answer.push_back(root);
				}
			}
		}

		return answer;
	}

	vector<TreeNode*> allPossibleFBT(int n) {
		// 특별한 경우 처리를 먼저 해 주기
		if (n % 2 == 0) {
			// 짝수 개의 노드로는 만들 수 있는 FBT가 없음
			return {};
		}
		else if (n == 1) {
			return { new TreeNode(0) };
		}
		else if (n == 3) {
			return { new TreeNode(0, new TreeNode(0), new TreeNode(0)) };
		}

		return generateFBTs(n);
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}