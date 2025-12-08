class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& c: nums) mp[c]++;
        if(mp.size()<=2) return 0;
        
        int prod=1;
        for(auto& p: mp) {
            prod*=p.second;
        }
        return prod;
    }
};