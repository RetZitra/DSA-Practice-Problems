class Solution {
public:
    bool checkPerfectNumber(int num) {
        //taking all the divisor of that number using squrt(n) time-complexity..excluding the number itself
        //while taking adding it 
        //if addison is same as the number then it is perfect number else it is not perfect number
        int sum=0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0 && i!=num){
               sum+=i;
               if(num/i!=i && num/i!=num){
                sum+=num/i;
               }
            }
        }
        if(sum==num){
            return true;
        }
        return false;
    }
};