class Solution {
public:
    int countCollisions(string directions) {
        int cnt=0;
        for(auto& d: directions) {
            if(d!='L') break;
            else cnt++;
        }
        string s1=directions;
        reverse(s1.begin(), s1.end());
        int cnt1=0;
        for(auto& d: s1) {
            if(d!='R') break;
            else cnt1++;
        }
        int ans=0;
        for(auto& v: directions) {
            if(v!='S') ans++;
        }
        return ans-cnt-cnt1;
    }
};