class Solution {
public:
//tc=O(q+n)
//approach:count the bad index in the range..so we use prefix sum
//if you want to find range sum take prefix sum
//we just check in a given subarray the number of bad index(the index that is responsible for making non parity to it's previous index)
//if the number of bad index in the given range is >=1 that means the subarray is not valid
//so to find the number of bad index in a given range in O(1) we use prefix sum table,contains the number of bad index(suppose i) to it's previous index(i-1)
//so there is no previous index before 0 so we put 0'th index count is 0 initially
//if the subarray range is (l,r) then the number of bad index in the subarray is ((number of bad index till range r)-(number of bad index till range(l-1)))
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        unordered_map<int,int>badindex_inrange;
        int n=nums.size();
        //so there is no previous index before 0 so we put 0'th index count is 0 initially
        badindex_inrange.insert({0,0});
        //O(n) for taking prefix sum of bad index
        for(int i=1;i<n;i++){
            //bad index condition if two adjacent's %2 is same means that is not odd-even or even-odd
            if(nums[i-1]%2==nums[i]%2){
                //if i'th index is bad then the number of bad index till i'th index is-> number of bad index till i-1'th+1
                //that is taking prefix sum
                badindex_inrange[i]=badindex_inrange[i-1]+1;
            }
            //if it is not bad index then the prefix sum for count of bad index for the index is just count of bad index of it's previous index or (count of previous index +0)
            else{
                badindex_inrange[i]=badindex_inrange[i-1];
            }
        }
        //O(q) for traversing all queries
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            //if the subarray range is (l,r) then normally the number of bad index in the subarray is ((number of bad index till range r)-(number of bad index till range(l-1)))
            //but in these case it is (prefixsum[r]-prefixsum[l]) because the if l'th index is bad the it is for l-1'th index so we cant concider l'th index count in my subarray 
            int num_of_badindex=badindex_inrange[r]-badindex_inrange[l];
            if(num_of_badindex>=1){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};