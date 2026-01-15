class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hmax = 1, hcurr = 1;
        int vmax = 1, vcurr = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcurr++;
            } else {
                hcurr = 1;
            }
            hmax = max(hmax , hcurr);
        }

        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcurr++;
            } else {
                vcurr = 1;
            }
            vmax = max(vmax , vcurr);
        }
        int side=min(hmax,vmax)+1;
        return side*side;
    }
};