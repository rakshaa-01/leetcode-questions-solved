class Solution {
public:
    int maximumValue(vector<string>& strs) {
        vector<int> nums;
        bool num=false;
        for(auto& word: strs) {
            for(auto& ch: word) {
                if(ch>='0'&&ch<='9') {
                    num=true;
                }
                else {
                    num=false;
                    break;
                }
            }
            if(num==true) {
                int x;
                stringstream ss(word);
                ss>>x;
                nums.push_back(x);
            }
            else {
                nums.push_back(word.size());
            }
        }
        int maxi=INT_MIN;
        for(auto& ch: nums) {
            maxi=max(maxi, ch);
        }
        return maxi;
    }
};