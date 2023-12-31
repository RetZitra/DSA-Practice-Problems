/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //    vector<pair<int,int>>adj[n+1];
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*t1=l1;
         ListNode*t2=l2;
         ListNode* dummynode=new ListNode(-1);
         ListNode*currNode=dummynode;
         int sum=0;
         int carry=0;
         while(t1!= NULL || t2!=NULL){
             sum=0;
             sum+=carry;
             if(t1!=NULL){
                 sum+=t1->val;
                 t1=t1->next;
             }
             if(t2!=NULL){
                 sum+=t2->val;
                 t2=t2->next;
             }
             carry=sum/10;
             sum=sum%10;
             ListNode*newnode=new ListNode(sum);
             currNode->next=newnode;
             currNode=currNode->next;
         }
         if (carry!=0){
             ListNode*newnode=new ListNode(carry);
             currNode->next=newnode;
         }
         return (dummynode->next);
    }
};