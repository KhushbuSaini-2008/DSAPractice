class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int count=0;
        int maxfreq=0;
        int left=0;
        int ans=0;
        for (int i = 0; i < s.length(); i++) {
                mp[s[i]]++;
                maxfreq=max(maxfreq,mp[s[i]]);
        
while((i - left + 1) - maxfreq > k) {
    mp[s[left]]--;
    left++;
    
    
}
 count=i-left+1;
        }
ans = max(ans,count);
    return ans;
    }
};