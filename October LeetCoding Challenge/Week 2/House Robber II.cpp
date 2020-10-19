class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if (n < 4)
            return *max_element(nums.begin(), nums.end());
        vector <int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        dp[2] = max(dp[1], dp[0] + nums[2]);
        for (size_t i = 3; i != n; ++i)
            dp[i] = max(dp[i-1], nums[i] + max(dp[i-2], dp[i-3]));
        ans = dp[n - 2];
        if (dp[n - 1] < ans)
            return ans;
        dp[0] = 0;
        dp[1] = nums[1];
        dp[2] = max(dp[1], nums[2]);
        for (size_t i = 3; i != n; ++i)
            dp[i] = max(dp[i-1], nums[i] + max(dp[i-2], dp[i-3]));
        return max(ans, dp[n - 1]);
    }
};
