class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& ch: nums) {
            mp[ch]++;
        }
        int maxi=-1;
        for(auto& ch: mp) {
            if(ch.second>maxi) {
                maxi=ch.second;
            }
        }
        int cnt=0;
        for(auto& ch: mp) {
            if(ch.second==maxi) cnt+=ch.second;
        }
        return cnt;
    }
};