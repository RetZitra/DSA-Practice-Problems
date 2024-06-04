class Solution {
public:
//k is number of unique number in the string
//x=variable not fixed
//tc=O(n+k*x)
//sc=O(k)
    int longestPalindrome(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int>f;
        //storing frequency
        //tc=O(n)
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        //tc=O(k*some variable depends on the frequency)
        for(auto it=f.begin();it!=f.end();){
            int freq=it->second;
            //taking 2's pair of a same character as much as possible to making palindrom
            while(freq>1){
                ans+=2;
                //after taking 2 of them from a same character in the string the remaning of the same character is freq-2
                freq=freq-2;
            }
            //after taking 2 same character in one operation
            //then to take all those pairs(all possible operation performed) if the character is no more(frequency=0) then we can delete it's occurence from map
            //these means after taking all those valid pairs the map only contains the unique character which frequency is 1
            //it = f.erase(it); updates it to this returned iterator, ensuring the loop can continue correctly.
            if (freq == 0) {
                it = f.erase(it);
            } else {
                ++it;
            }
        }
        //after taking maximum possible character of in pairs of 2.. if there exist one or more charecter
        //who's frequency is 1 then we can also take once of it in our palindrom string...to maximize the length of the string
        //because in a palindrom string maximum 1 character can present who's frequency is 1
        if(f.size()>0){
            ans++;
        }
        return ans;
    }
};