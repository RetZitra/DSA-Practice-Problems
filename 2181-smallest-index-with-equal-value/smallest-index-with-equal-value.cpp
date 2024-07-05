class Solution {
public:
//amk smallest index number ta bar korte boleche jekhane (i%10=nums[i]) ei condition ta hobe
    int smallestEqual(vector<int>& nums) {
       int small=INT_MAX;
       for(int i=0;i<nums.size();i++){
        if(i%10==nums[i]){
            small=min(small,i);
        }
       }
       if(small==INT_MAX){
        return -1;
       }
        return small;
    }
};