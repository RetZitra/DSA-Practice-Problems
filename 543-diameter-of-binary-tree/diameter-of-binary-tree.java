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
    //function to find the height of the tree
    static int height(TreeNode root){
        if(root==null){
            return 0;
        }
        //height ta store korar jonno sudhu function call ei korchi na function ta
        //je value dicche seta store kore rakchi rkta variable e
        int left_height=height(root.left);
        int right_height=height(root.right);
        return (Math.max(left_height,right_height)+1);
    }
    //ekta node jodi kono diameter er part hoto thle oi node take nie tree tar diameter holo height of 
    //left subtree + height of right subtree + oi node take concider korar jonno +1
    //ebar sob node traverse kore dekhbo kono node take nie tree tar diameter maximum hoi sei value tai holo
    //oi tree er diameter
    static int diameter(TreeNode root){
        //base case jodi tree ta termination hoi jai oi position e node er diameter holo 0
        if(root==null){
            return 0;
        }
        //left subtree er diameter bar korlam
        int left_diameter=diameter(root.left);
        //right subtree er diameter bar korlam
        int right_diameter=diameter(root.right);
        //current node er diameter bar korlam
        int curr_diameter=height(root.left)+height(root.right)+1;
        //ei 3 te diameter er moodhe jeta maximum hobe seta return korbo
        return Math.max(Math.max(left_diameter,right_diameter),curr_diameter);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        //ei jei answer ta berobe seta holo 2to leaf node er maje jei maximum path ta ache tar size ba tate kotogulo node ache
        //tate koto gulo edge ache seta bar korar jonno amake -1 korte hobe,path size bar korar jonno
        //karon 2 to node e hoi ekta edge

        // ✅ Two possible definitions of diameter:
        //  In terms of number of nodes in the longest path
        //  Example: A → B → C → D → Diameter = 4 nodes

        // In terms of number of edges in the longest path 
        // (\U0001f4a1 This is the most commonly used in coding platforms like LeetCode)
        // Example: A → B → C → D → Diameter = 3 edges
        return(diameter(root)-1);
    }
}