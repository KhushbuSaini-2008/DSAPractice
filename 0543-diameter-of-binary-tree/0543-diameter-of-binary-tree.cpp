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
int maxDepth(TreeNode* root){
if(root==NULL){
    return 0;
}
int left=maxDepth(root->left);
int right=maxDepth(root->right);
int ans=max(left,right)+1;
return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int option1=maxDepth(root->left)+maxDepth(root->right);
        int option2=diameterOfBinaryTree(root->left);
        int option3=diameterOfBinaryTree(root->right);
        int ans=max(option1,max(option2,option3));
        
        return ans;
    }
};