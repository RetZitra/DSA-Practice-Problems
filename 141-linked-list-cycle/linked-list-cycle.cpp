/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if the LL is empty or there is one node in the linkedList means there is no cycle in the linkedlist
        if(head==NULL ||head->next==NULL){
            return false;
        }
        ListNode*temp=head;
        unordered_map<ListNode*,bool>mp;
        //tc=O(n+logn for map insertion)
        //sc=O(n)store all unique node in map
        while(temp){
            //if there is repeating node means there is cycle in the linkedlist            
            if(mp.find(temp)!=mp.end()){
                return true;
            }
            else{
                mp[temp]=true;
                temp=temp->next;
            }
        }
        //temp end while reaches null so there is no cycle in linkedList
        return false;
    }
};