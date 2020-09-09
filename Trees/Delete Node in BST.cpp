class Solution {
public:
    
    TreeNode *searchMin(TreeNode *node)
    {
        TreeNode *temp=node;
        while(temp && temp->left)
        {
            temp=temp->left;
        }
        
        return temp;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        
        if(root->val==key)
        {
            if(root->left==NULL)
            {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *temp=searchMin(root->right);
                
                root->val = temp->val;
                
                root->right=deleteNode(root->right,temp->val);
                
            }
        }
        
        if(root->val < key) {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            root->left=deleteNode(root->left,key);
        }
        
        
        return root;
        
        
    }
};