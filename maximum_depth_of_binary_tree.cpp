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
    /*
    The idea here is that we get the height of the left subtree and the height of
      the right subtree and return the max of the two. If we encounter a null node
      we return a 0 (for 0 height). Then we recursively call the maxDepth func
      with the left subtree (to get the left height) and then the right subtree
      (to get the right height) and we return the max of the two. 
    */
    int maxDepth(TreeNode* root) {
        if (root ==0) return 0;

        int lh = 1+maxDepth(root->left);
        int rh = 1+maxDepth(root->right);

        return max(lh, rh);
    }
};
