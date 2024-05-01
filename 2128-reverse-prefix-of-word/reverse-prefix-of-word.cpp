class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        int i;
        for(i=0;i<n;i++){
            if(word[i]==ch){
                break;
            }
        }
        //jodi khuje na pai character ta oi word e thle word ta jamon ache tamon return korbo
        if(i>=n){
            return word;
        }
        string ans;
        int j=i+1;
        //jodi khuje pai to thle jekhane oi char ta khuje pelam sehan theke index 0 obdhi ekta ekta kore char ans e dhokabo
        while(i>=0){
            ans+=word[i];
            i--;
        }
        //trpr jekhane oi char ta khuje peye chilam tar por theke baki char gulo ans e dhokabo
        while(j<n){
            ans+=word[j];
            j++;
        }
        return ans;
    }
};