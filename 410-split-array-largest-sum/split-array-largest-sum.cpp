class Solution {
public:
    int max_array(vector<int>&nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        return maxi;
    }
    int max_range(vector<int>&nums,int k){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<(n-(k-1));i++){
            sum+=nums[i];
        }
        return sum;
    }
    bool ispossible(vector<int>&nums,int maxsum,int k){
        int subarrays=1;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]+sum<=maxsum){
                sum+=nums[i];
            }
            else{
                subarrays++;
                sum=nums[i];
            }
        }
        //if it is possible then this condition is true so the subarray we get is less than or equal to k so looking for minimum value which is not exceed the range
        if(subarrays<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=max_array(nums);
        int high=max_range(nums,k);
        while(low<=high){
            int mid=(low+((high-low)/2));
            if(ispossible(nums,mid,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        //low is at begining not possible range and high is possible range so after the search beacuse of opposite polarity cause low will go possible and high is go not possible range;
        return low;
    }
};