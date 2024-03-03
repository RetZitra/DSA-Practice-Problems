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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next==NULL){
            if(n==1){
                return NULL;
            }
        }
        int cnt=0;
        ListNode*temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        ListNode*prev=NULL;
        temp=head;
        // cnt++;
        int revcnt=cnt+1;
        while(revcnt>0){
            revcnt--;
            if(revcnt==n){
                if(revcnt==cnt){
                   head=head->next;
                   delete(temp);
                   return head;
                }
                // else if(temp->next==NULL){
                //     prev->next=NULL;
                //     delete(temp);
                //     break;
                // }
                else{
                prev->next=temp->next;
                delete(temp);
                break;
                }
               
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};