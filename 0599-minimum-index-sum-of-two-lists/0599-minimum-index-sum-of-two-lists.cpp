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
        unordered_map<string, int> mp2;
        for(int i=0; i<list2.size(); i++) {
            string s=list2[i];
            if(mp1.find(s)!=mp1.end() && (mp1[s]+i)<=mini) {
                mp2[s]=mp1[s]+i;
                mini=mp1[s]+i;
            }
        }
        vector<string> ans;
        for(auto& p: mp2) {
            if(p.second==mini)
                ans.push_back(p.first);
        }
        return ans;
    }
};