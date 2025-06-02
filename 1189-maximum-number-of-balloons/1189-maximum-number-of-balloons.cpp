class Solution {
public:
    int maxNumberOfBalloons(string s) {
        string target="balloon";
        if(target.length()>s.length()) {
            return 0;
        }

        unordered_map<char, int> mp_s, mp_target;
        
        for(auto& ch: s) {
            mp_s[ch]++;
        }
        for(auto& ch: target) {
            mp_target[ch]++;
        }
        int ans=INT_MAX;
        for(auto& ch: target) {
            if(mp_s[ch]==0) return 0;
            ans=min(ans, mp_s[ch]/mp_target[ch]);
        }
        return ans;
    }
};