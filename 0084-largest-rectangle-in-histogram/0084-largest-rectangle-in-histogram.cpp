class Solution {
public:
    void np(vector<int>&pse,vector<int>&nse,vector<int>&heights){
        stack<int>s;
        for(int i = heights.size()-1;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()) nse[i]=heights.size();
            else nse[i]=s.top();
            s.push(i);
        }
          s = std::stack<int>();
        for(int i=0;i<heights.size();i++){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()) pse[i]=-1;
            else pse[i]=s.top();
            s.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        np(pse,nse,heights);
        int max_i=0;
        for(int i=0;i<n;i++){
          int   area= heights[i]*(nse[i]-pse[i]-1);
           max_i=max(area,max_i);
        }
        return max_i;
    }
};