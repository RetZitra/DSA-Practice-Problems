class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        //jodi word er lenght 3 er cheye kom hoi to valid noi
        if(n<3){
            return false;
        }
        int vcnt=0;
        int ccnt=0;
        int i;
        for(i=0;i<n;i++){
            //jodi kono special character pai thle break hoi jabe..ar sesh e jodi i puro loop complete parte na pare to valid noi
            if(isalpha(word[i]) || isdigit(word[i])){
                if(isalpha(word[i])){
                    //jodi character ta alphabet hoi thle vowel consonant er count check hocche
                    if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U'){
                        vcnt++;
                    }
                    else{
                        ccnt++;
                    }
                }
            }
            else{
                break;
            }
        }
        //jodi kono special character na thake and vowel atleast 1 ta ar consonent atleast 1 ta thake to valid
        if(i>=n && vcnt>=1 && ccnt>=1){
            return true;
        }
        return false;
    }
};