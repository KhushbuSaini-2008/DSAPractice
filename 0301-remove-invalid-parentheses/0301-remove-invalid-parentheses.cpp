class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int index, int leftRem, int rightRem,
             int balance, string current) {

        if (index == s.size()) {
            if (balance == 0 && leftRem == 0 && rightRem == 0) {
                ans.push_back(current);
            }
            return;
        }

        char ch = s[index];

        // Parenthesis
        if (ch == '(') {

            // Remove '('
            if (leftRem > 0) {
                dfs(s, index + 1, leftRem - 1, rightRem,
                    balance, current);
            }

            // Keep '('
            dfs(s, index + 1, leftRem, rightRem,
                balance + 1, current + ch);
        }

        else if (ch == ')') {

            // Remove ')'
            if (rightRem > 0) {
                dfs(s, index + 1, leftRem, rightRem - 1,
                    balance, current);
            }

            // Keep ')' only if there is an '(' available
            if (balance > 0) {
                dfs(s, index + 1, leftRem, rightRem,
                    balance - 1, current + ch);
            }
        }

        else {
            // Normal character
            dfs(s, index + 1, leftRem, rightRem,
                balance, current + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum number of removals
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {
                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        dfs(s, 0, leftRem, rightRem, 0, "");

        // Remove duplicate answers
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};