class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       int min_abs_val=INT_MAX;
       int count_neg_val=0;
       long long total_sum=0;
       for(int i = 0;i<matrix.size();i++){
        for(int j = 0;j<matrix[i].size();++j){
            int val = matrix[i][j];
            total_sum+=abs(val);
            min_abs_val=min(min_abs_val,abs(val));;
            if(val<0) count_neg_val++;
        }
       } 
if(count_neg_val%2!=0){
    total_sum-=2*min_abs_val;
}

return total_sum;
    }
};