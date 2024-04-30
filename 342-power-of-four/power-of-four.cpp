class Solution {
public:
    bool isPowerOfFour(int n) {
        //tc=logn
        //similer as power of 2
        while(n>1){
            //if it is divisible by 4 we devide it by 4..
            if(n%4!=0){
                break;
            }
            n=n/4;
        }
        //if it is divisible by 4 then at last the number comes to 1 by repetatedly devided it by 4
        //so if it is comes to 1 means the number is power of 4
        //else it is not power of 4
        if(n==1){
            return true;
        }
        return false;
    }
};