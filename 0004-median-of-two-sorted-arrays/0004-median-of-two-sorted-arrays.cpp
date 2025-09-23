class Solution {
public:
void twoPointers(vector<int>& a, vector<int>& b, vector<int>& c) {
        int i=0, j=0;
        while(i<a.size() && j<b.size()) {
            if(a[i]<b[j]) {
                c.push_back(a[i]);
                i++;
            }
            else {
                c.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()) {
            c.push_back(a[i]);
            i++;
        }
        while(j<b.size()) {
            c.push_back(b[j]);
            j++;
        }
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> c;
        twoPointers(a, b, c);
        
        if(c.size()%2!=0) {
            return c[c.size()/2];
        }
        
        int mid=c.size()/2;
        return (c[mid]+c[mid-1])/2.0;
    }
};