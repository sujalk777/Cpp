// class solution{
// public:
// 	int ans=0;
// 	int pathsum(node*root,int sum ){
// 		if(root){
// 			dfs(root,sum );
// 			pathsum(root->left,sum);
// 			pathsum(root->right,sum);
// 			return ans;
// 		}
// 	}
// 	int dfs(node*root,int sum){
// 		if(root){
// 			if(root->val==sum) ans++;
// 			dfs(root->right,ans);
// 			dfs(root->left,ans);
// 		}
// 	}
// }

class Solution {
public:
    unordered_map<long, int> map;
    int count = 0;
    
    void countPathSum(TreeNode* root, int target, long sum){
        if(!root)
            return;
        sum += root->val;        //Path sum from root
        if(sum == target)
            count++;
        if(map.find(sum - target) != map.end())         //checking whether any target sum path present in the path from root to the current node
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;      //After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);
        return count;
    }
};