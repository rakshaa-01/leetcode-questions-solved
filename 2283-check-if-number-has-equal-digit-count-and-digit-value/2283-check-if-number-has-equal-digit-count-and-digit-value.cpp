class Solution {
public:
    bool digitCount(string num) {
        int d=0;
        for(auto& n: num) {
            int cnt = count(num.begin(), num.end(), d+'0');
            if(cnt!=(n-'0')) {
                return false;
            }
            d++;
        }
        return true;
    }
};