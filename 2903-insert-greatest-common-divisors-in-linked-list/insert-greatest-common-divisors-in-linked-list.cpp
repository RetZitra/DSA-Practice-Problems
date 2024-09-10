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
 //approach:
 //(1) jodi 1 ta node thake to tar adjacent node nei tai tar mane kono node dukbe na
 //(2) na hole 2 pointer use kore 2to node er majhe sei 2to node er gcd dhokabo
class Solution {
public:
    int gcd(int n1, int n2){
        for(int i=min(n1,n2);i>0;i--){
            if(n1%i==0 && n2%i==0){
                return i;
            }
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //if there is one node in the linked list that means there are no adjacent node so we just return the list
        //we can' insert a node as there are no adjacent node
        if(head->next==NULL){
            return head;
        }
        ListNode*temp=head->next;
        ListNode*prev=head;
        while(temp!=NULL){
            int n1=temp->val;
            int n2=prev->val;
            int gc=gcd(n1,n2);
            //create a new node cantains the gcd of prev & temp and insert in in between temp & prev
            ListNode* newnode=new ListNode(gc);
            newnode->next=temp;
            prev->next=newnode;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};