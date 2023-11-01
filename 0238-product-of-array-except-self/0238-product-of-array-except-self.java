class Solution {
    public int[] productExceptSelf(int[] nums) {
        int pro=1;
        int n = nums.length;
        int[] result = new int[n];
        int product = 1;
        int count = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                count++;
            }
        }
        if (count == 0) {
            for (int i = 0; i < nums.length; i++) {
                pro *= nums[i];
            }
            for (int i = 0; i < nums.length; i++) {
                nums[i]= (pro / nums[i]);
            }
        } else if (count == 1) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != 0) {
                    pro *= nums[i];
                }
            }
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == 0) {
                    nums[i] = (pro);
                } else {
                    nums[i] = 0;
                }
            }
        } else {
            for (int i = 0; i < nums.length; i++) {
                nums[i]= 0;
            }
        }
        return nums;
    }
}