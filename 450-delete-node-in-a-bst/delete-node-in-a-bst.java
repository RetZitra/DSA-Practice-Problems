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
    //function to find the minimum element from a bst
     int minValue(TreeNode root) {
     TreeNode curr=root;
     int ans=-1;
     while(curr!=null){
         ans=curr.val;
         curr=curr.left;
     }
     return ans;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        //jodi tree tai null hoi thle amra root take return kore bolbo je kono element delete korar nei
        if(root==null){
            return root;
        }
        //left subtree er delete
        //jodi key ta choto hoi current value er theke left side e jabo , die left side jei updated node ta debe seta backtracking er somoy current node er left
        //e set korbo
        if(key<root.val){
            root.left=deleteNode(root.left,key);
        }
        //right subtree er delete
        //jodi key ta boro hoi current value er theke right side e jabo , die right side jei updated node ta debe seta backtracking er somoy current node er right
        //e set korbo
        else if(key>root.val){
            root.right=deleteNode(root.right,key);
        }
        //current node er delete
        //jodi current node takei delete korte hoi
        else{
            //case1 jodi leaf node hoi thle seta case2 er sathei handle hoi jabe, karon sekhete left subtree o null and right subtree o null to oi perticular node
            //er jonno null node return korbe
            //case 2 
            //jodi deleted node er right subtree null hoi thle current node take delete korar pore root ke left subtree ta debo
            if(root.right==null){
                return root.left;
            }
            else if(root.left==null){
                return root.right;
            }
            //jodi deleted node er 2to subtree ei thake thle inorder succesor take current node er stahe replace korbo
            //jeheto inorder succesor ta leaf node and seta current node er right e thake to current node er right node , ar oi inorder succesor er value ta die
            //delete function ta lagabo thle inorder succesor ta delete hoi jabe, die current node er right pointer e , oi right subtree je updated node dilo
            //delete korar pore seta set kore nebo
            else{
                root.val=minValue(root.right);
                root.right=deleteNode(root.right,root.val);
            }
        }
        //current updated root ta tar parent ke return korlam
        return root;
    }
}