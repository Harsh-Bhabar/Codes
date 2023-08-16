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
	ListNode *reverseList(ListNode *head)
	{
		if (head == NULL)
		{
			return NULL;
		}

		ListNode *prev = NULL;
		while (head)
		{
			ListNode *next = head->next; // store next node
			head->next = prev;			 // point head to prev
			prev = head;				 // move prev to head
			head = next;				 // move head to next
		}

		return prev;
	}
};