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
 //iterative solution
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        //first create the new node
        TreeNode newnode=new TreeNode(val);
        //if the tree is null then only return the new inserted node
        if(root==null){
            return newnode;
        }
        //to store the parent of current inserted ndoe
        TreeNode parent=null;
        TreeNode curr=root;
        //simple binary search to find the parent node of the new inserted node
        while(curr!=null){
            parent=curr;
            if(val<curr.val){
                curr=curr.left;
            }
            else if(val>curr.val){
                curr=curr.right;
            }
        }
        //if the new inserted node is less than the parent node then push it into left
        if(val<parent.val){
            parent.left=newnode;
        }
        //if the new inserted node is greater than the parent node then push it into right
        else{
            parent.right=newnode;
        }
        return root;
    }
}