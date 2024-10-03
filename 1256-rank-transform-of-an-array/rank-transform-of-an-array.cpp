class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //at first put the element in the sorted map
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=-1;
        }
        //then treverse the sorted map and put it's rank by taking a cnt variable
        int cnt=1;
        //& it korte hobe nahole original map e change hobe na sudhu it mane copy tai reference die korte hobe
        for(auto &it:mp){
            it.second=cnt;
            cnt++;
        }
        //then traverse the array again and find each element in the map and put it's rank
        vector<int>ans;
        for(int i=0;i<n;i++){
            //put each element rank's stored in the map
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};