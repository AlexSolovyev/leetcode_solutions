class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
            return 0;
        sort(points.begin(), points.end(), myCmp);
        int num = 1, cur_pos = points[0][1];
        for (size_t i = 1; i != points.size(); ++i) {
            if (points[i][0] > cur_pos) {
                ++num;
                cur_pos = points[i][1];
            }
        }
        return num;
    }

    static bool myCmp(vector<int>& x, vector<int>& y){
        return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1];
    }
};
