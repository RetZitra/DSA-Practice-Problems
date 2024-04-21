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
//karon recursion e jodi true and false return kori to ami oi node ta je height create korche seta return korte parchi na caller function ke..
//tar joono oi node er moddhe height pabar jonno abr amk n times oi node er joono dfs kore height pete hocche
//jodi amr dfs bole je left subtree and right subtree er height er difference 1 er cheye boro thle
//-1 return korbo..tar mane holo je tree tar height balanced noi
//ar nahole tree er height return korbo..karon jodi ota balanced hoi thle ei case e asbe ek..ar second amke tar ager node er height ta lagbe tai child node ta jodi balanced hoi to parent
//node ta balanced kina seta dekhar jonno tar height ta take dite hobe parent node e tobei se check korte parbe..se balanced kina
    int dfs(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int lefth=dfs(node->left);
        int righth=dfs(node->right);
        //left subtree ba right subtree er height jodi balanced na hoi to ar dekhte hobe na puro tree tai unbalanced 
        if(lefth==-1 || righth==-1){
            return -1;
        }
        //jodi current node ta unbalanced hoi to -1 die track korbo
        if(abs(lefth-righth)>1){
            return -1;
        }
        return (1+max(lefth,righth));
    }
    bool isBalanced(TreeNode* root) {
        int height=dfs(root);
        if(height==-1){
            return false;
        }
        return true;
    }
};