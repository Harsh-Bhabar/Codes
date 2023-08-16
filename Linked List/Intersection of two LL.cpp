// using lenth
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		int alen = 0;
		int blen = 0;

		ListNode *a = headA;
		ListNode *b = headB;

		while (a)
		{
			a = a->next;
			alen++;
		}
		while (b)
		{
			b = b->next;
			blen++;
		}

		a = headA;
		b = headB;

		if (alen > blen)
		{
			while (alen > blen)
			{
				a = a->next;
				alen--;
			}
		}
		else
		{
			while (blen > alen)
			{
				b = b->next;
				blen--;
			}
		}

		while (a && b && a != b)
		{
			a = a->next;
			b = b->next;
		}

		return a;
	}
};

// without using len

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *a = headA;
		ListNode *b = headB;

		while (a != b)
		{
			a = (a == NULL) ? headB : a->next;
			b = (b == NULL) ? headA : b->next;
		}

		return a;
	}
};