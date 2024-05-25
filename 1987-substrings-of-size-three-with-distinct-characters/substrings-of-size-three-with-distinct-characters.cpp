class Solution {
public:
//classic sliding window pattern
//ekta substring e joto gulo character ache tader occurence 1 hobe
//ek ek ta 3 size er subsring er map e occurence count kochi..jodi map e amon kono element thake jar 
//frequency 0 thle ota ar map er rekhe kaj nei..ar frequency kome 0 hobe jokhon amra shrink korbo
//to shrinking er time e dekhe nicchi je jodi kono khetre frequency 0 hoi jai kono element er thle map theke ota delete korbo
//ebabe constant size er window te jodi kono substring er map er size 3 hoi exact thle seta valid
//karon map e key unique so 3 te element map e thaka mane tara dintinct ba unique
//tc=O(n)
//sc=O(n)
    int countGoodSubstrings(string s) {
        unordered_map<char,int>mp;
        int cnt=0;
        int n=s.size();
        int l=0;
        int r=0;
        while(r<=2){
            mp[s[r]]++;
            r++;
        }
        if(mp.size()==3){
            cnt++;
        }
        while(r<n){
            mp[s[r]]++;
            r++;
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
            if(mp.size()==3){
                cnt++;
            }
        }
        return cnt;
    }
};