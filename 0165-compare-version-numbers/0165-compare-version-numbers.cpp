class Solution {
public:
    vector<int> split(string& version) {
        vector<int> res;
        string temp;
        for(auto& ch: version) {
            if(ch=='.') {
                res.push_back(stoi(temp));
                temp="";
            }
            else {
                temp.push_back(ch);
            }
        }
        if(!temp.empty()) {
            res.push_back(stoi(temp));
        }
        return res;
    }
    void trim(vector<int>& res) {
        while(!res.empty() && res.back()==0) {
            res.pop_back();
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int> left = split(version1);
        vector<int> right = split(version2);

        trim(left);
        trim(right);


        if(left==right) return 0;
        return (left>right) ? 1: -1;
    }
};