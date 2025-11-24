class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[]ans=new int[2];
        //by using map
        Map<Integer,Integer>mp=new HashMap<>();
        //storing number and index
        for(int i=0;i<nums.length;i++){
            //check if (target-nums[i]) present or not if present then the answer is current number and that numbers index
            if(mp.containsKey(target-nums[i])){
                //(t-nums[i] number index)
                ans[0]=mp.get(target-nums[i]);
                ans[1]=i;
                return ans;
            }
            //each number er last occurance ta store korbo
            mp.put(nums[i],i);
        }
        //ekhane kokhono asbe na eta just sesh e return korte hoi bole kora
        return ans;
    }
}