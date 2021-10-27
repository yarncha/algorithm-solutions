struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	// reverse ListNode recursively
	// 100% runtime

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		// get the reversed node of current node ~ end
		// example ) if there is 1-2-3(head)-4-5-nullptr,
		//			 reversed_node is 5-4-nullptr
		ListNode* reversed_node = reverseList(head->next);

		// head->next is 4, so connect current head next to 4
		// and delete current head's next
		// so reversed_node to return is "5-4-3(head)-nullptr"
		// ★ what's important is.. with creating a pointer with a value of 3 (head) (not create a new one)
		// so you can find a place to add it next
		ListNode* next_node = head->next;
		next_node->next = head;
		head->next = nullptr;

		return reversed_node;
	}
};