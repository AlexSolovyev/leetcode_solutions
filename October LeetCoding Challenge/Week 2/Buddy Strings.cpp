class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        if (A.size() < 2)
            return false;
        vector <uint32_t> idxs;
        for (size_t i = 0; i != A.size(); ++i) {
            if (A[i] != B[i]) {
                idxs.push_back(i);
                if (idxs.size() > 2)
                    return false;
            }
        }
        if (idxs.size() == 1)
            return false;
        if (idxs.size() == 2)
            return A[idxs[0]] == B[idxs[1]] && A[idxs[1]] == B[idxs[0]];
        vector <uint32_t> freqs(26, 0);
        for (size_t i = 0; i != A.size(); ++i) {
            ++freqs[A[i] - 'a'];
            if (freqs[A[i] - 'a'] > 1)
                return true;
        }
        return false;
    }
};
