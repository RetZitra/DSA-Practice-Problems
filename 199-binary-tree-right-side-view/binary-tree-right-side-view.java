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
    List<Integer>f(TreeNode root,List<Integer>nodes,int level){
        //for traverse termination base case
        if(root==null){
            return nodes;
        }
        //jodi oi level er jonno kono node na thake array te thle rightmost node take oi level
        //er dhokabo
        if(nodes.size()<=level){
            nodes.add(root.val);
        }
        //traverse right subtree
        f(root.right,nodes,level+1);
        //traverse left subtree
        f(root.left,nodes,level+1);
        //after traverse all the subtrees from a node return to its parent
        return nodes;
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer>nodes=new ArrayList<>();
        int level=0;
        return f(root,nodes,level);
    }
}