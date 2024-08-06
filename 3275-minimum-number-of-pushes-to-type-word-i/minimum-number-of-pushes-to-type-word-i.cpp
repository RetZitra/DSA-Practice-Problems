//same question as 3015. Minimum Number of Pushes to Type Word II just constrains is small, word size is small so typed same code as version 2 of the problem
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>freq(26,0);
        long long ans=0;
        //taking frequency of each character
        for(int i=0;i<n;i++){
            int index=word[i]-'a';
            freq[index]++;
        }
        //sort the frequency of character in desending order so that we mapped maximum occurence character from first to fourth position of each switch
        sort(freq.begin(),freq.end(),[](int a,int b){
            return a>b;
        });
        for(int i=0;i<26;i++){
            //if there is no more word return current total minimum pushes
            if(freq[i]==0){
                return ans;
            }
            else{
                //0 based indexing so counting is 1 less
                //first 1-8 character according to maximum frequency placed frist position of each switch
                if(i>=0 && i<=7){
                  ans+=freq[i]*1;
                }
                //second 9-16 character according to maximum frequency placed second position of each switch
                else if(i>7 && i<=15){
                    ans+=freq[i]*2;
                }
                //third 17-24 character according to maximum frequency placed third position of each switch
                else if(i>15 && i<=23){
                    ans+=freq[i]*3;
                }
                //fourth 25-26 character according to maximum frequency placed fourth position of each switch
                else{
                    ans+=freq[i]*4;
                }
                }
        }
        return ans;
    }
};