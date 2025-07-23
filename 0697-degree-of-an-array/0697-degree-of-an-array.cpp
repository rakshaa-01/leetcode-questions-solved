class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int g=0;
        for(auto& ch: nums) {
            mp[ch].push_back(g++);
        }
       int deg=0;
       for(auto& [key, val]: mp) {
        int sz=val.size();
            deg = max(deg, sz);
       }
       int mini=INT_MAX;
       for(auto& [key, val]: mp) {
            if(val.size()<deg) continue;
            mini=min(mini, val[val.size()-1]-val[0]+1);
       }
       return mini;
    }
};