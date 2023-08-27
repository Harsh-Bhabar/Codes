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
	ListNode *swapPairs(ListNode *head)
	{
		// reverse in given size of K, K=2

		if (!head)
		{
			return head;
		}

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *prev = dummy;
		ListNode *curr = dummy;
		ListNode *next = dummy;
		int cnt = 0;

		while (curr->next)
		{
			cnt++;
			curr = curr->next;
		}

		if (cnt == 1)
		{
			return head;
		}

		while (cnt >= 2)
		{
			curr = prev->next;
			next = curr->next;
			for (int i = 1; i < 2; i++)
			{
				curr->next = next->next;
				next->next = prev->next;
				prev->next = next;
				next = curr->next;
			}
			prev = curr;
			cnt -= 2;
		}

		return dummy->next;
	}
};