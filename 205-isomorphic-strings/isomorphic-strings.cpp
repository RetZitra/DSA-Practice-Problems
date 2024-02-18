class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        map<pair<char,int>,int>freq;
        map<char,char>m;      
        for(int i=0;i<n1;i++){
        //    m[s[i]]=t[i];
           freq[{s[i],1}]++;
           freq[{t[i],2}]++;
        }
        for(int i=0;i<n1;i++){
            auto it1=freq.find({s[i],1});
            auto it2=freq.find({t[i],2});
            if(it1->second==it2->second){
                m[s[i]]=t[i];
            }
            else{
                m[s[i]]=s[i];
            }
        }
        for(int i=0;i<n1;i++){
            auto it=m.find(s[i]);;
            s[i]=it->second;
        }
        int i;        
        for(i=0;i<n1;i++){
            if(s[i]!=t[i]){
                break;
            }
        }
        if(i>=n1){
            return true;
        }
        else{        
            return false;
        }      
    }
};