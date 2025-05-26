class Solution {
public:
    string largestPalindromic(string num) {
        string left="", center="";
        unordered_map<char, int> mp;
        for(auto& ch: num) {
            mp[ch]++;
        }

        for(char d='9'; d>='0'; d--) {
            if(mp[d]>=2) {
                int pairs=mp[d]/2;
                left+=string(pairs, d);
                mp[d]-=(pairs*2);
            }
        }

        for(char d='9'; d>='0'; d--) {
            if(mp[d]>0) {
                center+=d;
                break;
            }
        }

        string right=left;
        reverse(right.begin(), right.end());
        if(!left.empty() && left[0]=='0') {
            if(center.empty()) {
                return "0";
            }
            else {
                return center;
            }
        }
        return left+center+right;
    }
};