class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = intervals.size();
        if (res == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        vector <bool> deleted(intervals.size(), false);
        //for (size_t i = 0; i != intervals.size(); ++i)
        //    cout << intervals[i][0] << " " << intervals[i][1] << endl;
        for (size_t i = 0; i != intervals.size() - 1; ++i) {
            if (intervals[i][0] == intervals[i+1][0]) {
                deleted[i] = true;
                --res;
                continue;
            }
            if (deleted[i])
                continue;
            for (size_t j = i + 1; j != intervals.size(); ++j) {
                if (deleted[j])
                    continue;
                if (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    --res;
                    deleted[i] = true;
                }
                if (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]) {
                    --res;
                    deleted[j] = true;
                }
            }
        }
        //for (auto elem : deleted)
        //    cout << elem << " ";
        return res;
    }
};
