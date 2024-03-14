class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
        if(nums.empty()==true){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int longest=INT_MIN;
    int current_count=1;
    sort(nums.begin(),nums.end());
    int prev=nums[0];
    for(int i=1;i<n;i++){
    if(prev==nums[i]){
        //if dublicate skip
    }
    else if(prev+1==nums[i]){
        //if two consecutive take it
        current_count++;
        prev=nums[i];
    }
    else{
        //if no consecutive reset
        current_count=1;
        prev=nums[i];
    }
    longest=max(current_count,longest);
    }
    return longest;
    }
};