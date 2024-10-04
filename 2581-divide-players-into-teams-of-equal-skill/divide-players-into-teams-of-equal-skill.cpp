class Solution {
public:
//time complexity:for sorting(nlogn)+ for two-pointer traversal (n/2)
//so(nlogn+n/2) 
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        //jeta return korte boleche seta holo all possible pair er product er sum
        long long ans=0;
        //ekta array er 2 to kore pair nile sum same hobe jodi amra smallest,largest
        //second-smallest,second-largest erom kore pair nie
        //er baire sum equal hoa posssible noi
        //sort kore erom bhabe 2 pointer die first,second(largest,smallest) travese korte korte check korbo sum same kina
        long long sum=0;
        sort(skill.begin(),skill.end());
        //possible sum hobe sob pair er jonno sort korar por fist smallest element ar first largest element er sum
        //kono ekta pair er sum jodi ei sum er sathe match na kore to seta valid pair possible noi
        //always take first possible sum for check in loop
        sum+=(skill[0]+skill[n-1]);
        for(int i=0,j=n-1;i<j;i++,j--){
            //first and last element sum is not previous sum
            if(sum!=(skill[i]+skill[j])){
                return -1;
            }
            //if sum matches it previous keep updated ans variable accordingly
            ans+=(skill[i]*skill[j]);
        }
        return ans;
    }
};