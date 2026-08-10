class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] score = new int[2];

        for(int i = 0; i<nums.length; i++)
        {
            for(int j = i + 1; j<nums.length; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    score[0] = i;
                    score[1] = j;
                    return score;
                }
                
            }
        }
          return new int[0];
    }

}