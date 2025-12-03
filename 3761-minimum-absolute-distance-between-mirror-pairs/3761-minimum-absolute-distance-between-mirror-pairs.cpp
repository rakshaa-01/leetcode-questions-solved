class Solution {
    int find(int num)
    {
        int rev=0;
        while(num) {
            int rem=num%10;
            rev=rev*10+rem;
            num=num/10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        int g=0;
        for(auto& num: nums)
        {
            if(mp.count(num))
                ans = min(ans, abs(g - mp[num]));
            int reverseNum = find(num);
            mp[reverseNum] = g++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};