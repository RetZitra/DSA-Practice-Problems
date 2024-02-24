class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int parcount=0;
        int prevparcount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                prevparcount=parcount;
                parcount++;
            }
            else{
                prevparcount=parcount;
                parcount--;
            }
            if((parcount>0)&&(prevparcount!=0)){
                ans+=s[i];
            }
        }
        return ans;
    }
};