class Solution {
public:
//equal question of maximum lenght of subarray whos sum is equal to k
    int equalSubstring(string s, string t, int maxCost) {
        int maxi=0;
        int l=0;
        int r=0;
        int diff=0;
        int n=s.size();
        while(r<n){
            diff+=abs(s[r]-t[r]);
            if(diff>maxCost){
                diff-=abs(s[l]-t[l]);
                l++;
            }
            maxi=max(maxi,((r-l)+1));
            r++;
        }
        return maxi;
    }
};