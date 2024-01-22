class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        while(n>j){
            if(nums[j]>nums[i]){
                if(nums[i+1]!=nums[j]){
                nums[i+1]=nums[i+1]^nums[j];
                nums[j]=nums[i+1]^nums[j];
                nums[i+1]=nums[i+1]^nums[j];
                }
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return(i+1);
    }
};