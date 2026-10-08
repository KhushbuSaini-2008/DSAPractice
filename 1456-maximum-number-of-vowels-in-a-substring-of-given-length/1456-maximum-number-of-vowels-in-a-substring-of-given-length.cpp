class Solution {
public:
    int maxVowels(string s, int k) {
        int low = 0;
        int high = k - 1;
        int count = 0;
        int result = 0;

        // Count vowels in first window
        for (int i = low; i <= high; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        result = count;

        // Slide the window
        while (high + 1 < s.length()) {

            // Remove the character leaving the window
            if (s[low] == 'a' || s[low] == 'e' || s[low] == 'i' ||
                s[low] == 'o' || s[low] == 'u') {
                count--;
            }

            low++;
            high++;

            // Add the new character entering the window
            if (s[high] == 'a' || s[high] == 'e' || s[high] == 'i' ||
                s[high] == 'o' || s[high] == 'u') {
                count++;
            }

            result = max(result, count);
        }

        return result;
    }
};