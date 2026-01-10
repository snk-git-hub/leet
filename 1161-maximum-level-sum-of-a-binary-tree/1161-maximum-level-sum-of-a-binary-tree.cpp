/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int maxi = INT_MIN;
        int currlevel = 1;
        int maxLevel = 1;
        while (q.empty() == false) {
            int sum = 0;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                sum += currNode->val;

                if (currNode->left != NULL) {
                    q.push(currNode->left);
                }
                if (currNode->right != NULL) {
                    q.push(currNode->right);
                }
            }
            if (sum > maxi) {
                maxi = sum;
                maxLevel = currlevel;
            }
            currlevel += 1;
        }
        return maxLevel;
    }
};