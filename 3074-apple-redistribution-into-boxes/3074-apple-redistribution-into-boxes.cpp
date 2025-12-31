class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end());
        int i=capacity.size()-1;
        int ans=0, cnt=0;
        while(i>=0) {
            if(ans+capacity[i]>=sum) {
                cnt++;
                return cnt;
            }
            else {
                ans+=capacity[i];
                cnt++;
                i--;
            }
        }
        return ans;
    }
};