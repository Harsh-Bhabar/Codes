/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 // ITERATIVE

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null){
            return ans;
        }

        Stack<TreeNode> st = new Stack<TreeNode>();
        TreeNode curr = root;

        while(curr != null || !st.isEmpty()){
            while(curr != null){
                st.push(curr);
                curr = curr.left;
            }
            curr = st.peek();
            st.pop();
            ans.add(curr.val);
            curr = curr.right;
        }

        return ans;
    }
}

// RECURSIVE

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<Integer> ans = new ArrayList<>();
    
    TreeNode inorder(TreeNode root){
        if(root == null){
            return null;
        }
        inorder(root.left);
        ans.add(root.val);
        inorder(root.right);
        return root;
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null){
            return ans;
        }
        inorder(root);
        return ans;
    }
}