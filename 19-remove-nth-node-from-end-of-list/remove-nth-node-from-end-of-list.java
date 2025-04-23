/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int x) {
        //calculating the lenght of the node
        int len=0;
        ListNode temp=head;
        while(temp!=null){
            //jeheto count ta 0 theke start hocche tai age oi node er jonno length take barabo tarpor pointer thake next node e nie jabo ba onno kichu check korbo
            len++;
            temp=temp.next;
        }
        //ebar ami (n-x+1)th node er ager node e pointer ta nie jabo jeheto ami (n-x+1)th node take delete korbo
        //so ami pointer take (n-x+1)-1=(n-x) th node e nie jabo..mne current jei node ta delete hobe tar previous node e
        //kintu ekhane jodi head node take delete korte bole mne x=length hoi to alada bhabe handle korte hobe karon amra sekhetre 0th node take khujbo kintu 0th node paboi na karon node er numbering 1 theke start hobe
        if(x==len){
            //deleting head node
            head=head.next;
        }
        else{
        //to count the number of node traversed
        int cnt=0;
        temp=head;
        while(temp!=null){
            cnt++;
            if(cnt==(len-x)){
                break;
            }
            temp=temp.next;
        }
        //delete korar process previous node er next e , tar next node er next ke assign korlam
        temp.next=temp.next.next;
    }
        return head;
    }
    }