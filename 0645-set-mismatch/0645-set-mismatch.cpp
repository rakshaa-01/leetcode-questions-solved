class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        //Find duplicate
        unordered_set<int> s;
        for(auto& n: nums) {
            if(s.count(n)) {
                ans.push_back(n);
                break;
            }
            s.insert(n);
        }

        //Find the missing
        int n=1;
        for(auto& ch: nums) {
            if(n!=ch) {
                ans.push_back(n);
                break;
            }
            n++;
        }
        return ans;
    }
};