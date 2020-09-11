class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>qu;
        if(root==NULL)
        {
            return {};
        }
        qu.push(root);
        vector<int>res;
        
        while(!qu.empty())
        {
            int max=INT_MIN;
            int size=qu.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=qu.front();
                qu.pop();
                if(temp->val > max)
                {
                    max=temp->val;
                }
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            res.push_back(max);
        }
        
        return res;
    }
};