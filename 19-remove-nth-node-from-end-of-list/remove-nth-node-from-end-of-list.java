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
        //by using first and slow pointer
        //first pointer take slow pointer er theke x step egie rakhbo so, jokhon first pointer null node jabe slow pointer ta ,sesh theke xth node age thekbe to setai hobe sesh theke xth node jetake delete korte hobe
        //jodi first pointer ta last node e traverse sesh kore to slow pointer ta sesh theke (x-1)th node e thakbe , 1 ta node age thekbe to sekherte amra jei node delete korte hobe tar ager node pabo to amader subidha hobe delete korar khetre
        ListNode slow=head;
        ListNode first=head;
        //first pointer ta initially (x+1)th node e thakbe ba traverse start korbe,slow pointer ter theke x ghor egie thakbe
        int cnt=0;
        while(first!=null ){
            cnt++;
            if(cnt==x+1){
                break;
            }
            first=first.next;
        }
        //jodi initialization er somoy ei dekha jai je first pointer ta null e chole galo ba traverse sesh korlo ,thle amake head ta delete korte boleche
        if(first==null){
            head=head.next;
        }
        else{
        while(first!=null && first.next!=null){
            slow=slow.next;
            first=first.next;
        }
        slow.next=slow.next.next;
    }
        return head;
    }
}