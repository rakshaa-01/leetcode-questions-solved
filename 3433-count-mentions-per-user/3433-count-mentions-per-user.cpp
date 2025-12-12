class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
        //     return a[1] < b[1];
        // });

        sort(events.begin(), events.end(),
    [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        int na = std::stoi(a[1]);
        int nb = std::stoi(b[1]);

        if (na != nb)
            return na < nb;                    // primary sort: numeric value

        // secondary sort when a[1] == b[1]
        if (a[0] == "OFFLINE" && b[0] != "OFFLINE")
            return true;                       // OFFLINE goes first
        if (a[0] != "OFFLINE" && b[0] == "OFFLINE")
            return false;

        return false; // equal or no special handling
    }
);

        for(auto& e: events) {
            cout<<e[0]<<"-"<<e[1]<<"-"<<e[2]<<endl;
        }

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