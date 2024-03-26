class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        while(j<n){
           freq[nums[j]]++;
           //if there ar k times 0 then we can consider it is valid subarray ..but if it exceeds k times of 0
           //we can search for next subarry by moving i from forward
           if(freq.find(0)!=freq.end()){
            while(freq[0]>k){
                freq[nums[i]]--;
                i++;
            }
           }
           // taking the longest length of consecutive 1 after considering at most k times 0
           //because we can flip k 0's to 1
           int length=(j-i)+1;
           maxi=max(maxi,length);
           j++;
        }
        return maxi;
    }
};