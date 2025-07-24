class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mapSum;
        int sum = 0, ans = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int temp = sum%k;
            if(temp==0)ans++;
            if(temp<0)temp+=k;
            if(mapSum.find(temp)!=mapSum.end())ans+=mapSum[temp];
            mapSum[temp]++;
        }
        return ans;
    }
};