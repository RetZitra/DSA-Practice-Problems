class Solution {
public:
    int maxelement(vector<int>&nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
            }
        }
        return maxi;
    }
    //take long long because each numbers of array can range 1e6 and if the array max length is 10e6 then we add all elements so it can be out of range 
    long long all_sum(vector<int> & nums){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    double sumresult(vector<int> & nums,int divisor){
        double sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=ceil((double)nums[i]/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //edge case
        // if we devide the array with 1 then we take ans as the sum of all element of the array..so if the thresold exides or equal to that so it is oviously the one and only ans to the problem
        //in the first tast case the sum of all elements is 17 if it  gives thresold as 17 or 18 or 100 the ans is 1 because if we devide the array with 1 then ans is 17 which dont ever cross the thresold if it is >= to 17
        if(threshold>=all_sum(nums)){
            return 1;
        }
        //take low as 1 because if there is one element in an array then the min and max element is pointing to the same element,so the search space is wrong so it might be not give the actual ans
        int low=1;
        int high=maxelement(nums);
        int ans;
        while(low<=high){
            int mid=(low+((high-low)/2));
            double result=sumresult(nums,mid);
            if(result<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};