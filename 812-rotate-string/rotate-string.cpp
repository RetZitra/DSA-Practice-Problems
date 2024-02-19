class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++){
            string ans="";
            int j=i+1;
            if(j<n){
               ans+=s.substr(j,(n-j));
            }
            ans+=s.substr(0,((i+1)-0));
            cout<<ans<<endl;
            if(ans==goal){
                return true;
            }
        }
        return false;
    }
};