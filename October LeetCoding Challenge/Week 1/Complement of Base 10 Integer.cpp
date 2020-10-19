class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        cout << (N | ~N);
        return (N | ~N) - N;
    }
};

