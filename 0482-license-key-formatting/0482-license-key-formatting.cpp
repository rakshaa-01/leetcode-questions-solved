class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp="";
        int g=0;
        for(int i=s.length()-1; i>=0; i--) {
            if(isalnum(s[i])) {
                temp+=toupper(s[i]);
                g++;
                if(g==k && i>0) {
                    g=0;
                    temp+="-";
                }
            }
        }
        reverse(temp.begin(), temp.end());
        if (temp[0] == '-') {
            temp = temp.substr(1);
        }
        return temp;
    }
};