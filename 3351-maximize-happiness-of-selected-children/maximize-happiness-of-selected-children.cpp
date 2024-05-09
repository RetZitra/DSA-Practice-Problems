class Solution {
public:
//apporach:amk k ta amon element select korte hobe jate array te je value gulo ache setar sum maximize hoi
//ar operations e bole dieche je ekta element nile onno element gulor value 1 kore kombe.. kintu negetive jabe na..negetive gele seta 0 dhorte pari
//to maximum sum hobe jodi ami array er maximum value er element theke students nite thaki..to sort kore greedly maximum theke sum bar korbo
//ar right side theke joto egabo toto onno element gulo 1 kore decrement hobe..to ekta variable nie nicchi jeta koto bar 1 kore decrement hobe seta count korche
//to i pointer ta next maximum value te asche die jotobar decrement korar value ta toto bar decrement korche(by 1)..jate negetive na hoi seta check korche..die setar sum korche..jotokhon na k ta student neoa jai
//amk inner loop use kore each element -1 korar dorkar nei ...amk dekhte hobe je next maximum element ke ..ar seta kotobar by 1 decrement hocche..thlei kaj sesh
//tai kotobar decrement hocche seta dekhar jonno ekta variable niechi
//tc:nlogn for sorting+n for traversing
//tc=O(nlogn+n)
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        int nums_tobe_decremented=0;
        sort(happiness.begin(),happiness.end());
        int i=n-1;
        long long ans=0;
        while(k>0){
           if((happiness[i]-nums_tobe_decremented)>0){
            ans+=(happiness[i]-nums_tobe_decremented);
           }
           i--;
           k--;
           nums_tobe_decremented++;
        }
        return ans;
    }
};