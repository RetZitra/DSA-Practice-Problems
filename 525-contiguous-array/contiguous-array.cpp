class Solution {
public:
//tc=o(n)
//sc=o(n)
//classic prefixsum pattern ekhane khali terget sum nijeke bar korte hobe
//jodi 0 guloke -1 dhori to jokhon current sum= 0 hocche tokhon..sob 1 gulo cancle hoi jacche..to sum=0 hole tate equal 0's and 1's thekche..tai khali ektu bhabar
//terget sum=0..ar 0 ele currentsum e -1 add korbo jate jokhon terget sum=0 hobe tate equal amount e 0's and 1's thake
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int maxi=0;
        unordered_map<int,int>prefixsum;
        //tergetsum=0..here
        int targetsum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum+=-1;
            }
            else{
                sum+=1;
            }
            int rem=sum-targetsum;
            //jodi remaining take khuje pai age thle current valid subarray holo... tar porer position thek current position
            if(prefixsum.find(rem)!=prefixsum.end()){
                int length=(i-prefixsum[rem]);
                maxi=max(maxi,length);
            }
            //jodi total sum=target sum then the valid subarray is from oth position to current position
            if(sum==targetsum){
                maxi=max(maxi,i+1);
            }
            //longest boleche tai repetation sum store korbo na map e ..store sum as left as possible
            if(prefixsum.find(sum)==prefixsum.end()){
                prefixsum[sum]=i;
            }
        }
        return maxi;
    }
};