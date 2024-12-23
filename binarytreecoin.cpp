
class Solution {
    int result = 0;

    int distribute_(TreeNode* root) {
        if(!root) return 0;
        auto lVal = distribute_(root->left);
        auto rVal = distribute_(root->right);
        auto total = root->val + lVal + rVal;
        result += abs(total-1);
        return total -1;
    }
public:
    int distributeCoins(TreeNode* root) {
        distribute_(root);
        return result;
    }
};