class Solution {
public:
//memoization
//Tc=O(n)
//sc=O(n)+O(n)=O(2n)
    // int f(int n,vector<int>dp){
    //     if(n<=0){
    //         if(n==0){
    //             return 1;
    //         }
    //         else{
    //             return 0;
    //         }
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     else{
    //         return dp[n]=f(n-1,dp)+f(n-2,dp);
    //     }

    // }
    //tabulation TC=O(n)
    //Sc=O(n)
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i==1){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
};