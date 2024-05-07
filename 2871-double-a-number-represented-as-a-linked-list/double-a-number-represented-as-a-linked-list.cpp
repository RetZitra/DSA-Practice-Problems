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
//same qts as add 1 to a linkedlist
//total tc=O(3n)
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        //edge case jodi ektai node thake ar esta 0 hoi thle digit extract ta kaj korbe na num>0 condition ta sejonno amk oi linkedlist tai return korte hobe
        if(head->next==NULL && head->val==0){
            return head;
        }
        //tc=O(n) for first reverse
        head=reverse(head);
        ListNode*temp1=head;
        ListNode*dummynode=new ListNode(0);
        ListNode*temp2=dummynode;
        int carry=0;
        //linked list ta direct 2 die ek ek ta digit last theke multiply korte korte new linked list ta create korchi 
        //O(n) for creating newlinked list
        while(temp1!=NULL){
            int num=temp1->val*2;
            num=num+carry;
            //num%10 karon multiply korle ekta digit ei bosai to ektar beshi digit hobe na ekta node e
            ListNode* newnode=new ListNode(num%10);
            //ekta digit bade baki ta carry theke jeta porer multiply er sathe add hoi
            //updating carry for the current number after multiplication
            carry=num/10;
            temp2->next=newnode;
            temp2=temp2->next;
            temp1=temp1->next;
        }
        //jodi sesh e carry pore thke to setar jonno o new node create korte hobe
        if(carry>0){
            ListNode*newnode=new ListNode(carry);
            temp2->next=newnode;
        }
        ListNode*newhead=dummynode->next;
        //sesh e reverse kor ans dite hocche karon multiply right side theke kore node create korlam ar number left side theke dite hoi tai
        //O(n) for second reverse 
        newhead=reverse(newhead);
        return newhead;
    }
};