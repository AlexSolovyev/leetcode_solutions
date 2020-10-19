class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        if (nums.size() < 2)
            return res;
        unordered_map <int, int> freqs;
        for (size_t i = 0; i != nums.size(); ++i)
            ++freqs[nums[i] + k];

        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); ++i) {
            if ((k != 0 && freqs[nums[i]] > 0) || (k == 0 && freqs[nums[i]] > 1))
                ++res;
            while (i < nums.size() - 1 && nums[i] == nums[i+1])
                ++i;
        }
        return res;
    }
};

