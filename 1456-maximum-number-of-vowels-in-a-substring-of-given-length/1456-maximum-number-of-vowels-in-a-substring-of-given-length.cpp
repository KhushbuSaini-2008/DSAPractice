class Solution {
public:
    int maxVowels(string s, int k) {
        int low = 0;
        int high = k - 1;
        int count = 0;
        int result = INT_MIN;

       
        for (int i = low; i <= high; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        
    
        while (high  < s.length()) {

  result=max(result,count);
  
            if (s[low] == 'a' || s[low] == 'e' || s[low] == 'i' ||
                s[low] == 'o' || s[low] == 'u') {
                count--;
            }

            low++;
            high++;

        
            if (s[high] == 'a' || s[high] == 'e' || s[high] == 'i' ||
                s[high] == 'o' || s[high] == 'u') {
                count++;
            }

          
        }

        return result;
    }
};