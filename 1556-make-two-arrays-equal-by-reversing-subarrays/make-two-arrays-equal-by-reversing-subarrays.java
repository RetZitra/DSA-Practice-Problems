//approach:Ekhane boleche jotogulo ichha jekono size er subarray reverse operation korte pari
//so amra ek ek ta number dhore dhore jekono size er subarray nie reverse kore sei number take nijer jaigai bosie dite pari
//so jodi 2to array te same number same frequency te thake,thle amra array ta target er equal korte pari
//jodi 2 to number same frequency te na thake thle array ta target array te convert kora jabe na
//2to array ke sort kore nebo die,jeheto array 2to equal size er 2to arrray ke traverse korte thakbo,2to array er element guloke check korte korte
//jodi element 2to same na hoi break kore jabo
//jodi array 2to traverse sesh kore thle true return korbo nahole false
class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        int n=target.length;
        Arrays.sort(target);
        Arrays.sort(arr);
        int i;
        for(i=0;i<n;i++){
            if(target[i]!=arr[i]){
                break;
            }
        }
        if(i>=n){
            return true;
        }
        return false;
    }
}