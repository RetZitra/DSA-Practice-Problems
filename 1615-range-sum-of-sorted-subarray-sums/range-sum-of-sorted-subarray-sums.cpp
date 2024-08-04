class Solution {
//approcah:amk boleche je sob possible subarray er sum bar kore sei sum gulo ke sort kore asending order e ekta range er moddhe print korte
//so two-pointer use kore N^2 e sob subarray er sum ber kore ekta array te store kore rakhlam
//die seta ke sort korlam
//die oi range er sum bar korlam sorted array te
//die sum take 10^9+7 er sathe mod kore return korlam 
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const long long MOD = 1000000007;
        vector<int>all_sum;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                all_sum.push_back(sum);
            }
        }
        sort(all_sum.begin(),all_sum.end());
        long long ans=0;
        for(int i=left-1;i<right;i++){
            ans+=all_sum[i];
        }
        return (ans%MOD);
    }
};