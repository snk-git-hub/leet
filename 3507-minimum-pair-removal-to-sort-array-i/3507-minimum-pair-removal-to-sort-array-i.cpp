class Solution {
public:
    bool sorted(const vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end());
    }

public:
    void mergePair(const pair<int, int>& minPair, vector<int>& nums,
                   int& count) {
        int sum = nums[minPair.first] + nums[minPair.second];
        nums[minPair.first] = sum;
        nums.erase(nums.begin() + minPair.second);
        count++;
    }

public:
    int minimumPairRemoval(vector<int>& nums) {

        int count = 0;

        while (!sorted(nums)) {
            int mini = INT_MAX;
            pair<int, int> minPair;

            for (int i = 0; i < (int)nums.size() - 1; ++i) {
                int currentSum = nums[i] + nums[i + 1];
                if (currentSum < mini) {
                    mini = currentSum;
                    minPair = {i, i + 1};
                }
            }

            mergePair(minPair, nums, count);
        }
        return count;
    }
};