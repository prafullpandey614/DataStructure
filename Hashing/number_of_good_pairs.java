class Solution {
    public int numIdenticalPairs(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (mp.containsKey(nums[i])) {
                mp.put(nums[i], mp.get(nums[i]) + 1);
            } else {
                mp.put(nums[i], 1);
            }
        }
        int result = 0;

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int value = entry.getValue();
            result += value * (value - 1) / 2;
        }
        return result;

    }
}
