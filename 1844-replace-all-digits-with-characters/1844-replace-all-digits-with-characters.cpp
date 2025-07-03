class Solution {
public:
    string replaceDigits(string s) {
        for(int i=0; i<s.length(); i+=2) {
            char c = s[i];
            int d = s[i+1]-'0';
            char shifted = c+d;
            s[i+1]=shifted;
        }
        return s;
    }
};