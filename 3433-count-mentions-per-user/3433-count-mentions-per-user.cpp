class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers, 0);
        vector<int> offline(numberOfUsers, 0); //0 other than considered as offline
        for(int i=0; i<events.size(); i++) {
            string first=events[i][0];
            int second=stoi(events[i][1]);
            string third=events[i][2];
            if(first=="MESSAGE" && third!="ALL" && third!="HERE") {
                stringstream s(third);
                string word;
                while(s >> word) {
                    cout<<word.substr(2)<<endl;
                    int num = stoi(word.substr(2));
                    ans[num]++;  
                }
            }
            else if(first=="MESSAGE" && third=="ALL") {
                for(auto& c: ans) c+=1;
            }
            else if(first=="MESSAGE" && third=="HERE") {
                for(int c=0; c<offline.size(); c++) {
                    if(offline[c]==0) ans[c]+=1;
                    else {
                        if(second-offline[c]>=60) 
                            ans[c]+=1;
                    }
                }
            }
            else if(first=="OFFLINE") {
                int third=stoi(events[i][2]);
                int second=stoi(events[i][1]);
                offline[third]=second;
            }
        }
        return ans;
    }
};