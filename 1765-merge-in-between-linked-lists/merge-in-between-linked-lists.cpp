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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt=0;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        ListNode*prev=NULL;
        while(cnt<a){
           prev=temp1;
           temp1=temp1->next;
           cnt++;
        }
        while(cnt<=b){
            ListNode*del=temp1;
            prev->next=temp1->next;
            temp1=temp1->next;
            delete del;
            cnt++;
        }
        while(temp2!=NULL){
            ListNode* newnode=new ListNode(temp2->val);
            temp2=temp2->next;
            newnode->next=temp1;
            prev->next=newnode;
            prev=prev->next;
        }
        return list1;
    }
};