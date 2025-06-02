class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp_mag;
        unordered_map<char, int> mp_ran;
        for(auto& ch: magazine) {
            mp_mag[ch]++;
        }
        for(auto& ch: ransomNote) {
            mp_ran[ch]++;
        }
        for(auto& ch: ransomNote) {
            if(mp_mag[ch]>=mp_ran[ch]) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};