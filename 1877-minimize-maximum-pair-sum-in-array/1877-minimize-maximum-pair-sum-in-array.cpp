class Solution {
private:
    void maxx(pair<int, int> p, int& ans) {
        ans = max(p.first + p.second, ans);
    }

public:
    int minPairSum(vector<int>& nums) {

        pair<int, int> p;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {

            p = {nums[i], nums[n - 1 - i]};
            maxx(p, ans);
        }
        return ans;
    }
};