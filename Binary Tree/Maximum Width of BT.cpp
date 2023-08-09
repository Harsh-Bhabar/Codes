/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }   

        long ans = 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            long start = q.front().second;
            long end = q.back().second;
            ans = max(ans, end-start+1);

            while(n--){
                TreeNode* curr = q.front().first;
                long currInd = q.front().second - start;
                q.pop();
                if(curr->left){
                    q.push({curr->left, currInd * 2 + 1});
                }
                if(curr->right){
                    q.push({curr->right, currInd * 2 + 2});
                }
            }
        }

        return ans;
    }
};