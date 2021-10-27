#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

/*
iterative solution with stack

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.4 MB, less than 61.05% of C++ online submissions for Binary Tree Postorder Traversal.
*/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;

		if (root == NULL) {
			// if there is 0 nodes in the given trees
			return result;
		}

		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty())
		{
			TreeNode* cur = s.top();
			s.pop();

			result.insert(result.begin(), cur->val);
			if (cur->left != NULL) {
				s.push(cur->left);
			}
			if (cur->right != NULL) {
				s.push(cur->right);
			}
		}
		return result;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}