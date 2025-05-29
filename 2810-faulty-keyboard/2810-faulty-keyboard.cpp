class Solution {
public:
    string finalString(string s) {
        string temp="";
        for(auto& ch: s) {
            if(ch=='i') {
                reverse(temp.begin(), temp.end());
            }
            else {
                temp+=ch;
            }
        }
        return temp;
    }
};