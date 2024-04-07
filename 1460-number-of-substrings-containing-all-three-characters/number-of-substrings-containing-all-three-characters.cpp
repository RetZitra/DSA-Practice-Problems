class Solution {
        // int n=s.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int>mp;
        //     for(int j=i;j<n;j++){
        //         mp[s[j]]++;
        //         //brute force
        //         //tc=o(n^2)
        //         //sc=o(n)
        //         //generate all substring
        //         //age 3 te character subarray te find kore nicche die jokon sobgulo peye jacche tokhon count++ koche
        //         if((mp.find('a')!=mp.end()) && (mp.find('b')!=mp.end()) && (mp.find('c')!=mp.end()) && (mp['a']>=1) && (mp['b']>=1) && (mp['c']>=1)){
        //             count++;
        //         }
        //     }
        // }
        // return count;
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while((mp.find('a')!=mp.end()) && (mp.find('b')!=mp.end()) && (mp.find('c')!=mp.end()) && (mp['a']>=1) && (mp['b']>=1) && (mp['c']>=1)){
                count+=(n-j);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};