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
        if(head==NULL){
            return NULL;
        }
        ListNode*tempodd=head;
        ListNode*evenhead=head->next;
        ListNode*tempeven=head->next;
        while(tempeven && tempeven->next){
            tempodd->next=tempodd->next->next;
            tempodd=tempodd->next;
            tempeven->next=tempeven->next->next;
            tempeven=tempeven->next;
        }
        tempodd->next=evenhead;
        return head;

    }
};