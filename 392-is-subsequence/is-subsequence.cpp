class Solution {
public:
//approach:
//s string ta choto seta t er subsequence kina seta check korte boleche to s ar t string e 2 to pointer lagachi jodi s er ekta char er sathe t er ekta char match kore to
//s er pointer take egochi..ebhabe t er protita charecter er jonno check korchi..jodi s string ta traverse complete hoi jai thle s er protita character t string e sequence e ache
//tar mane oi s holo t er subsequence ar jodi boro string ta traverse sesh hoe geleo choto string ta traverse sesh na hoi mane holo je s er sob character t string e nei
//to subsequence noi
    bool isSubsequence(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        //edge case jodi 2 to null string dei to trao subsequence hobe
        if(n1==0 && n2==0){
            return true;
        }
        int i=0,j=0;
        for(j=0;j<n2;j++){
            if(i<n1){
                if(s[i]==t[j]){
                    i++;
                }
            }
            //if small string complete it traverse it means that it is a subsequence of string 
            if(i>=n1){
                return true;
            }
        }
        return false;
    }
};