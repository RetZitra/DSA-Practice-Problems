class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        int i;
        //edge case
        //ekta element thekle true return hobe
        if(n==1){
            return true;
        }
        for(i=1;i<n;i++){
            //if two adjacent are odd-even..then valid
            if(nums[i-1]%2!=0 && nums[i]%2==0){
               //skip ok conditions
            }
            //if two adjacent are even-odd..then also valid
            else if(nums[i-1]%2==0 && nums[i]%2!=0){
                //skip ok conditions
            }
            //two adjacent ar not in same parity
            else{
                break;
            }
        }
        if(i<n){
            return false;
        }
        return true;
    }
};