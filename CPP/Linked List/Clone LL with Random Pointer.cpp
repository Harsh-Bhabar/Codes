/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution
{
public:
	Node *duplicate(Node *head)
	{

		if (!head)
		{
			return NULL;
		}

		Node *curr = head;
		// make duplicae nodes in the middle
		while (curr)
		{
			Node *newNode = new Node(curr->val);
			Node *temp = curr->next;
			curr->next = newNode;
			newNode->next = temp;

			curr = temp;
		}

		curr = head;

		// set random pointers of duplicate created node
		while (curr)
		{
			curr->next->random = (curr->random) ? curr->random->next : NULL;
			curr = curr->next->next;
		}

		Node *og = head;
		Node *copy = head->next;
		Node *temp = copy;

		// break connection to newly created duplicate nodes
		while (og and copy)
		{
			og->next = og->next ? og->next->next : og->next;
			copy->next = copy->next ? copy->next->next : copy->next;
			og = og->next;
			copy = copy->next;
		}

		return temp;
	}

	Node *copyRandomList(Node *head)
	{
		return duplicate(head);
	}
};