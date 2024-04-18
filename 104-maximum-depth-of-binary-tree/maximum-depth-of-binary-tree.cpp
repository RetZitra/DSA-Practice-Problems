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
//bfs traversal e queue ta empty hobar age joto bar cholche setai holo tar max level ba height
//first e 3 ta queue te elo to cnt=1
//trpr 9 20 ta queue te elo to cnt=2
//trpr 15 7 ta queue te elo to cnt=3
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int n=q.size();
          for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
          }
          cnt++;
        }
        return cnt;
    }
};