class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        uint8_t n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[n-1][m-1])
            return false;
        uint8_t raw_idx = 0, col_idx = 0;
        for (; matrix[raw_idx][m-1] < target; ++raw_idx) {}
        for (; matrix[raw_idx][col_idx] < target; ++col_idx) {}
        //cout << raw_idx << " " << col_idx << endl;
        return matrix[raw_idx][col_idx] == target;
    }
};
