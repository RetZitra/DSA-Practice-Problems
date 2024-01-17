class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>occur;
        for(auto it=mp.begin();it!=mp.end();it++){
            occur.push_back(it->second);
        }
        sort(occur.begin(),occur.end());
        int i;
        for(i=0;i<(occur.size())-1;i++){
            if(occur[i]==occur[i+1]){
                break;
            }
        }
        if(i==(occur.size())-1){
            return true;
        }
        else{
            return false;
        }

    }
};