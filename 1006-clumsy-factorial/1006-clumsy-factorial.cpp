class Solution {
public:
    int clumsy(int n) {
        int result = 0;
        int fact = n;   // current group (same name you used)
        int g = 0;      // operation index: 0=*,1=/,2=+,3=-
        
        for (int i = n - 1; i >= 1; i--) {

            if (g == 0) {            // multiply
                fact *= i;
            }
            else if (g == 1) {       // divide
                fact /= i;
            }
            else if (g == 2) {       // finish group, add
                result += fact;
                fact = i;           // start new group
            }
            else if (g == 3) {       // finish group, subtract
                result += fact;
                fact = -i;          // start new NEGATIVE group
            }

            g = (g + 1) % 4;
        }

        // Add last group
        result += fact;

        return result;
    }
};
