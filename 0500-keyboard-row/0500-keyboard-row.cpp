class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string firstRow="qwertyuiop", secondRow="asdfghjkl", thirdRow="zxcvbnm";
        unordered_map<char, int> mp;
        for(auto& ch: firstRow) {
            mp[ch]=1;
        }
        for(auto& ch: secondRow) {
            mp[ch]=2;
        }
        for(auto& ch: thirdRow) {
            mp[ch]=3;
        }
        vector<string> ans;
        for(auto& word: words) {
            bool flag=true;
            int row = mp[tolower(word[0])]; //Find out the row number from first letter
            for(auto& w: word) {
                if(mp[tolower(w)]!=row) {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};