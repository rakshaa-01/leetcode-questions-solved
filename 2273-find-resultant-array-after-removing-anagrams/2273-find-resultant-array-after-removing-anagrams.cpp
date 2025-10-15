class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1; i<words.size(); i++) {
            string f=words[i];
            string s=words[i-1];
            sort(f.begin(), f.end());
            sort(s.begin(), s.end());
            if(f==s) {
                words.erase(remove(words.begin(), words.end(), words[i]), words.end());
                i--;
            }
        }
        return words;
    }
};