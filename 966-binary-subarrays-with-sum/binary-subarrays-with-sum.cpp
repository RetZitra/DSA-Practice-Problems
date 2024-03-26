class Solution {
public:
//same pattern with leetcode 560
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefixsum;
        int sum=0;
        int n=nums.size();
        int count=0;
        prefixsum[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=(sum-goal);
            if(prefixsum.find(rem)!=prefixsum.end()){
                count+=prefixsum[rem];
            }
            prefixsum[sum]++;
        }
        return count;
    }
};