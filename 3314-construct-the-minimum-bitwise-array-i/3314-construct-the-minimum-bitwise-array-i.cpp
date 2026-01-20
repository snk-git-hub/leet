class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int j = 0; j < n; j++) {
            if (nums[j] % 2 == 0) {
                ans[j] = -1;
                continue;
            }
            bool found = false;
            for (int i = 0; i < nums[j]; i++) {
                if ((i | (i + 1)) == nums[j]) {
                    ans[j] = i;
                    found = true;
                    break;
                }
            }

            if (!found) {
                ans[j] = -1;
            }
        }

        return ans;
    }
};