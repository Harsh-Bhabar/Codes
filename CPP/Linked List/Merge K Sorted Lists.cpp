// using MINHEAP and making new list

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
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto i : lists)
		{
			while (i)
			{
				pq.push(i->val);
				i = i->next;
			}
		}

		ListNode *newHead = new ListNode(-1);
		ListNode *curr = newHead;
		while (!pq.empty())
		{
			ListNode *newNode = new ListNode(pq.top());
			pq.pop();
			curr->next = newNode;
			curr = newNode;
		}

		return newHead->next;
	}
};

// using MERGE SORT

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
	ListNode *mergeTwoLL(ListNode *l1, ListNode *l2)
	{
		if (!l1)
		{
			return l2;
		}
		if (!l2)
		{
			return l1;
		}
		if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLL(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLL(l1, l2->next);
			return l2;
		}
		return NULL;
	}

	ListNode *breakAndJoin(vector<ListNode *> &lists, int l, int r)
	{
		if (l > r)
		{
			return NULL;
		}
		if (l == r)
		{
			return lists[l];
		}
		int mid = l + (r - l) / 2;
		ListNode *l1 = breakAndJoin(lists, l, mid);
		ListNode *l2 = breakAndJoin(lists, mid + 1, r);
		return mergeTwoLL(l1, l2);
	}

	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		int k = lists.size();
		if (k == 0)
		{
			return NULL;
		}
		return breakAndJoin(lists, 0, k - 1);
	}
};