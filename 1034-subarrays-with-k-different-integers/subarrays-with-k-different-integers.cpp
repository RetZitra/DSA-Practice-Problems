class Solution {
public:
//these is the combination problem of fruits into busket(longest subarrays with 2 different integers)
//and number of good subarrays
//amra subarrays take valid korchi jokhon subrarray te at most 2 to different integer ache..to amra kohonoi exact k ta different subarray er pabo na..peleo tate number of subrarray er
//count korte parbo na..karon amra window te pabo (<=k) ta different integer ache..ar subarray er count holo current window er j th element thek ith element obdhi..jth element take nie
//joto fulo subraay hoi seta(j-i+1) ..tate k er kom different integer er subarray o count hocche
//tai (<=k) different subarray count korchi cnt1 e
//ar (<=k-1) different subarray count korchi cnt2 te
//cnt1-cnt2 korle oi k er kom different integer subarray jegulo count hoichilo cnt1 e segulo badd hoi gie sudu exact k ta different integer nie je subarrays gulo thakbe segulo pabo
//overall tc=O(2n+2n)=o(4n)
//overall sc=O(k)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        int i=0;
        int j=0;
        int cnt1=0;
        int cnt2=0;
        //counting the number of subarrays where there is (<=k) different integers
        //tc=O(2n) because of there shrinking at most goes to O(n) and expanding at most goes to o(n)
        //sc=O(k) we at most store k different integer in the map
        while(j<n){
            freq[nums[j]]++;
            while(freq.size()>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            if(freq.size()<=k){
                cnt1+=(j-i)+1;
            }
            j++;
        }
        i=0;
        j=0;
        freq.clear();
        //counting the number of subarrays where there is (<=k-1) different integers
        //tc=O(2n) because of there shrinking at most goes to O(n) and expanding at most goes to o(n)
        //sc=O(k) we at most store k different integer in the map
        while(j<n){
            if(k-1==0){
                break;
            }
            freq[nums[j]]++;
            while(freq.size()>(k-1)){
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            if(freq.size()<=(k-1)){
                cnt2+=(j-i)+1;
            }
            j++;
        }
        return (cnt1-cnt2);
    }
};