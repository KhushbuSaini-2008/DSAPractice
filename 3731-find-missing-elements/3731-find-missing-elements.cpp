class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int expected = nums[0];   // Start from the smallest element

        for (int x : nums) {

            while (expected < x) {
                ans.push_back(expected);
                expected++;
            }

            expected++;   // Move to the next expected number
        }

        return ans;
    }
};