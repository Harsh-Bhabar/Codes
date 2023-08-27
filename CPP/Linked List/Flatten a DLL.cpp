/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};
*/

class Solution
{
public:
	Node *flatten(Node *head)
	{

		Node *curr = head;
		Node *tail = head;
		stack<Node *> st;

		while (curr)
		{
			if (curr->child)
			{
				Node *child = curr->child;
				if (curr->next)
				{
					st.push(curr->next);
					curr->next->prev = NULL;
				}
				curr->next = child;
				child->prev = curr;
				curr->child = NULL;
			}
			tail = curr;
			curr = curr->next;
		}

		// this gives 1 2 3 7 8 11 12

		while (!st.empty())
		{
			curr = st.top();
			st.pop(); // pick and add to tail
			tail->next = curr;
			curr->prev = tail;
			while (curr)
			{
				tail = curr;
				curr = curr->next;
			}
		}

		return head;
	}
};