class Solution
{
public:
	int numTrees(int n)
	{

		//  we can see that the total number of unique BST G(n),
		//  is the sum of BST F(i) using each number i as a root.
		// => G(n) = F(1, n) + F(2, n) + ... + F(n, n).

		// only one combination to construct a BST
		// out of a sequence of length 1 (only a root) or 0 (empty tree).
		// => G(0)=1, G(1)=1.

		// Given a sequence 1…n, we pick a number i, then the number of
		// unique BST with the specified root F(i),
		// is the cartesian product of the number of BST for its left and right subtrees.
		// For example, F(3, 7): the number of unique BST tree with number 3 as its root.
		// To construct an unique BST out of the entire sequence [1, 2, 3, 4, 5, 6, 7]
		// with 3 as the root, which is to say,
		// we need to construct an unique BST out of its left subsequence [1, 2]
		// and another BST out of the right subsequence [4, 5, 6, 7],
		// and then combine them together (i.e. cartesian product).
		// The tricky part is that we could consider
		// the number of unique BST out of sequence [1,2] as G(2),
		// and the number of of unique BST out of sequence [4, 5, 6, 7] as G(4).
		// Therefore, F(3,7) = G(2) * G(4).
		// F(i, n) = G(i-1) * G(n-i)	1 <= i <= n

		// Combining the above two formulas, we obtain the recursive formula for G(n).
		// G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)

		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}

		return dp[n];
	}
};