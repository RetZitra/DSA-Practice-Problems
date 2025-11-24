class Solution {
    public boolean isAnagram(String s, String t) {
        // 2to string eke oporer anagram hole tader each character er occurence exactly same but permutation alada
        //so first string er frequency nebo frequency array te
        //2nd string er frequency oi frequency array theke bad debo 
        // jodi tara eke oporer anagram hoi thle er por 
        // frequency array e sob alphabet er frequency 0 hobe..mne 1st word 
        // and 2nd word bad dile kichui thakbe na
        int[]freq=new int[26];
        for(int i=0;i<s.length();i++){
            int index=s.charAt(i)-'a';
            freq[index]++;
        }
        for(int i=0;i<t.length();i++){
            int index=t.charAt(i)-'a';
            freq[index]--;
        }
        //jodi eta korar por ektao alphabet er frequency 0 er beshi hoi thle anagram noi
        for(int i=0;i<25;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        //loop e return na hole sobar frequency 0 so anagram
        return true;
    }
}