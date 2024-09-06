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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //keep all deleted_node in a map so space is O(n)
        unordered_map<int,int>delete_val;
        for(int i=0;i<nums.size();i++){
            delete_val[nums[i]]++;
        }
        //if the list has only one node then check if deleted or nor if deleted return null or if not deleted return the list itself
        if(head->next==NULL){
            if(delete_val.find(head->val)!=delete_val.end()){
                return NULL;
            }
            return head;
        }
        ListNode* temp=head->next;
        ListNode*prev=head;
        //O(n) for linked list traversal and log(n) for map find algo
        //so O(nlogn)
        while(temp!=NULL){
            //check if the current value is to be deleted or not
            int value=temp->val;
            //if the current node value is found in map then delete the value
            //current node ta delete hole current node er ager node ta (prev) current node er next node er sathe align hoi jabe
            //mane current node ta delete hoi galo
            if(delete_val.find(value)!=delete_val.end()){
                prev->next=temp->next;
            }
            //prev ta egobe jokhon current node ta delete hobe na tokon temp ta prev temp ta temp->next
            //current node ta valid hole eta hobe
            else{
                prev=prev->next;
            }
            temp=temp->next;
        }
        //after all deletation is done check if the head of the node is to be deleted or not
        if(delete_val.find(head->val)!=delete_val.end()){
            //jodi head er por kono kichu na thake to null return koro
            if(head->next==NULL){
                return NULL;
            }
            head=head->next;
        }
        return head;
    }
};