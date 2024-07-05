class Solution {
public:
//sort+sliding window problem sort chara sliding window hobe na
//sort kore nicchi karon ekta pattern chole asche je joto right side e move korbe difference toto
//barbe first index point er theke,tai possible minimum differece bar korar jonno sudhu adjacent window ba numbers er difference
//check korlei hobe O(n^2) e sob possible differnce check korar dorkar nei
//sort kore nile ekta sliding window er last number ta hobe highest number and first number ta hobe lowest number to erom sob fixed length(k)
//er sliding window er jader maximum and minimum er difference ta minimum sei minimum difference ta return korte hobe
    int minimumDifference(vector<int>& nums, int k) {
        //jodi bole ekta student jader maximum and minimum differnece ta kom thle otai oi student er highest marks and lowest marks
        //to difference of a same number is always been 0 so return 0
        if(k==1){
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int i=0,j=k-1;
        while(j<n){
            mini=min(mini,(nums[j]-nums[i]));
            j++;
            i++;
        }
        return mini;
    }
};