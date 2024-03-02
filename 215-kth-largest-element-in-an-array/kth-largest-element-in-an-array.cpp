class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //take maxheap as qts says to give kth largest element
        priority_queue<int>pq;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(!pq.empty()){
            int curmaxi=pq.top();
            pq.pop();
            cnt++;
            if(cnt==k){
                return curmaxi;
            }
        }
        return 0;
    }
};