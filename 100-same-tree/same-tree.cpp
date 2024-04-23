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
//bfs solution
//tc=O(n) number of nodes
//sc=O(2n) because we use 2 sepearate queue for storing two different trees nodes
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        vector<vector<int>>v1;
        vector<vector<int>>v2;
        //root gulo queue te dhokarnor age dekhe nicchi je tree ta faka noi to ba kono root null noi to seta
        if(p!=NULL){
        q1.push(p);
        }
        if(q!=NULL){
        q2.push(q);
        }
        while(!q1.empty() || !q2.empty()){
           int n1=q1.size();
           int n2=q2.size();
           //protita level e jodi ekei number er node na thake thle identical noi
           if(n1!=n2){
            return false;
           }
           for(int i=0;i<n1;i++){
             TreeNode* node1=q1.front();
             TreeNode* node2=q2.front();
             q1.pop();
             q2.pop();
             //traversed node gulor value jodi same na hoi to identical noi
             if(node1->val!=node2->val){
                return false;
             }
             //jodi erom joi je ekta tree er ekta node er left child ache onno tree er oi same node er jonno left child nei thle identical noi
             if((node1->left==NULL && node2->left!=NULL)||(node1->left!=NULL && node2->left==NULL)){
                return false;
             }
             //jodi erom joi je ekta tree er ekta node er right child ache onno tree er oi same node er jonno right child nei thle identical noi
             if((node1->right==NULL && node2->right!=NULL)||(node1->right!=NULL && node2->right==NULL)){
                return false;
             }
             if(node1->left!=NULL){
                q1.push(node1->left);
             }
             if(node2->left!=NULL){
                q2.push(node2->left);
             }
             if(node1->right!=NULL){
                q1.push(node1->right);
             }
             if(node2->right!=NULL){
                q2.push(node2->right);
             }
           }
        }
           return true;
    }
};