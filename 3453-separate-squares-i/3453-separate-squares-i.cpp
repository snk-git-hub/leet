class Solution {
public:
    double areaBelow(double mid, vector<vector<int>>& squares){
        double area = 0;
        for(auto& sq : squares){
            double y = sq[1], len = sq[2];
            double h_below = max(0.0, min(len, mid - y));
            area += h_below * len;
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0;
        double min_y = INT_MAX;
        double max_y = INT_MIN;
        
        for(auto& sq : squares){
            double len = sq[2];
            total_area += len * len;
            min_y = min(min_y, (double)sq[1]);
            max_y = max(max_y, (double)(sq[1] + len));
        }
        
        double target = total_area / 2;
        double low = min_y, high = max_y;
        
        for(int i = 0; i < 100; i++) {
            double mid = (low + high) / 2;
            if(areaBelow(mid, squares) < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return high;
    }
};