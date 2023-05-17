/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; 
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int maxLen = 0;
        dfs(root, true, 0, maxLen);
        dfs(root, false, 0, maxLen);
        return maxLen;
    }
    
private:
    void dfs(TreeNode* node, bool isLeft, int len, int& maxLen) {
        if (!node) {
            return;
        }
        
        maxLen = max(maxLen, len);
        
        if (isLeft) {
            dfs(node->left, false, len+1, maxLen);
            dfs(node->right, true, 1, maxLen);
        } else {
            dfs(node->right, true, len+1, maxLen);
            dfs(node->left, false, 1, maxLen);
        }
    }
};
