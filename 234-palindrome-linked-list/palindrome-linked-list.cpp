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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        map<int,int>mp;
        int cnt=0;
        ListNode*temp=head;
        while(temp){
            cnt++ ;
            mp.insert({cnt,temp->val});
            temp=temp->next;
        }
        int i;
        int tempcnt=cnt;
        for(i=1;i<=(cnt/2);i++){
            if(mp[i]!=mp[tempcnt]){
                break;
            }
            tempcnt--;
        }
        if(i>(cnt/2)){
            return true;
        }
        else{
            return false;
        }
    }
};