import java.util.Arrays;

class Solution {
    static final int MOD = (int) (1e9 + 7);
    int[][] dp;

    public int numberOfGoodSubarraySplits(int[] nums) {
        dp = new int[nums.length][2];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return solve(0, nums, 0) % MOD;
    }

    private int solve(int ind, int[] nums, int contains) {
        if (ind == nums.length)
            return 0;
        if (dp[ind][contains] != -1)
            return dp[ind][contains];
        if (contains != 0) {
            if (nums[ind] == 1)
                return dp[ind][contains] = solve(ind + 1, nums, 1) % MOD;
            else
                return dp[ind][contains] = (solve(ind + 1, nums, 0) + solve(ind + 1, nums, 1)) % MOD;
        } else {
            if (nums[ind] == 1)
                return dp[ind][contains] = (1 + solve(ind + 1, nums, 1)) % MOD;
            else
                return dp[ind][contains] = solve(ind + 1, nums, 0) % MOD;
        }
    }
}
