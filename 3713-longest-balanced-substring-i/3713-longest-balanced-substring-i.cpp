class Solution {
public:
    bool solve(unordered_map<char, int> &mp) {
        int mini=INT_MAX, maxi=0;
        for(auto& p: mp) {
            mini=min(mini, p.second);
            maxi=max(maxi, p.second);
        }
        return mini==maxi;
    }
    int longestBalanced(string s) {
        unordered_map<char, int> mp;
        int ans=0;
        for(int i=0; i<s.size(); i++) {
            unordered_map<char, int> mp;
            for(int j=i; j<s.size(); j++) {
                mp[s[j]]++;
                if(solve(mp)) {
                    ans=max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};