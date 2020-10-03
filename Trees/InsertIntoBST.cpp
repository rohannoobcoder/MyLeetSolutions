class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *new_node = new TreeNode(val);
            return new_node;
        }
        
        if(root->val > val){
            root->left = insertIntoBST(root->left,val);
        }else if(root->val < val){
            root->right = insertIntoBST(root->right,val);
        }
        
        
        
        return root;
        
    }
};