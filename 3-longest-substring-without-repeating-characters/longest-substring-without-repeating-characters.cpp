class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        //edge case
        if(n==0){
            return n;
        }
        unordered_map<char,int>freq;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        while(j<n){
            //take the current frequency of last entered element in the subarray
            freq[s[j]]++;
            //if a element's frequency is greater than 1 then reduce the subarray by increasing i
            //to make it valid one
            //the constraint is take the longest subarry in which one character present at most once
            while(freq[s[j]]>1){
               freq[s[i]]--;
               i++;
            }
            //if a subarray is valid take the longest length of the subarray
            int length=(j-i)+1;
            maxi=max(length,maxi);
            j++;
        }
        return maxi;
    }
};