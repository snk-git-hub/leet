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

    struct Result {
        int depth;
        TreeNode* node;
    };

public:
    Result findMaxDepthAndParent(TreeNode* node, int CurrentDepth) {
        if (!node)
            return {CurrentDepth - 1, nullptr};

        if (!node->left && !node->right) {
            return {CurrentDepth, node};
        }
        Result leftRes = findMaxDepthAndParent(node->left, CurrentDepth + 1);

        Result rightRes = findMaxDepthAndParent(node->right, CurrentDepth + 1);

        if (leftRes.depth > rightRes.depth) {
            return leftRes;
        } else if (rightRes.depth > leftRes.depth) {
            return rightRes;
        } else {
            return {leftRes.depth, node};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return nullptr;

        Result ans = findMaxDepthAndParent(root, 0);

        return ans.node;
    }
};