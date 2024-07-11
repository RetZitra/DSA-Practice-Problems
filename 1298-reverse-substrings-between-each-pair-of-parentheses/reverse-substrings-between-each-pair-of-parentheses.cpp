class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int start=st.top();
                int last=i+1;
                st.pop();
                reverse(s.begin()+start,s.begin()+last);
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
        }
        return ans;
    }
};