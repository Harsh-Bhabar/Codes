// using MINHEAP
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