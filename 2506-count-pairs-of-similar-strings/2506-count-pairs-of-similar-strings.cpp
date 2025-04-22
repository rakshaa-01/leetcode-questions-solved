class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt=0;
        vector<unordered_set<char>> vec;
        
        for(int i=0; i<words.size(); i++) {
            unordered_set<char> s(words[i].begin(), words[i].end());
            vec.push_back(s);
        }

        for(int i=0; i<vec.size()-1; i++) {
            for(int j=i+1; j<vec.size(); j++) {
                if(vec[i]==vec[j]) cnt++;
            }
        }
        return cnt;
    }
};