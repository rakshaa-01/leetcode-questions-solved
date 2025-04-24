class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        int distinct=s.size();
        s.clear();
        int res=0;

        for(int i=0; i<nums.size(); i++) {
            s.clear();
            for(int j=i; j<nums.size(); j++) {
                s.insert(nums[j]);
                if(s.size()==distinct) res++;
            }
        }
        return res;
    }
};