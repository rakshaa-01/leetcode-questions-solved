class Solution {
public:
    int canConstruct(string ransomNote, unordered_map<char, int> mp_mag) {
        unordered_map<char, int> mp_ran;
        int cnt=0;
        
        for(auto& ch: ransomNote) {
            mp_ran[ch]++;
        }
        for(auto& ch: ransomNote) {
            if(mp_mag[ch]>=mp_ran[ch]) {
               cnt+=1;
            }
            else {
                return 0;
            }
        }
        return cnt;
    }
    int countCharacters(vector<string>& words, string chars) {
        int sum=0;
        unordered_map<char, int> mp_mag;
        for(auto& ch: chars) {
            mp_mag[ch]++;
        }
        for(auto& word: words) {
            sum = sum+canConstruct(word,mp_mag);
        }
        return sum;
    }
};