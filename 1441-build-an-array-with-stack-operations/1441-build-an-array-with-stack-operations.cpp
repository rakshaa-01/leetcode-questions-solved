class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int g=0;
        for(int i=1; i<=n && g<target.size(); i++) {
            if(i==target[g]) {
                ans.push_back("Push");
                g++;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};