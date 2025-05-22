class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int g=0;
        for(auto& word: words) {
            if(word.find(x)!=string::npos) {
                ans.push_back(g);
            }
            g++;
        }
        return ans;
    }
};