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
    int sumOfLeftLeaves(TreeNode* root) {
        //edge case jodi ekta tree er root tai leaf node hoi to tar left leaf node nei to sum 0 hobe
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        //level order traversal e protita level er first node tai left most node seta track korchi jokhon queue theke jokhon ekta ke pop korchi seta oi mohorte queue er first position e
        //ache mane i=0..ar protita level er left most node ta jodi leaf hoi to segulo ke add korchi
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL && node->left->left==NULL && node->left->right==NULL){
                    ans+=(node->left->val);
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};