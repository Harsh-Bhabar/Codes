/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	bool isPalindrome(ListNode *head)
	{
		if (!head)
		{
			return false;
		}

		ListNode *slow = head;
		ListNode *fast = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		// find mid then from mid to end, reverse

		ListNode *prev = NULL;
		ListNode *curr = slow;
		while (curr)
		{
			ListNode *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		while (prev && head)
		{
			if (prev->val != head->val)
			{
				return false;
			}
			prev = prev->next;
			head = head->next;
		}

		return true;
	}
};