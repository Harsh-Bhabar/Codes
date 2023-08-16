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
	ListNode *rotateRight(ListNode *head, int k)
	{
		if (!head or !head->next || k == 0)
		{
			return head;
		}

		int len = 1;
		ListNode *curr = head;
		while (curr->next)
		{ // till last node
			len++;
			curr = curr->next;
		}
		curr->next = head; // make it point to head

		k = (len - k % len); // find new k

		while (k--)
		{ // move till kth node;
			curr = curr->next;
		}

		head = curr->next; // make a new head;
		curr->next = NULL; // mark it as end of list

		return head;
	}
};