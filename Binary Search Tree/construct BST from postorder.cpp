/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node *insertInBST(Node *root, int val)
{
	if (!root)
	{
		return new Node(val);
	}
	if (root->data < val)
	{
		root->right = insertInBST(root->right, val);
	}
	else
	{
		root->left = insertInBST(root->left, val);
	}
	return root;
}

Node *constructTree(int post[], int size)
{
	// code here
	if (size == 0)
	{
		return NULL;
	}
	Node *newHead = new Node(post[size - 1]);
	for (int i = size - 2; i >= 0; i--)
	{
		insertInBST(newHead, post[i]);
	}
	return newHead;
}