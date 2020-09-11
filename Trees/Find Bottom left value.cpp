class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        queue<TreeNode *>qu;
        qu.push(root);
        
        while(!qu.empty())
        {
            int size=qu.size();
            ans=qu.front()->val;
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=qu.front();
                qu.pop();
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
        }
        
        
        
        return ans;
    }
};