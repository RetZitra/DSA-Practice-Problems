class Solution {
public:
//classic sliding window problem with constant size window
    int maxVowels(string s, int k) {
        int n=s.size();
        int vowelcount=0;
        int maxi=0;
        //first taking the k size sliding window..and counting its number of vowels
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vowelcount++;
            }
        }
        //assigning the left and right pointer after taking k size window
        int l=0;
        int r=k-1;
        //maxi is at this point the number of vowelcount found in first k size window
        maxi=vowelcount;
        //classic sliding window..moving the window till the end with size k and each time calculating its number of vowles
        while(r<(n-1)){
            if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'){
                vowelcount--;
            }
            l++;
            r++;
            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u'){
                vowelcount++;
            }
            //storing the max vowelcount of all possible window of size k
            maxi=max(vowelcount,maxi);
        }
        return maxi;

    }
};