class Solution {
public:
    int largestInteger(int num) {
        vector<int> arr;
        while(num>0) {
            int rem=num%10;
            arr.push_back(rem);
            num=num/10;
        }
        reverse(arr.begin(), arr.end());

        for(int i=0; i<arr.size(); i++) {
            int poss=-1;
            int maxi=INT_MIN;
            for(int j=i+1; j<arr.size(); j++) {
                int no1=arr[i];
                int parity=no1%2;
                int p=arr[j]%2;
                if(parity==p && arr[j]>no1 && arr[j]>maxi) {
                    maxi=arr[j];
                    poss=j;
                }
            }
            if(poss!=-1) {
                swap(arr[i], arr[poss]);
            }
        }
        int res=0;
        for(auto& d: arr) {
            res=res*10+d;
        }
        return res;
    }
};