class Solution {
public:
//pattern sliding window with constant size
//white ball take jodi blackball korte hoi thle otao black ball ei hobe..thle k holo window size
//protita window te whiteball count korte hobe die minimum ta return korte hobe
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int mini=0;
        int whitecount=0;
        for(int i=0;i<k;i++){
           if(blocks[i]=='W'){
            whitecount++;
           }
        }
        mini=whitecount;
        int l=0;
        int r=k-1;
        while(r<(n-1)){
            if(blocks[l]=='W'){
                whitecount--;
            }
            l++;
            r++;
            if(blocks[r]=='W'){
                whitecount++;
            }
            mini=min(whitecount,mini);
        }
        return mini;
    }
};