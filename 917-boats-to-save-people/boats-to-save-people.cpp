class Solution {
public:
//ekhane bole dieche je ekta boat e ekta people jete parbe for sure kintu boat number komanor jonno bole ..dieche
//je ekta boat e 2 to people o jete pare jodi tader weight<=limit hoi
//basically array take sort kore nebo die dekhbo je jeta maximum weight setar sathe jeta minimum weight seta eksathe
//jete pare kina jodi jeta maximum weight setar sathe jat minimum weight seta eksathe jete na pare..thhle oi
//minimum er theke beshi weight oviously jete parbe na thle sudhu oi maximum weight tai jabe ekta boat e
//two pointer approah use korchi ekhane
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int cnt=0;
        sort(people.begin(),people.end());
        int left=0,right=n-1;
        while(left<=right){
            //checking if a boat can take 2 people or not
            if(people[left]+people[right]<=limit){
                left++;
                right--;
            }
            //if a boat cant take two people then it take only one people
            else{
               right--;
            }
            //each iteration 1 boat required either it can hold 2 people or just one people
            cnt++;
        }
        return cnt;
    }
};