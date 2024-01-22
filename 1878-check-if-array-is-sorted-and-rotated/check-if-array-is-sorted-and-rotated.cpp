class Solution {
public:
    bool check(vector<int>& nums) {
        //if the array is roated sorted then there might me one time these happened that the one element 
        //is greater than the next element this is the position of the baraking point
        //if the braking point is greater than one than the array is not sorted
        //if the baraking point is 0 then it means the array is not roatated but sorted
        //if the braking point is 1 then it means the array is roatated but sorted
        int n=nums.size();
        int brakingpoint=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                brakingpoint++;
            }
            if(brakingpoint>1){
                return false;
            }
        }
        return true;
    }
};