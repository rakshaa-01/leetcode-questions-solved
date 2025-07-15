class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        set<vector<int>> st;
        int n=arr.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                set<long long> s;
                for(int k=j+1; k<n; k++) {
                    long long sum=arr[i]+arr[j];
                    sum+=arr[k];
                    long long more=target-sum;
                    if(s.find(more)!=s.end()) {
                        vector<int> temp={(int)arr[i], (int)arr[j], (int)arr[k], (int)more};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    s.insert(arr[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};