class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum=0;
        for(int i=0; i<s.length(); i++) {
            //Index of s = i, s[i]
            int j = t.find(s[i]);
            sum+=abs(j-i);
        }
        return sum;
    }
};