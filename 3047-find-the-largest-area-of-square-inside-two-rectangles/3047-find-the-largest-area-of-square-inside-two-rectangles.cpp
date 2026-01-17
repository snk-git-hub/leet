class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long maxSide = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1_i = bottomLeft[i][0], y1_i = bottomLeft[i][1];
                int x2_i = topRight[i][0], y2_i = topRight[i][1];

                int x1_j = bottomLeft[j][0], y1_j = bottomLeft[j][1];
                int x2_j = topRight[j][0], y2_j = topRight[j][1];

                int x1_overlap = max(x1_i, x1_j);
                int y1_overlap = max(y1_i, y1_j);
                int x2_overlap = min(x2_i, x2_j);
                int y2_overlap = min(y2_i, y2_j);

                if (x1_overlap < x2_overlap && y1_overlap < y2_overlap) {
                    int width = x2_overlap - x1_overlap;
                    int height = y2_overlap - y1_overlap;
                    int side = min(width, height);
                    maxSide = max(maxSide, (long long)side);
                }
            }
        }
         return maxSide * maxSide;
    }
};