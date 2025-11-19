class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxEl=*max_element(nums.begin(), nums.end());
        int i=-1;
        int g=0;
        for(auto& c: nums) {
            if(c==maxEl) {
                i=g;
            }
            else if(c*2>maxEl) return -1;
            g++;
        }
        return i;
    }
};