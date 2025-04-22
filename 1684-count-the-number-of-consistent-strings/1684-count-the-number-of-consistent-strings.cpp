class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool flg=0;
        int cnt=0;
        for(int i=0; i<words.size(); i++) {
            flg=0;
            for(int j=0; j<words[i].length(); j++) {
                if(allowed.find(words[i][j])!=string::npos) {
                    flg=1;
                }
                else {
                    flg=0;
                    break;
                }
            }
            if(flg==1) {
                cnt++;
            }
        }
        return cnt;
    }
};