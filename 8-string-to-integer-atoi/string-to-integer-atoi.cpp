class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int n = s.size();
        long long ans=0;
        int i=0;
        cout<<n<<endl;
        //skip the white space
        while(i<n && s[i]==' '){
            i++;
        }
        //take first sign
        if(i<n){
            if(s[i]=='-'){
                sign=-1;
                i++;
            }
            else if(s[i]=='+'){
                i++;
            }
        }
        while (i < n) {
            if(!isdigit(s[i])){
                break;
            }
            if (isdigit(s[i])) {
                int digit = s[i] - '0';
                ans=ans*10+digit;
            }
            if(sign*ans>INT_MAX){
                return INT_MAX;
            }
            if(sign*ans<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        ans=sign*ans;
        return ((int)ans);
    }
};