class Solution {
public:
    bool isAnagram(string s, string t) {
        map<pair<char,int>,int>freq;
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2){
            return false;
        }
        for(int i=0;i<n1;i++){
            freq[{s[i],1}]++;
            freq[{t[i],2}]++;
        }
        for(int i=0;i<n1;i++){
            if(freq.find({s[i],2})!=freq.end()){
                auto it1=freq.find({s[i],1});
                auto it2=freq.find({s[i],2});
                if(it1->second!=it2->second){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};