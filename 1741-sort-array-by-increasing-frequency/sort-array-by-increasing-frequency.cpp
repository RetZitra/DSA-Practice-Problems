class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<=100;i++){
            for(auto it=freq.rbegin();it!=freq.rend();it++){
                if(it->second==i){
                    ans.insert(ans.end(),i,it->first);
                }
            }
        }
        return ans;
    }
};