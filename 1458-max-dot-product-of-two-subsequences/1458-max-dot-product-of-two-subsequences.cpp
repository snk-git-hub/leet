class Solution {
public:
    int max_dot_product(vector<int>& nums1, vector<int>& nums2, int n1,
                        int n2) {
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                int take_with_prev =
                    (dp[i - 1][j - 1] != INT_MIN)
                        ? nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1]
                        : INT_MIN;

                dp[i][j] = max({nums1[i - 1] * nums2[j - 1], take_with_prev,
                                dp[i - 1][j], dp[i][j - 1]});
            }
        }

        return dp[n1][n2];
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max_idx = max_dot_product(nums1, nums2, nums1.size(), nums2.size());
         return max_idx;
       
    }
};