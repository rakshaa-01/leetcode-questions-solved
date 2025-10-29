class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        int m=num1.size(), n=num2.size();
        vector<int> ans(m+n+1, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int d1=num1[i]-'0';
                int d2=num2[j]-'0';
                int prod=ans[i+j]+(d1*d2);
                ans[i+j]=prod%10;
                ans[i+j+1]+=prod/10;
            }
        }
        while(ans.size()>1 && ans.back()==0) ans.pop_back();

        string res="";
        for(auto& d: ans) {
            res+='0'+d;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};