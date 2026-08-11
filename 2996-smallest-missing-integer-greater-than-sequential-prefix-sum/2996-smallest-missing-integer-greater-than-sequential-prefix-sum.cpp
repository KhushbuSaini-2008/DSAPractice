class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find sum of longest sequential prefix
        int sum = nums[0];

        int i = 1;
        while (i < n && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        // Find the smallest integer >= sum
        // that is not present in nums
        while (true) {
            bool found = false;

            for (int j = 0; j < n; j++) {
                if (nums[j] == sum) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return sum;
            }

            sum++;
        }
    }
};