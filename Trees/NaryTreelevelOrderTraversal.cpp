/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *>qu;
        vector<vector<int>>res;
        if(root==NULL)
        {
            return res;
        }
        qu.push(root);
        
        while(!qu.empty())
        {
            int size=qu.size();
            vector<int>getLevel;
            for(int i=0;i<size;i++)
            {
                Node *temp=qu.front();
                qu.pop();
                getLevel.push_back(temp->val);
                for(auto v:temp->children)
                {
                    qu.push(v);
                }  
            }
            res.push_back(getLevel);
        }
        
        
        return res;
        
    
        
    }
};