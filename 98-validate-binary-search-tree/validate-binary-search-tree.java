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
    int minValue(TreeNode root) {
    TreeNode curr=root;
    int ans=0;
    while(curr!=null){
        ans=curr.val;
        curr=curr.left;
    }
    return ans;
    }
    int maxValue(TreeNode root) {
    TreeNode curr=root;
    int ans=0;
    while(curr!=null){
        ans=curr.val;
            curr=curr.right;
    }
    return ans;
    }
    void f(TreeNode root,int[]flag){
        if(root==null){
            return;
        }
        //current node ta inorder_predessor er theke boro ba hobe and inorder_succesor er theke choto  hobe
        //jodi na ei 2to na hoi to variable ta flase korbo ar traverse korte hobe na bolbo je ei tree ta bst noi karon
        //current node ta valid noi

        //so ei condition 2 tor er negetion jodi jekono 1 ta true holei oi node ta valid noi
        //jodi left subtree ei na thake thle ar left subtree er jonno current node ta valid kina check kore lav nei
        if (root.left != null && root.val <= maxValue(root.left)) {
            flag[0] = 0;
            return;
        }
        //jodi right subtree ei na thake thle ar right subtree er jonno current node ta valid kina check kore lav nei
       if (root.right != null && root.val >= minValue(root.right)) {
           flag[0] = 0;
           return;
        }
        //left subtree te same kaj
        f(root.left,flag);
        //right subtree te same kaj
        f(root.right,flag);
        //left subtree and right subtree er kaj sesh hole caller ke return korbo
        return;
    }
    public boolean isValidBST(TreeNode root) {
        //assume amar bst ta valid ebar jodi check korar pore invalid hoi to variable e update hoi jabe
        int[] flag=new int[1];
        flag[0]=1;
        f(root,flag);
        if(flag[0]==1){
            return true;
        }
        return false;
    }
}