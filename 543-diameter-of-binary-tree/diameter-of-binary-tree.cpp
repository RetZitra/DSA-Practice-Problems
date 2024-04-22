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
    int dfs(TreeNode* node){
       if(node==NULL){
        return 0;
       }
       int left_h=dfs(node->left);
       int right_h=dfs(node->right);
       return max(left_h,right_h)+1;
    }
    //O(n^2) solution
    //sudu root er diameter bar korechi..sob node er diameter bar korte hobe
    //O(n) to finding the diameter of every node
    void f(TreeNode* node,int &ans){
        if(node==NULL){
            return;
        }
        //O(n) for finding the height of every node
        int lefth=dfs(node->left);
        int righth=dfs(node->right);
        ans=max(ans,lefth+righth);
        f(node->left,ans);
        f(node->right,ans);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};