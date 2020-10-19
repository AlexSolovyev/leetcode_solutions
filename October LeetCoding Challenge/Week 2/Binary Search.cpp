class Solution {
public:
    int search(vector<int>& nums, int target) {
        uint16_t l = 0, r = nums.size() - 1, cur;
        while (r - l > 1) {
            cur = (r + l) / 2;
            if (nums[cur] == target)
                return cur;
            else if (nums[cur] < target)
                l = cur;
            else
                r = cur;
        }
        if (nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;
        return -1;
    }
};
