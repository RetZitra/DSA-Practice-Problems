class Solution {
public:
    //Tc=O(n)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxconsione=0;
        int consione=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                consione=0;
            }
            else{
                consione++;
            }
            maxconsione=max(maxconsione,consione);
        }
        return maxconsione;
    }
};