class Solution {
public:
//i ta 1 theke start korchi every second e next pelow te jacche ar time ta komche
//jodi nth pellow te jai to abr process ta ulto hocche mne nth position theke 1th position e asche
//ei forward ar backward move hotei thakche jotokhon na time ta sesh hoi
//time ta sesh hoi gele jei position e asche pillow ta sei position ta return korchi
    int passThePillow(int n, int time) {
        int i=1;
        while(time>0){
            if(i==1){
                while(time>0 && i<n){
                   i++;
                   time--;
                }
            }
            if(i==n){
               while(time>0 && i>1){
                time--;
                i--;
               }
            }
        }
        return i;
    }
};