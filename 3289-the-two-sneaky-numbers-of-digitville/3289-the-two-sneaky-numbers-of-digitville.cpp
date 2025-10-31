class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& ch: nums) {
            mp[ch]++;
        }
        vector<int> v;
        for(auto& c: mp) {
            if(c.second>1) {
                v.push_back(c.first);
            }
        }
        return v;
    }
};