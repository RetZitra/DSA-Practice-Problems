class Solution {
public:
//tc=logn
    bool isPowerOfTwo(int n) {
    while(n>1){
        //if it is divisible by 2 we devide it by 2 else we break
        if(n%2!=0){
            break;
        }
        n/=2;
    }
    if(n==1){
        return true;
    }
    return false;
    }
};