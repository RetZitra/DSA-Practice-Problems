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
 //approach:jamon dfs traverse kore tamon traverse korchi..die maximum depth e aschi die backtrack korar somoy dekhchi je jodi ota leaf node hoi..ar target hoi
 //to oi node take delete korchi..mane jeheto ota leaf node tai oi node take null kore dicchi thlei ota delete hoi jacche..mane oi node take ar concider korchi na
 //tc=O(n)bfs traversal
 //sc=O(n) stack space
class Solution {
public:
    void dfs(TreeNode*&node,int t){
        if(node==NULL){
            return;
        }
        dfs(node->left,t);
        dfs(node->right,t);
        //checking if the node is leaf node after backtracking
        if(node->left==NULL && node->right==NULL){
            //if the node value is same as target..then set the node to null..means deleting the node
            if(node->val==t){
                //delete korte hobe na oi node tai null kore debo..jeheto leaf node kono problem hobe na
                node=NULL;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root,target);
        return root;
    }
};