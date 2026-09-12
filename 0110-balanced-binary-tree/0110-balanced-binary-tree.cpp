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
int getheight(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=getheight(root->left);
    int right=getheight(root->right);
    int ans= max(left,right)+1;
    return ans;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftheight=getheight(root->left);
        int rightheight=getheight(root->right);
        int difference=abs(leftheight-rightheight);
        if(difference>1){
            return false;
        }
        else{
            bool leftans=isBalanced(root->left);
            bool rightans=isBalanced(root->right);
            if(leftans==true && rightans== true){
                return true;
            }
            else{
                return false;
            }
        }
    }
};