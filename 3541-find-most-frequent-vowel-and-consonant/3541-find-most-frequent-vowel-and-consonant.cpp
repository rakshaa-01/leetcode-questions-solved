class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char, int> consonants;

        for(auto& ch: s) {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') {
                vowels[ch]++;
            }
            else {
                consonants[ch]++;
            }
        }
        int maxV=0, maxC=0;
        for(auto& ch: vowels) {
            maxV=max(maxV, ch.second);
        }
        for(auto& ch: consonants) {
            maxC=max(maxC, ch.second);
        }
        return maxV+maxC;
    }
};