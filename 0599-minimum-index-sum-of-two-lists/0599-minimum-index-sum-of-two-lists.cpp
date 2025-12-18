class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp1;
        int g=0;
        for(auto& s: list1) {
            mp1[s]=g++;
        }
        for(auto& p: mp1) cout<<p.first<<"-"<<p.second<<endl;
        
        int mini=INT_MAX;
        vector<string> ans;
        for(int i=0; i<list2.size(); i++) {
            string s=list2[i];
            if(mp1.find(s)!=mp1.end()) {
                if(mp1[s]+i<mini) {
                    ans.clear();
                    ans.push_back(s);
                    mini=mp1[s]+i;
                }
                else if(mp1[s]+i==mini) {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};