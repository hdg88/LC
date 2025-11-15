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
    This solution relies on calculating the height of the left subtree
      and the height of the right subtree and then getting the difference
      between them. If the difference is more than 1, we return false. 
      At the top level if it is true, we then pass in the root's left
      child and compare it's subtrees, and we do the same for the root's
      right subtree. 

    The height function here returns 0 if the root is null. Then it 
     calculates the height of the left tree (the 1+ is for the current
     level) and the height of the right tree. The max of the left and
     right will be the height of the tree.

     See below for a more efficient solution to this question. 
    */
    bool isBalanced2(TreeNode* root) {
        if (root == NULL) return true;
        int hl = heightOfTree2(root->left);
        int hr = heightOfTree2(root->right);

        if (abs(hl-hr) >1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int heightOfTree2(TreeNode* root) {
        if (root == NULL) return 0;
        int l = 1+ heightOfTree2(root->left);
        int r = 1+ heightOfTree2(root->right);
        return max(l,r);
    }

    /*
    The issue with the implementation above is that we are calculating the 
      height for each node in the tree and comparing the heights of their 
      left and right subtrees. This results in recalculating a lot of the
      heights. This can already be improved as we are already calculating 
      the height for both subtrees (in the height function) to begin with,
      so why not check the diff as well. 
    */
    bool isBalanced(TreeNode* root) {
        if (checkHeights(root) == -1) return false;
        return true;
    }
    int checkHeights(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = checkHeights(root->left);
        if (lh == -1) return -1;
        int rh = checkHeights(root->right);
        if (rh == -1) return -1;

        if (abs(lh-rh)>1) return -1;

        return max(lh, rh) +1;
    }
};
