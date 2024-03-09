class Solution {
public:
//memoization=tc(O(n))
//sc=(O(n)+O(n)=O(2n))
    int f(vector<int>nums,vector<int>&dp,int index){
        if(index==0){
            return nums[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick=nums[index]+f(nums,dp,index-2);
        int notpick=0+f(nums,dp,index-1);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // return f(nums,dp,n-1);
        //tabulation-Tc(O(n))
        //sc=O(n)
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int pick;
        //     if(i>1){
        //         pick=nums[i]+dp[i-2];
        //     }
        //     else{
        //         pick=nums[i]+0;
        //     }
        //     int notpick=0+dp[i-1];
        //     dp[i]=max(pick,notpick);
        // }
        // return dp[n-1];
        //space optimization TC=O(n)...sc=O(1)
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
};