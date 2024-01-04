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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        if(root->left){
            invertTree(root->left);
        }
        if(root->right){
            invertTree(root->right);
        }

        
        //  root->left = reinterpret_cast<TreeNode*>(reinterpret_cast<uintptr_t>(root->left) ^ reinterpret_cast<uintptr_t>(root->right));
        // root->right = reinterpret_cast<TreeNode*>(reinterpret_cast<uintptr_t>(root->left) ^ reinterpret_cast<uintptr_t>(root->right));
        // root->left = reinterpret_cast<TreeNode*>(reinterpret_cast<uintptr_t>(root->left) ^ reinterpret_cast<uintptr_t>(root->right));

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        return root;
    }
};