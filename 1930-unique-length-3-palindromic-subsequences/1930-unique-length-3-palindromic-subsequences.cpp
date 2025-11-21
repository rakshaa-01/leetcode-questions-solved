class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> first(26, -1), last(26, -1);

        int i=0;
        for(auto& ch: s) {
            if(first[ch-'a']==-1)
                first[ch-'a']=i;
            last[ch-'a']=i;
            i++;
        }

        int ans=0;
        for(int i=0; i<26; i++) {
            if(first[i]!=-1 && last[i]!=-1 && first[i]!=last[i]) {
                unordered_set<char> st;
                for(int j=first[i]+1; j<last[i]; j++)
                    st.insert(s[j]);
                ans+=st.size();
            }
        }
        return ans;
    }
};