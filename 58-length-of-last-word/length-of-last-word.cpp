class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        //skip space from last
        int i=n-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        //count the number of character from last after skipping spaces until the next space comes
        //means these is the length of last word
        int count=0;
        //out of bound ta check korte hobe age trpr oi index take use kore string take access kore onno
        //condition likhte parbo
        //jodi agei string take access kore ni trpr outofbound kina check kori thle..jodi i=-1 hoi jai
        //to age string access korte gie runtime error khabe
        //testcase:"a"
        while(i>=0 && s[i]!=' '){
            count++;
            i--;
        }
        return count;
    }
};