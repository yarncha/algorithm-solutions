class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		else {
			int left_depth = maxDepth(root->left);
			int right_depth = maxDepth(root->right);

			if (left_depth < right_depth) {
				return right_depth + 1;
			}
			else {
				return left_depth + 1;
			}
		}
	}
};