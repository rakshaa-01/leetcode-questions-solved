class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size()+1, 0);
        for(auto& ch: nums) {
            v[ch]++;
        }
        int rep=-1, mis=-1;
        for(int i=1; i<v.size(); i++) {
            if(v[i]==2) rep=i;
            else if(v[i]==0) mis=i;
        }
        return {rep, mis};
    }
};