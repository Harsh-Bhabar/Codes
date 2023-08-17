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
	ListNode *oddEvenList(ListNode *head)
	{

		// same as Partition List
		if (!head)
		{
			return head;
		}

		ListNode *odd = new ListNode(0);
		ListNode *even = new ListNode(0);
		ListNode *evenHead = even;
		ListNode *oddHead = odd;

		int i = 1;
		while (head)
		{
			if (i % 2 == 0)
			{
				evenHead->next = head;
				evenHead = evenHead->next;
			}
			else
			{
				oddHead->next = head;
				oddHead = oddHead->next;
			}
			i++;
			head = head->next;
		}

		evenHead->next = NULL;
		oddHead->next = even->next;

		return odd->next;
	}
};