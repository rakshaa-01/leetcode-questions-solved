class Solution {
public:
    bool satisfy(vector<int> freq, int k) {
        if(freq[0]>=k && freq[1]>=k && freq[2]>=k) return true;
        else return false;
    }
    bool isValid(string s, int k, int mid) {
        vector<int> freq(3,0);
        for(int i=0; i<mid; i++) freq[s[i]-'a']++;

        if(satisfy(freq, k)) return true;

        int n=s.length();
        int left=mid-1;
        int right=n-1;

        while(left>=0) {
            freq[s[left]-'a']--;
            freq[s[right]-'a']++;
            if(satisfy(freq, k)) return true;
            left--;
            right--;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        int low=0, high=s.length();
        int ans=INT_MAX;
        while(low<=high) {
            int mid=low+(high-low)/2;

            if(isValid(s,k,mid)) {
                ans=min(ans, mid);
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans==INT_MAX ? -1: ans;
    }
};