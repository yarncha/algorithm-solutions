class Solution {
public:
	void deleteNode(ListNode* node) {
		// because node to delete is always not tail node, just change current node's value and next to next node's
		node->val = (node->next)->val;
		node->next = (node->next)->next;
	}
};