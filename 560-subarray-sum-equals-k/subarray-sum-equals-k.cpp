class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefixsum=0;
        int count=0;
        mp.insert({0,1});
        for(int i=0;i<n;i++){
           prefixsum+=nums[i];
           int remaining=prefixsum-k;
           //jodi reamining ta khuje pai thle oi index er jonno remaining ta koto bar ache..thle oi index er moddhe toto kota k ache
           if(mp.find(remaining)!=mp.end()){
             count+=mp[remaining];
           }
           //prefix sum ta koto bar pelo seta add kore nicchi ..pore jate seta karur (s-k) hoi thle khujte subidha hoi
           mp[prefixsum]++;
        }
        return count;
    }
};