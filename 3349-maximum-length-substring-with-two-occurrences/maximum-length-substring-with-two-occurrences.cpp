class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int>freq;
        int n=s.size();
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        while(j<n){
            freq[s[j]]++;
            //if it is not a valid subarray that means any character occurs more than 2 times than i till shorten the subarray by moving front pointer
            //one by one and delete its occurence..for searching the next subarray in which a character occur less or equal to 2
               while(freq[s[j]]>2){
                freq[s[i]]--;
                i++;
               }
            //if it is valid subarray then i will increase j to greedly get largest valid subarray and take the largest length of the valid subarray
            int length=(j-i)+1;
            maxi=max(length,maxi);
            j++;
        }
        return maxi;
    }
};