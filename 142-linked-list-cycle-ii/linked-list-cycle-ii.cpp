/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//TC=O(n)
//Sc=O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        unordered_map<ListNode*,int>mp;
        ListNode*temp=head;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            else{
                mp[temp]=1;
                temp=temp->next;
            }
        }
        return NULL;
    }
};