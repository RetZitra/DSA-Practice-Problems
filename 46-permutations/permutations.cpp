class Solution {
    //TC=O(n!*n)
public:
    void f(vector<int>& nums,vector<int>& ds,vector<int>& map,vector<vector<int>>& ans){
        //base case
        //in a valid permutations the size if ds is same as the size of actual nums array
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //if ith index value is not taken in permutation take it
            if(!map[i]){
                ds.push_back(nums[i]);
                //mark that index is taken so that in current permutation it not take in same position
                map[i]=1;
                //check for next possible numbers for current permutation,using recursion call and privide all data structures for constraints
                f(nums,ds,map,ans);
                //while backtrack make sure the number is thaken in current position is removed from ds and unmarked it from map also
                ds.pop_back();
                map[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        //n size array with all value 0
        vector<int>map(n,0);
        f(nums,ds,map,ans);
        return ans;
    }
};