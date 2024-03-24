class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_map<int,int>freq;
        int maxi=INT_MIN;
        while(j<n){
            freq[nums[j]]++;
            while(freq[nums[j]]>k){
               freq[nums[i]]--;
               i++;
            }
            int length=(j-i)+1;
            maxi=max(maxi,length);
            j++;
        }
        return maxi;
    }
};