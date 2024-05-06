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
 //last node ta kokhonoi delete hobe na karon amk boleche je ekta node er right side e jodi or theke
 //boro kono node thake thle setake delete korte to last node er right side e kono node ei nei
class Solution {
public:
//Tc of reverse=O(n)
    ListNode* reverse(ListNode*head){
        ListNode* prev=NULL;
        ListNode*temp=head;
        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    //overall time-complexity=O(3n)
    //space complexity=O(1)..because we do all stuff by changing the link in the given linkedlist..not using extra vector ot array
    ListNode* removeNodes(ListNode* head) {
        int maxi=INT_MIN;
        ListNode*newhead=reverse(head);
        ListNode*temp=newhead;
        ListNode*prev=NULL;
        //first node ta delete hobe na to first node ta skip korchi
        //tc=O(n)
        while(temp!=NULL){
            maxi=max(maxi,temp->val);
            if((temp->val)<maxi){
                ListNode*front=temp->next;
                prev->next=front;
                temp=front;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        //again reverse so TC=O(n)
        ListNode*ans=reverse(newhead);
        return ans;
    }
};