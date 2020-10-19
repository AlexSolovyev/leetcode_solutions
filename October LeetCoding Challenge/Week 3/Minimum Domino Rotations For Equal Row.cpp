class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        uint16_t f_var = A[0], s_var = B[0], ansA1 = 0, ansA2 = 0, ansB1 = 0, ansB2 = 0, n = A.size();
        for (size_t i = 0; i != n; ++i) {
            if (A[i] != f_var && A[i] != s_var && B[i] != f_var && B[i] != s_var)
                return -1;
            f_var = (A[i] != f_var && B[i] != f_var) ? -1 : f_var;
            s_var = (A[i] != s_var && B[i] != s_var) ? -1 : s_var;
            ansA1 += A[i] == f_var;
            ansA2 += A[i] == s_var;
            ansB1 += B[i] == f_var;
            ansB2 += B[i] == s_var;
        }
        return min(n - max(ansA1, ansB1), n - max(ansA2, ansB2));
    }
};
