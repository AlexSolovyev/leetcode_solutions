class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target == 0)
            return {{}};
        sort(candidates.begin(), candidates.end());
        vector <vector < vector <int>>> dp(target + 1);
        for (size_t i = 1; i != dp.size(); ++i)
            for (size_t j = 0; j != candidates.size() && candidates[j] <= i; ++j)
                if (i == candidates[j])
                    dp[i].push_back({{candidates[j]}});
                else
                    for (auto comb : dp[i - candidates[j]])
                        if (candidates[j] <= comb[0]) {
                            dp[i].push_back({{candidates[j]}});
                            for (auto elem : comb)
                                dp[i][dp[i].size() - 1].push_back(elem);
                        }
        return dp[target];
    }
};

