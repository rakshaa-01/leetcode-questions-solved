class Solution {
public:
    vector<int> evenOddBit(int n) {
        string binary = "";
        if (n == 0) {
            binary="0";
        }

        while (n > 0) {
            binary = char((n % 2) + '0') + binary;
            n /= 2;
        }

        reverse(binary.begin(), binary.end());
        int cE=0, cO=0;
        for(int i=0; i<binary.length(); i++) {
            if(binary[i]=='1') {
                if(i%2==0) {
                cE++;
              }
                else {
                cO++;
                }
            }
        }

        vector<int> ans = {cE, cO};
        return ans;
    }
};