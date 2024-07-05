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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //jodi linkedlist er length 2 hoi mane critical point paoa jabe na to tokhon (-1,-1) return korbo
        if(head->next->next==NULL){
            return vector<int>(2,-1);
        }
        vector<int>ans;
        //traversing the linkedlist from second node as to search critical node we have a node,which must have a previous node and a next node
        //for the same reason we ended traversing for last node,does not concider it
        //cnt count each node number from 2nd node
        ListNode*temp=head->next;
        ListNode*prev=head;
        int firstpoint=0;
        int lastpoint=0;
        int cnt=1;
        int mindis=INT_MAX;
        //our maximum distance will alwayse be the distance b/w first criticalpoints and lastcritical points so for that we just keep first critical points and break...just break the
        //whole traversing in two parts
        while(temp->next!=NULL){
           cnt++;
           //current node is localmaxima
           if(((prev->val)<(temp->val)) && ((temp->next->val)<(temp->val))){
             firstpoint=cnt;
             prev=temp;
             temp=temp->next;
             break;
           }
           //current node is localminima
           else if(((prev->val)>(temp->val)) && ((temp->next->val)>(temp->val))){
             firstpoint=cnt;
             prev=temp;
             temp=temp->next;
             break;
           }
           prev=temp;
           temp=temp->next;
        }
        //in the second traversing part we just check the the minimum distance b/w intermidiate critical points ,for minimum distance and update the lastpoint to the actual last critical
        //point after the whole traversal done..so lastpoint denotes the last critical point after traversal..and all intermidate critical node distance will be checked for minimal distance
        lastpoint=firstpoint;
        while(temp->next!=NULL){
           cnt++;
           //current node is localmaxima
           if(((prev->val)<(temp->val)) && ((temp->next->val)<(temp->val))){
             mindis=min(mindis,(cnt-lastpoint));
             lastpoint=cnt;
           }
           //current node is localminima
           else if(((prev->val)>(temp->val)) && ((temp->next->val)>(temp->val))){
            mindis=min(mindis,(cnt-lastpoint));
            lastpoint=cnt;
           }
           prev=temp;
           temp=temp->next;
        }
        //if there are only one criticalnode
        if(firstpoint==lastpoint){
            return vector<int>(2,-1);
        }
        int maxdis=lastpoint-firstpoint;
        ans.push_back(mindis);
        ans.push_back(maxdis);
        return ans;
    }
};