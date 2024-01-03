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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*t=head;
        ListNode*dummynode=new ListNode(-1);
        ListNode*current=dummynode;
        int cnt=0;
        while(t){
            cnt++;
            if(cnt%2!=0){
                ListNode*newnode=new ListNode(t->val);
                current->next=newnode;
                current=current->next;
            }
             t=t->next;
             
        }
        t=head;
        cnt=0;
         while(t){
            cnt++;
            if(cnt%2==0){
                ListNode*newnode=new ListNode(t->val);
                current->next=newnode;
                current=current->next;
            }
            t=t->next;
            
        }
        return(dummynode->next);
    }
};