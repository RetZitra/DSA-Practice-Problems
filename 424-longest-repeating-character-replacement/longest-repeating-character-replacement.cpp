class Solution {
public:
//amk boleche ekta subrarray er moddhe ektai character repeat hobe..jodi onno character thake thle setake k bar flip korte parbo
//to longest subarray pabo jodi ami current subarray te maximum bar je character ache seta bade onno character guloke flip kori
    int characterReplacement(string s, int k) {
        // int n=s.size();
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int>freq;
        //     int maxfreq=0;
        //     for(int j=i;j<n;j++){
        //         freq[s[j]]++;
        //         //to ekta subarray te maxumum je character ta ache seta track korchi
        //         //map e last element ta dhukie ekta variable e jamon max count kori temon bhabe..map ta last update hobar por
        //         //tar moddhe je frequency ta max seta track korchi
        //         maxfreq=max(maxfreq,freq[s[j]]);
        //         int length=(j-i)+1;
        //         //ekta subarray valid hobe na jokhon maximum character chara tate onno character k er cheye beashi thake
        //         //onno character bar korbo (current length of the subarray-maximum occuring character)
        //         if(length-maxfreq>k){
        //             break;
        //         }
        //         //valid hole tar maximum length count korbo
        //         maxi=max(maxi,length);
        //     }
        // }
        // return maxi;
        //better version sliding window
        // int n=s.size();
        // int i=0;
        // int j=0;
        // unordered_map<char,int>freq;
        // int maxfreq=0;
        // int maxi=0;
        // while(j<n){
        //     freq[s[j]]++;
        //     maxfreq=max(maxfreq,freq[s[j]]);
        //     //if the window is not valid make it valid
        //     while((j-i+1)-maxfreq>k){
        //         freq[s[i]]--;
        //         //always check maxfreq after updating map
        //         maxfreq=max(maxfreq,freq[s[i]]);
        //         i++;
        //     }
        //     int length=(j-i)+1;
        //     maxi=max(length,maxi);
        //     j++;
        // }
        // return maxi;
        //optimized version for sliding window
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int>freq;
        int maxfreq=0;
        int maxi=0;
        while(j<n){
            freq[s[j]]++;
            maxfreq=max(maxfreq,freq[s[j]]);
            //if the window is not valid keep the current largest window and move forward it to one step just shrinking i once
            if((j-i+1)-maxfreq>k){
                freq[s[i]]--;
                //always check maxfreq after updating map
                maxfreq=max(maxfreq,freq[s[i]]);
                i++;
            }
            int length=(j-i)+1;
            maxi=max(length,maxi);
            j++;
        }
        return maxi;
    }
};