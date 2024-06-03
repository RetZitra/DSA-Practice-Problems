class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int j=0;
        for(int i=0;i<n1;i++){
            if(s[i]==t[j]){
                j++;
            }
        }
        if(j>=n2){
          return 0;
        }
        return (n2-j);
    }
};