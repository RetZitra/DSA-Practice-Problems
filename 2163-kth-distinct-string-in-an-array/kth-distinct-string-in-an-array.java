class Solution {
    public String kthDistinct(String[] arr, int k) {
        int n=arr.length;
        String ans="";
        int cnt=0;
        Map<String, Integer> freq = new HashMap<>();
        //storing frequency of each element to check each distinct element in the string
        for(int i=0;i<n;i++){
            //if the element is  previously present in map then just increase it's frequency by 1
            if(freq.containsKey(arr[i])){
                freq.put(arr[i],freq.get(arr[i])+1);
            }
            //if the element is not previously present in map then just put it's key value, 1
            else{
                freq.put(arr[i],1);
            }
        }
        //traverse the string array and if it is distinct string (frequency 1) then counter is increased
        for(int i=0;i<n;i++){
            int occurence=freq.get(arr[i]);
            if(occurence==1){
                cnt++;
            }
            //if cnt==k means it is kth distinct element then return it
            if(cnt==k){
                return arr[i];
            }
        }
        //after traversing the map if not string is returned means there is no kth distinct element present in the map so return null string
        return ans;
    }
}