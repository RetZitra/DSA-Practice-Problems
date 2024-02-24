class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int parcount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                parcount++;
            }
            else if(s[i]==')'){
                parcount--;
            }
            maxdepth=max(maxdepth,parcount);
        }
        return maxdepth;
    }
};