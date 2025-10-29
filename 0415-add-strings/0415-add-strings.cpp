class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1; int j=num2.size()-1;
        string n="";
        int c=0;
        while(i>=0 || j>=0 || c) {
            long sum=c;
            if(i>=0) sum+=num1[i--]-'0';
            if(j>=0) sum+=num2[j--]-'0';
            n+=to_string(sum%10);
            c=sum/10;
        }
        reverse(n.begin(), n.end());
        return n;
    }
};