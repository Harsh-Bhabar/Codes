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
		priority_queue<int, vector<int>, greater<int>> minHeap;

		for (auto it : lists)
		{
			while (it)
			{
				minHeap.push(it->val);
				it = it->next;
			}
		}

		if (minHeap.empty())
		{
			return NULL;
		}

		ListNode *newHead = new ListNode(minHeap.top());
		minHeap.pop();
		ListNode *curr = newHead;

		while (!minHeap.empty())
		{
			ListNode *newNode = new ListNode(minHeap.top());
			minHeap.pop();
			curr->next = newNode;
			curr = newNode;
		}

		return newHead;
	}
};