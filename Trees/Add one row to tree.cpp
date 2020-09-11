//DFS WAY
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
       
        if(root==NULL)
        {
            return root;
        }
        
        if(d==1)
        {
            TreeNode *n=new TreeNode(v);
            n->left=root;
            return n;
        }
        insert(v,root,1,d);
        
        return root;
    }
    
    void insert(int val,TreeNode*root,int depth,int n)
    {
        if(root==NULL) return;
        
        if(depth==n-1){
            TreeNode *temp=root->left;
            root->left=new TreeNode(val);
            root->left->left=temp;
            temp=root->right;
            root->right=new TreeNode(val);
            root->right->right=temp;
        }else
        {
            insert(val,root->left,depth+1,n);
            insert(val,root->right,depth+1,n);
        }
    }
};




//BFS WAY



class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
     
        if(root==NULL) return root;
        
        if(d==1)
        {
            TreeNode *temp=new TreeNode (v);
            temp->left=root;
            return temp;
        }
        
        queue<TreeNode *>qu;
        qu.push(root);
        
        int depth=1;
        while(depth!=d-1)
        {
            int size=qu.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=qu.front();
                qu.pop();
                if(temp->left)qu.push(temp->left);
                if(temp->right)qu.push(temp->right);
            }
            depth++;
        }
        
        while(!qu.empty())
        {
            TreeNode *node=qu.front();
            qu.pop();
            TreeNode *temp=node->left;
            node->left=new TreeNode(v);
            node->left->left=temp;
            temp=node->right;
            node->right=new TreeNode(v);
            node->right->right=temp;
        }
        
        
        return root;
        
        
    }
};