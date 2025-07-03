class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        // 1) turn shifts into suffix‐sum modulo 26
        long long acc = 0;
        for (int i = n - 1; i >= 0; --i) {
            acc = (acc + shifts[i]) % 26;
            shifts[i] = acc;                   // now shifts[i] is totalShift[i]
        }
        // 2) apply each shift exactly once
        for (int i = 0; i < n; ++i) {
            int original = s[i] - 'a';
            int shifted  = (original + shifts[i]) % 26;
            s[i] = char('a' + shifted);
        }
        return s;
    }
};
