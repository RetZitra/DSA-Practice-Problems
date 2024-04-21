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
//tc=O(n^2)
class Solution {
public:
//O(n^2) approach
//these function gives the height of a node
int dfs(TreeNode* node){
    if(node==NULL){
        return 0;
    }
    int lefth=dfs(node->left);
    int righth=dfs(node->right);
    return max(lefth,righth)+1;
}
//these function check that tree is balanced or not
//O(n)
bool check(TreeNode* node){
    //recursion jeheto sesh thek suru hoi tai dhore nicchi je..sob node er height balanced..base case
    if(node==NULL){
        return true;
    }
    //jodi ekta node er left subtree ba right subtree bole je..ami height balanced noi..to puro tree ta height balanced noi
        if(check(node->left)==false||check(node->right)==false){
            return false;
        }
        //o(n)
        //left subtree ar right subtree er height bar korchi
        int lefth=dfs(node->left);
        int righth=dfs(node->right);
        //height balanced er condition check korchi..jodi statisfy na kore to false
        if(abs(lefth-righth)>1){
            return false;
        }
        //jodi height balanced er sob codition statisfy kore to oi node tar jonno true..oi node ta height-balanced
        return true;
}
    bool isBalanced(TreeNode* root) {
        if(check(root)){
            return true;
        }
        return false;
    }
};