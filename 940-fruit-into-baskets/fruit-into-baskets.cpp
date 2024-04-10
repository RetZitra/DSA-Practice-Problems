class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int n=fruits.size();
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     set<int>st;
        //     for(int j=i;j<n;j++){
        //         st.insert(fruits[j]);
        //         if(st.size()<=2){
        //             int length=(j-i)+1;
        //             maxi=max(length,maxi);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxi;
        //o(n+n) because shrinking of i max goes to n and r will always goes to n
        //better solution
        // int n=fruits.size();
        // int i=0;
        // int j=0;
        // unordered_map<int,int>freq;
        // int maxi=0;
        // while(j<n){
        //     freq[fruits[j]]++;
        //         while(freq.size()>2){
        //             freq[fruits[i]]--;
        //             if(freq[fruits[i]]==0){
        //                 freq.erase(fruits[i]);
        //             }
        //             i++;
        //         }
        //     if(freq.size()<=2){
        //     int length=(j-i)+1;
        //     maxi=max(length,maxi);
        //     }
        //     j++;
        // }
        // return maxi;
        //optimal solution
        //after finding a maximum valid window we dont reduce it's size we just taking the length size and move one step foward to the window to find maximum possible answer
        //so we shrink the sliding window in 1 step at most so i will move at max 1 so the tc will depend only j pointer which is moved to n..so tc=0(n)
        //tc=0(n)
        int n=fruits.size();
        int i=0;
        int j=0;
        unordered_map<int,int>freq;
        int maxi=0;
        while(j<n){
            freq[fruits[j]]++;
                if(freq.size()>2){
                    freq[fruits[i]]--;
                    if(freq[fruits[i]]==0){
                        freq.erase(fruits[i]);
                    }
                    i++;
                }
            if(freq.size()<=2){
            int length=(j-i)+1;
            maxi=max(length,maxi);
            }
            j++;
        }
        return maxi;

    }
};