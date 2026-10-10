
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                // Every '(' needs two ')'
                need += 2;

                // If need is odd, insert one ')'
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }
            } else {
                need--;

                // Extra ')' without a matching '('
                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};
