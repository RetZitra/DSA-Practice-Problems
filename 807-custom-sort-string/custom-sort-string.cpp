class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26,0);
        int n1=s.size();
        int n2=order.size();
        string ans;
        for(int i=0;i<n1;i++){
            int index=s[i]-'a';
            freq[index]++;
        }
        for(int i=0;i<n2;i++){
            int index=order[i]-'a';
            while(freq[index]!=0){
                ans+=order[i];
                freq[index]--;
            }
        }
        for(int i=0;i<n1;i++){
            int index=s[i]-'a';
            if(freq[index]!=0){
                ans+=s[i];
                freq[index]--;
            }
        }
        return ans;
    }
};