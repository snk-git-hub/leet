class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (auto it : nums) {
            if (mp.find(it) != mp.end()) continue;
          vector<int> divisors;
                for (int i = 1; i * i <= it; i++) {
                    if (it % i == 0) {
                        divisors.push_back(i);
                        if(i!=it/i){
                            divisors.push_back(it/i);
                        }
                    }
                }
                mp[it]=divisors;
            
        }

        int sum = 0;
        for (auto& num :nums) {
            if (mp[num].size() == 4) {
                for (auto val : mp[num]) {
                     sum+=val;
                }
            }
        }
        return sum;
    }
};