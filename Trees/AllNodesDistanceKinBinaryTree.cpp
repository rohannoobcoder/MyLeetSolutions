class Solution {
        map<TreeNode *,TreeNode *> myMap;
public:
    
    void dfs(TreeNode *root){
        if(root){
            if(root->left){
                myMap[root->left]=root;
            }
            if(root->right){
                myMap[root->right]=root;
            }
            dfs(root->left);
            dfs(root->right);
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        set<TreeNode *>seen;
        queue<TreeNode *>qu;
        dfs(root);
        qu.push(target);
        seen.insert(target);
        vector<int>ans;
        int level=0;
        while(!qu.empty()){
            if(level==K){
                while(!qu.empty()){
                    ans.push_back(qu.front()->val);
                    qu.pop();
                }
                return ans;  
            }
            level++;
            int size=qu.size();
            
            for(int i=0;i<size;i++){
                TreeNode *temp=qu.front();
                qu.pop();
                if(temp->left && seen.find(temp->left)==seen.end()){
                    qu.push(temp->left);
                    seen.insert(temp->left);
                }
                if(temp->right && seen.find(temp->right)==seen.end()) {
                    qu.push(temp->right);
                    seen.insert(temp->right);
                }
                if(myMap.find(temp)!=myMap.end() && seen.find(myMap[temp])==seen.end()){
                    qu.push(myMap[temp]);
                    seen.insert(myMap[temp]);
                }
            }
        }
        
        
        return vector<int>{};
        
    }
};