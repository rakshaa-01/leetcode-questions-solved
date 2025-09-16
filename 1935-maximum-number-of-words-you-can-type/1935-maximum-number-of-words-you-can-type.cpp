class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int cnt=0;
        istringstream iss(text);
        string word;
        while(iss >> word) {
            bool ok=true;
            for(char ch: word) {
                if(broken.count(ch)) {
                    ok=false;
                    break;
                }
            }
            if(ok) cnt++;
        }

        
        return cnt;
    }
};