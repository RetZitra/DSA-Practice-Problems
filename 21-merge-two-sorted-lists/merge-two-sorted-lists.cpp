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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        else if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        ListNode* dummynode=new ListNode(-1);
        ListNode*t1=list1;
        ListNode*t2=list2;
        ListNode*anslist=dummynode;
        while(t1!=NULL || t2!=NULL){
           if(t1!=NULL && t2!=NULL){
               if((t1->val)<=(t2->val)){
                ListNode*newnode=new ListNode(t1->val);
                t1=t1->next;
                anslist->next=newnode;
                anslist=anslist->next;
               }
               else{
                ListNode*newnode=new ListNode(t2->val);
                t2=t2->next;
                anslist->next=newnode;
                anslist=anslist->next;
               }
           }
           else if(t1!=NULL){
                ListNode*newnode=new ListNode(t1->val);
                t1=t1->next;
                anslist->next=newnode;
                anslist=anslist->next;
           }
           else{
               ListNode*newnode=new ListNode(t2->val);
                t2=t2->next;
                anslist->next=newnode;
                anslist=anslist->next;
           }
        }
        return (dummynode->next);
    }
};