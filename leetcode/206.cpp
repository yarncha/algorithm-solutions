struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// reverse ListNode iteratively

	ListNode* reverseList(ListNode* head) {
		ListNode* current_node = head;

		// current_node (input) can be nullptr
		ListNode* result_node = nullptr;
		if (current_node != nullptr)
		{
			result_node = new ListNode(current_node->val);

			while (current_node->next != nullptr)
			{
				current_node = current_node->next;
				result_node = new ListNode(current_node->val, result_node);
			}
		}

		return result_node;
	}
};