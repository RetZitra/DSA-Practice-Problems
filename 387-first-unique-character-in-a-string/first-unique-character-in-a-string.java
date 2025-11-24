class Solution {
    public int firstUniqChar(String s) {
        //initially ans is -1..if there is no element non-repeating
        int ans=-1;
        //we can create a frequency array of each character and then again traverse the string from the front 
        // and then check if the character's frequency is unique if it is then return the first character
        // 0-25 total 26 alphabet's character
        int[]freq=new int[26];
        for(int i=0;i<s.length();i++){
            //oi character er respictive 0-25 index value peye jabo..uppercase hole -'A' hoto
            int index=s.charAt(i)-'a';
            //index array te oi character er frequency 1 baralam
            freq[index]++;
        }
        //after that traverse the string from front and check the first character that have frequency 1
        for(int i=0;i<s.length();i++){
            int index=s.charAt(i)-'a';
            //store that char's index in ans
            if(freq[index]==1){
                ans=i;
                return ans;
            }
        }
        return ans;
    }
}