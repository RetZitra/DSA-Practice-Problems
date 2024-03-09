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
        return f(nums,dp,n-1);
    }
};