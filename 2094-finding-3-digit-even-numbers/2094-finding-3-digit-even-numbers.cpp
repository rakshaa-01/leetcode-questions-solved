class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;
        for(auto& a: digits) {
            mp[a]++;
        }
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            if (mp[i] == 0) continue;
            mp[i]--;

            for (int j = 0; j <= 9; j++) {
                if (mp[j] == 0) continue;
                mp[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (mp[k] == 0) continue;
                    res.push_back(i*100 + j*10 + k);
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return res;
    }
};