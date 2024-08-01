class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        int n=details.size();
        //traverse each persons details
        for(int i=0;i<n;i++){
            //for each person details taking there age
            int age=0;
            int j=11;
            for(int k=0;k<2;k++){
                int digit=details[i][j]-'0';
                age=age*10+digit;
                j++;
            }
            //counting the the people whos age is strictly greater than 60
            if(age>60){
                ans++;
            }
        }
        return ans;
    }
};