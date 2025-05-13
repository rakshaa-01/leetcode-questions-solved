class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<int> st;
        for(auto& ch: s) {
            if(st.find(ch)==st.end()) {
                st.insert(ch);
            }
            else {
                return ch;
            }
        }
        return 'a';
    }
};