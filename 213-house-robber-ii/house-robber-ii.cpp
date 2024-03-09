class Solution {
public:
        int robb(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        //space optimization 
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
           int pick=nums[i]+prev2;
           int notpick=0+prev;
           int curri=max(pick,notpick);
           prev2=prev;
           prev=curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //jodi bari 1 ta thake to setar adjacent kono bari nei tai setai rob kore berie jabe
        if(n==1){
            return nums[0];
        }
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1){
               temp1.push_back(nums[i]);
            }
            if(i!=0){
               temp2.push_back(nums[i]);
            }
        }
        //solved subproblems from 0-(n-2)
        int ans1=robb(temp1);
        //solved subproblems from 1-(n-1)
        //return the max of ans1 and ans2 as in the ans first index and last index cant present together
        int ans2=robb(temp2);
        return max(ans1,ans2);
    }
};