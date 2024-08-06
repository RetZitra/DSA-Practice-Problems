//approach:amk boleche word er moddhe each character gulo ke type korte koto bar push korte hobe
//given condition holo je 2-9  8 ta switch ache 
//ekta switch er moddhe jara first e thakbe tader 1 bar push korte hobe,2nd e thakle 2bar ,3rd e thakle 3 bar erom
//so jodi 8 ba 8 er cheye kom unique character thake to amra oi character gulo ke each switch e 1st position e rakhbo jate 1 bar push korte hoi
//9-16th unique character gulo ke 2rd bar push korte hobe each switch er 2rd position e rakhte hobe
//17-24th unique character gulo ke 3rd bar push korte hobe each switch er 3rd position e rakhte hobe
//25-26th unique character gulo ke 4rd bar push korte hobe each switch er 4rd position e rakhte hobe
//so amra swich gulo te character gulo ke position korbo erom bhabe je je character joto beshi ache tader amra age place korbo each switch jate kore jei character gulo beshi ache
//tader kom bar push korte hoi overall sum kom hoi
//ar ekta character jotobar ache toto bar amk tipte hobe to oi character ta jonno total push =(switch er position*frequency)
//sob push gulo ke addition kore result bar korbo
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