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
    //recursive function to calculate height of the tree
    int f(TreeNode root){
        //base case
        if(root==null){
            return 0;
        }
        //ekta node er height holo tar left subtree and right subtree er moddhe maximum depth jar , ar oi node ta concider korar jonno 1 plus korte 
        //hobe
        int left_height=f(root.left);
        int right_height=f(root.right);
        //eta holo last theke oi node obdhi current height
        int height=Math.max(left_height,right_height)+1;
        return height;
    }
    public int maxDepth(TreeNode root) {
        int ans=f(root);
        return ans;
    }
}